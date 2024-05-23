/*Aqui a gnt põe linka os outros arquivos.c pra quando for rodar o programa, rodar por aqui*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadatro_lista_encadeada.c"
#include "listagem_dos_itens.c"

// Função para criar banco de dados em arquivo texto
void criar_banco_txt(Conta *conta, const char *dado) {
    if (conta == NULL) {
        printf("Erro: conta é NULL\n");
        return;
    }
    if (conta->user == NULL) {
        printf("Erro: conta->user é NULL\n");
        return;
    }

    char filename[60];
    sprintf(filename, "%s_lista_de_desejos.txt", conta->user);
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Erro ao criar banco de dados do usuário\n");
        return;
    }
    fprintf(file, "%s\n", dado);
    fclose(file);
}

int main() {
    Conta *inicio = NULL;
    Conta *atual;
    char continuar;
    int opcao;
    char dado[100];

    // Inicializando lista
    L.inicio = NULL;
    L.fim = NULL;

    // Cadastro inicial de contas
    do {
        if (inicio == NULL) {
            inicio = criarConta();
            Cadastro(inicio);  // Inicializa os dados da conta
            atual = inicio;
        } else {
            atual->prox = criarConta();
            atual = atual->prox;
            Cadastro(atual);  // Inicializa os dados da nova conta
        }

        printf("Deseja adicionar outra conta? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's');

    // Exibição das contas cadastradas
    printf("\n======= REGISTROS =======\n\n");
    imprimirContas(inicio);

    // Menu de opções
    do {
        menu();
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer do teclado
        switch (opcao) {
            case 0:
                break;
            case 1:  // Inserir no início
                printf("Informe o nome do Jogo: ");
                fgets(dado, 100, stdin);
                dado[strcspn(dado, "\n")] = 0;  // Remove o '\n' do final da string
                InserirNoInicio(dado);
                criar_banco_txt(inicio, dado);
                break;
            case 2:  // Inserir no fim
                printf("Informe o nome do Jogo: ");
                fgets(dado, 100, stdin);
                dado[strcspn(dado, "\n")] = 0;  // Remove o '\n' do final da string
                InserirNoFim(dado);
                criar_banco_txt(inicio, dado);
                break;
            case 3:  // Remover item da lista
                remover2(&L);
                break;
            case 4:  // Imprimir lista
                imprimir();
                break;
        }
    } while (opcao != 0);

    // Liberação de memória
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

    return 0;
}
