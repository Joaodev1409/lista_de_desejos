/*Aqui a gnt põe linka os outros arquivos.c pra quando for rodar o programa, rodar por aqui*/ 

#include "cadatro_lista_encadeada.c"
#include "listagem_dos_itens.c"

void criar_banco_txt(Conta *conta,NO *dado){
    char filename[60];
    sprintf(filename,"%s_lista de desejos.txt",conta->user);
    FILE* file=fopen(filename,"w");
    NO* lista=dado->dado;
    while(lista!=NULL){
        fprintf(file,"%s\n",lista->dado);
        lista= lista->prox;
    }
    fclose(file);
}

void adicionar_ao_banco_de_dados(Conta *conta,NO *dado){
    char filename[60];
    sprintf(filename,"%s_lista de desejos.txt",conta->user);
    FILE* file=fopen(filename,"a");
    NO* lista=dado->dado;
    while(lista!=NULL){
        fprintf(file,"%s\n",lista->dado);
        lista= lista->prox;
    }
    fclose(file);
}

int main(){
   /*Conta *inicio = NULL;
    Conta *atual;
    char continuar;
    int opcao;
    char dado[100];
    L.inicio = NULL;//sempre o inicio e o fim tem q ta inicializado em NULL
    L.fim = NULL;

    do {
        if (inicio == NULL) {
            inicio = criarConta();
            banco_txt(inicio,dado);
            atual = inicio;
        } else {
            atual->prox = criarConta();
            atual = atual->prox;
        }

        Cadastro(atual);

        printf("Deseja adicionar outro registro? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's');

    printf("\n======= REGISTROS =======\n\n");
    imprimirContas(inicio);

    Conta *contaAtual = inicio;
    while (contaAtual != NULL) {
        Conta *contaParaLiberar = contaAtual;
        contaAtual = contaAtual->prox;

        SenhaNode *senhaAtual = contaParaLiberar->senhas;
        while (senhaAtual != NULL) {
            SenhaNode *senhaParaLiberar = senhaAtual;
            senhaAtual = senhaAtual->prox;
            free(senhaParaLiberar->senha);
            free(senhaParaLiberar);
        }
        free(contaParaLiberar->user);
        free(contaParaLiberar);
    }
    
    
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
                adicionar_ao_banco_de_dados(inicio,dado);
                break;
            case 2: //inserir no fim
                printf("Informe o nome do Jogo: ");
                fgets(dado, 100, stdin);
                dado[strcspn(dado, "\n")] = 0; // Remove o '\n' do final da string
                InserirNoFim(dado);
                adicionar_ao_banco_de_dados(inicio,dado);
                break;
            case 3:
                remover2(&L);
                break;
            case 4: //imprimir
                imprimir();
                break;
        }
    } while(opcao != 0);
    */




    return 0;
}