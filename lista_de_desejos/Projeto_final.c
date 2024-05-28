/*Aqui a gnt põe linka os outros arquivos.c pra quando for rodar o programa, rodar por aqui*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listagem_dos_itens.c"

int main() {
    Conta *inicio = NULL;
    Conta *atual;
    char continuar;
    char usuarioLogado[20] = {0};

    do {
        if (inicio == NULL) {
            inicio = criarConta();
            atual = inicio;
        } else {
            atual->prox = criarConta();
            atual = atual->prox;
        }

        cadastrarConta(atual);

        printf("Deseja adicionar outro registro? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's');

    printf("\n============= REGISTROS =============\n\n");
    imprimirContas(inicio);

    int logado = 0;
    int opcao;

    do {
        if (!logado) {
            char usuario[20], senha[20];
            printf("============= LOGIN =============\n\nDigite seu nome de usuario:\n");
            scanf("%s", usuario);
            printf("Digite sua senha:\n");
            scanf("%s", senha);

            if (login(inicio, usuario, senha, usuarioLogado)) {
                printf("Login bem-sucedido!\n");
                logado = 1;

            } else {
                printf("Falha no login! Usuario ou senha incorretos.\n");
                continue;
            }
        }

        do {
            limparTerminal();
            imprimirLista();
            menu();
            scanf("%d", &opcao);
            char jogo[100];

            switch (opcao) {
                case 1:
                    limparTerminal();
                    printf("Informe o nome do jogo para inserir no inicio: ");
                    scanf("%s", jogo);
                    inserirNoInicio(jogo);
                    salvarEmArquivo(usuarioLogado);
                    break;
                case 2:
                    limparTerminal();
                    printf("Informe o nome do jogo para inserir no fim: ");
                    scanf("%s", jogo);
                    inserirNoFim(jogo);
                    salvarEmArquivo(usuarioLogado);
                    break;
                case 3:
                    limparTerminal();
                    removerItem(&L);
                    salvarEmArquivo(usuarioLogado);
                    break;
                case 4:
                    limparTerminal();
                    logado = 0;
                    break;
                case 0:
                    limparTerminal();
                    break;
                default:
                    limparTerminal();
                    printf("Opção inválida!\n");
                    break;
            }
        } while (opcao != 0 && logado);

        NO *noAtual = L.inicio;
        while (noAtual != NULL) {
            NO *noParaLiberar = noAtual;
            noAtual = noAtual->prox;
            free(noParaLiberar);
        }
        L.inicio = L.fim = NULL;

    } while (opcao != 0);

    Conta *contaAtual = inicio;
    while (contaAtual != NULL) {
        Conta *contaParaLiberar = contaAtual;
        contaAtual = contaAtual->prox;

        SenhaNo *senhaAtual = contaParaLiberar->senhas;
        while (senhaAtual != NULL) {
            SenhaNo *senhaParaLiberar = senhaAtual;
            senhaAtual = senhaAtual->prox;
            free(senhaParaLiberar->senha);
            free(senhaParaLiberar);
        }
        free(contaParaLiberar->usuario);
        free(contaParaLiberar);
    }

    return 0;
}