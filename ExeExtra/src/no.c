#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "no.h"

struct nos{
    void* dados;
    no_t *xor;
};

no_t* XOR(no_t* a, no_t* b){
	return (no_t*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

no_t *criar_no(void *dado)
{
    no_t *p = malloc(sizeof(no_t));

    if (p == NULL){
        perror("cria_no:");
        exit(EXIT_FAILURE);
    }

    p->dados = dado;
    p->xor = NULL;

    return p;
}

void ligar_nos (no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL){
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    fonte->xor = XOR(fonte->xor, destino);
    destino->xor = XOR(destino->xor, fonte);
}

void desligar_no (no_t *fonte, no_t *destino)
{
    if (fonte == NULL) {
        fprintf(stderr,"desligar_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }else if(destino == NULL){
    	fonte->xor = NULL;
    }else{
    	fonte->xor = obter_proximo(fonte, destino);
    	destino->xor = obter_proximo(destino, fonte);
    }

}

no_t *obter_proximo (no_t *no, no_t* ant)
{
    if (no == NULL) {
        fprintf(stderr,"obter_proximo: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return XOR(no->xor, ant);

}

no_t *obter_anterior (no_t *no, no_t* prox)
{
    if (no == NULL) {
        fprintf(stderr,"obter_anterior: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return XOR(no->xor, prox);
}

void *obter_dado (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->dados;
}
