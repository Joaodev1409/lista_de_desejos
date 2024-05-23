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
    printf("INICIO--->\n ");
    while(ptr != NULL){
        printf("%s \n", ptr->dado);
        ptr = ptr->prox;
    }
    printf(" <---FIM\n\n");
}


void remover2(Lista *l){
    NO *aux, *prev = NULL;
    aux = l -> inicio;
    if( aux == NULL ){
        printf(" Lista vazia !!! ");
    }else{
        char remover[100];
        printf("Informe o jogo a ser removido: ");
        scanf( "%s" , remover );
        while ( aux != NULL ){
            if( strcmp(remover , aux -> dado) == 0){
                if(aux == l -> inicio){
                    l -> inicio = aux -> prox;
                }else{
                    prev -> prox = aux -> prox;
                }
                free(aux);
                break;
            }
            prev = aux;
            aux = aux -> prox;
        }
    }
}


void menu() {
    printf("1- Para inserir no inicio da Lista\n");
    printf("2- Para inserir no fim da Lista\n");
    printf("3- Para remover item da Lista\n");
    printf("4- Para imprimir a Lista\n");
    printf("0- Para encerrar\n");
}

/*int main() {
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
            case 3:
                remover2(&L);
                break;
            case 4: //imprimir
                imprimir();
                break;
        }
    } while(opcao != 0);
    
    return 0;
}
*/