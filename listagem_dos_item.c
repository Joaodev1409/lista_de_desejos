#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO {
    char dado[100];
    struct NO* prox;
} NO;

typedef struct Lista {
    NO* inicio;
    NO* fim;
} Lista;

Lista L;

void InserirNoInicio(char* elemento) {
    NO *ptr = (NO*)malloc(sizeof(NO));
    if(ptr == NULL){
        printf("Erro de Alocação!!!.\n");
        exit(0);
    } else {
        strcpy(ptr->dado, elemento);
        ptr->prox = NULL;
        
        if(L.inicio == NULL){
            L.fim = ptr;
        } else {
            ptr->prox = L.inicio;
        }
        L.inicio = ptr;
    }
}

void InserirNoFim(char* elemento) {
    NO *ptr = (NO*)malloc(sizeof(NO));
    if(ptr == NULL){
        printf("Erro de Alocação!!!.\n");
        exit(0);
    } else {
        strcpy(ptr->dado, elemento);
        ptr->prox = NULL;

        if(L.inicio == NULL){
            L.inicio = ptr;
        } else {
            L.fim->prox = ptr;
        }
        L.fim = ptr;
    }
}

void imprimir() {
    NO* ptr = L.inicio;
    printf("INICIO---> ");
    while(ptr != NULL){
        printf("%s ", ptr->dado);
        ptr = ptr->prox;
    }
    printf(" <---FIM\n\n");
}

NO* remover(NO **Lista,char elemento){//ainda não atualizei lá no main
    NO *aux,*remover=NULL;
    if(*Lista){//se o valor dentro do if é equivalente a ta comparando se é = NULL
        if((*Lista)->dado== elemento){//aq tbm verifica se o dado é NULL
            remover= *Lista;
            *Lista=remover->prox;
        }else{
            aux=*Lista;
            while(aux->prox && aux->prox->dado!=elemento){//aq tmb é se é NULL
                aux= aux->prox;
            }
            if(aux->prox){
                remover=aux->prox;
                aux->prox=remover->prox;
            }
        }
    }   
    return remover;
}

void menu() {
    printf("1- Para inserir no inicio da Lista\n");
    printf("2- Para inserir no fim da Lista\n");
    printf("3- Para imprimir a Lista\n");
    printf("0- Para encerrar\n");
}

int main() {
    int opcao;
    char dado[100];
    L.inicio = NULL;//sempre o inicio e o fim tem q ta inicializado em NULL
    L.fim = NULL;
    
    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // é pra limpar o buffer do teclado , tem muita utilidade n mas é legal pra ficar bunitin
        switch (opcao) {
            case 0:
                break;
            case 1: //inserir no inicio
                printf("Informe o nome do Jogo: ");
                fgets(dado, 100, stdin);
                dado[strcspn(dado, "\n")] = 0; // Remove o '\n' do final da string
                InserirNoInicio(dado);
                break;
            case 2: //inserir no fim
                printf("Informe o nome do Jogo: ");
                fgets(dado, 100, stdin);
                dado[strcspn(dado, "\n")] = 0; // Remove o '\n' do final da string
                InserirNoFim(dado);
                break;
            case 3: //imprimir
                imprimir();
                break;
        }
    } while(opcao != 0);
    
    return 0;
}
