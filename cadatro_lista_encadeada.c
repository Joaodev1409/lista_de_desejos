#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct senhaNode {
    char *senha;
    struct senhaNode *prox;
};

struct conta {
    char *user;
    struct conta *prox;
    struct senhaNode *senhas;
};

typedef struct conta Conta;
typedef struct senhaNode SenhaNode;

Conta* criarConta() {
    Conta* novaConta = (Conta*)malloc(sizeof(Conta));
    novaConta->user = NULL;
    novaConta->prox = NULL;
    novaConta->senhas = NULL;
    return novaConta;
}

SenhaNode* criarSenhaNode() {
    SenhaNode* novaSenha = (SenhaNode*)malloc(sizeof(SenhaNode));
    novaSenha->senha = NULL;
    novaSenha->prox = NULL;
    return novaSenha;
}

void Cadastro(Conta *conta) {
    char usuario[20], senha1[20], senha2[20];

    printf("======REGISTRO======\n\nRegistre seu nome de usuario:\n");
    scanf("%s", usuario);
    printf("Registre sua senha:\n");
    scanf("%s", senha1);
    printf("Confirme sua senha:\n");
    scanf("%s", senha2);

    while (1) {
        if (strcmp(senha1, senha2) != 0) {
            printf("As senhas nao correspondem. Tente de novo:\n");
            scanf("%s", senha1);
            scanf("%s", senha2);
        } else {
            printf("Registro efetuado!\n");
            break;
        }
    }

    conta->user = malloc(strlen(usuario) + 1);
    strcpy(conta->user, usuario);

    SenhaNode *novaSenha = criarSenhaNode();
    novaSenha->senha = malloc(strlen(senha1) + 1);
    strcpy(novaSenha->senha, senha1);

    if (conta->senhas == NULL) {
        conta->senhas = novaSenha;
    } else {
        SenhaNode *atualSenha = conta->senhas;
        while (atualSenha->prox != NULL) {
            atualSenha = atualSenha->prox;
        }
        atualSenha->prox = novaSenha;
    }
}

void imprimirContas(Conta *inicio) {
    Conta *atual = inicio;
    while (atual != NULL) {
        printf("Usuário: %s\n", atual->user);
        SenhaNode *senhaAtual = atual->senhas;
        while (senhaAtual != NULL) {
            printf("Senha: %s\n", senhaAtual->senha);
            senhaAtual = senhaAtual->prox;
        }
        printf("\n");
        atual = atual->prox;
    }
}

/*int main() {
    Conta *inicio = NULL;
    Conta *atual;
    char continuar;

    do {
        if (inicio == NULL) {
            inicio = criarConta();
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

    return 0;
}
*/