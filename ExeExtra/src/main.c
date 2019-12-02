#include <stdio.h>
#include "dados.h"
#include "lista_enc.h"


int main(){
    lista_enc_t *lista = ler_dados_csv("camera_temp.csv");

    exibir_dados(lista);

   liberar_dados(lista);

    return 0;
}
