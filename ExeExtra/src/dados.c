#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "lista_enc.h"

struct dados {
    int amostra;
    float temperatura;
    char tempo[64];
};

dado_t * criar_dado (int amostra, float temperatura, char * timestamp){

    dado_t * dado = malloc(sizeof(struct dados));

    dado->amostra = amostra;
    dado->temperatura = temperatura;
    strcpy(dado->tempo, timestamp);

    return dado;
}

lista_enc_t *ler_dados_csv(char *nome_do_arquivo){

	char texto[64];
	int amostra;
	float temperatura;

    lista_enc_t *lista;
    dado_t *dado;
    no_t *meu_no;

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    lista = criar_lista_enc();

    fgets(texto,64, fp);

    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, texto) == 3){
        printf("Lido %d, %f, %s\n", amostra, temperatura, texto);


        dado = criar_dado(amostra, temperatura, texto);

        meu_no = criar_no(dado);


        add_cauda(lista, meu_no);


    }

    fclose(fp);

    return lista;
}

void exibir_dados(lista_enc_t * lista){

	no_t *anterior, *atual, *proximo;
	anterior = NULL;
	atual = obter_cabeca(lista);

	while(atual != NULL){
		proximo = obter_proximo(atual, anterior);
		dado_t *dado = obter_dado(atual);
		printf("%d %f %s \n", dado->amostra, dado->temperatura, dado->tempo);

		anterior = atual;

		atual = proximo;

	}

}

void liberar_dados(lista_enc_t *lista){
	libera_lista(lista);
}
