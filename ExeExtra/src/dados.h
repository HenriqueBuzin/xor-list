#ifndef DADO_H_INCLUDED

#include "lista_enc.h"

typedef struct dados dado_t;

dado_t * criar_dado (int amostra, float temperatura, char * timestamp);

void liberar_dados(lista_enc_t *lista);

lista_enc_t *ler_dados_csv(char *nome_do_arquivo);

void exibir_dados(lista_enc_t * lista);

#endif
