#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Jogo{
    char nome_do_jogo[51];
    int codigo;
    int preco;
}JOGO;

typedef struct NO{
    int dado;
    struct NO* proximo;
    struct NO* anterior;
}NO;

void InserirElemento(struct JOGO *elemento){
    NO *ptr= (NO*)malloc(sizeof(NO));
    ptr->anterior=NULL;
    ptr->proximo=NULL;
    ptr->dado=elemento;
    
}


void removerelemento(){
    int op;
    printf("1 ---REMOVER NO INICIO\n");
    printf("2 ---REMOVER NO FINAL\n");
    printf("3 ---REMOVER ELEMENTO INDICADO\n");
    printf("0 ---NÃO REMOVER\n");
    scanf("%d",&op);

}