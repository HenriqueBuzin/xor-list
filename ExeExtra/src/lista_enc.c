#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

struct listas_enc {
    no_t *cabeca;
    no_t *cauda;
    int tamanho;
};

lista_enc_t *criar_lista_enc (void) {

    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}

void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    desligar_no(elemento, NULL);

   if (lista->tamanho == 0)
   {
        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;
   }
   else {
        ligar_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}


void add_cabeca(lista_enc_t *lista, no_t* elemento){
	if (lista == NULL || elemento == NULL){
	        fprintf(stderr,"add_cabeca: ponteiros invalidos");
	        exit(EXIT_FAILURE);
	    }

	desligar_no(elemento, NULL);

	   if (lista->tamanho == 0)
	   {
	        lista->cauda = elemento;
	        lista->cabeca = elemento;
	        lista->tamanho++;
	   }
	   else {
	        ligar_nos(elemento, lista->cabeca);

	        lista->cabeca = elemento;
	        lista->tamanho++;
	   }
}

no_t *obter_cabeca(lista_enc_t *lista){
    return lista->cabeca;
}

int lista_vazia(lista_enc_t* lista){
	if(lista == NULL || lista->tamanho == 0){

		return 1;

	} return 0;

}

no_t *obter_cauda(lista_enc_t *lista){

	return lista->cauda;

}

void libera_lista(lista_enc_t *lista){

	if(lista == NULL){
		fprintf(stderr,"libera_lista: ponteiros invalidos");
		exit(EXIT_FAILURE);
	}

	while(!lista_vazia(lista)){
		remover_cabeca(lista);
	}
	free(lista);
}

void remover_cabeca(lista_enc_t *lista){

	no_t *cabeca = obter_cabeca(lista);
	if(cabeca != NULL){
		lista->cabeca = obter_proximo(cabeca, NULL);

		if(lista->cabeca != NULL){
			desligar_no(cabeca, lista->cabeca);
		}

		free(obter_dado(cabeca));
		free(cabeca);
		if(--lista->tamanho == 0){
			lista->cauda = NULL;
		}
	}
}

void remover_cauda(lista_enc_t *lista){
	no_t *cauda = lista->cauda;
	if(cauda != NULL){
		lista->cauda = obter_anterior(cauda, NULL);
		desligar_no(lista->cauda, cauda);
		free(obter_dado(cauda));
		free(cauda);
		if(--lista->tamanho == 0){
			lista->cabeca = NULL;
		}
	}
}
