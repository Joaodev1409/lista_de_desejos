#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct conta
{
    char *user;
    char *senha;
    struct conta *prox;
};

typedef struct conta Conta;

Conta* criarConta()
{
    Conta* novaConta = (Conta*)malloc(sizeof(Conta));
    novaConta->user = NULL;
    novaConta->senha = NULL;
    novaConta->prox = NULL;
    return novaConta;
}

void Cadastro(Conta *inicio)
{
    Conta *atual = inicio;

    char usuario[20], senha1[20], senha2[20];

    printf("======REGISTRO======\n\nRegistre seu nome de usuario:\n");
    scanf("%s", usuario);
    printf("Registre sua senha:\n");
    scanf("%s", senha1);
    printf("Confirme sua senha:\n");
    scanf("%s", senha2);

    while (1)
    {
        if (strcmp(senha1, senha2) != 0)
        {
            printf("As senhas nao correspondem. Tente de novo:\n");
            scanf("%s", senha1);
            scanf("%s", senha2);
        }
        else
        {
            printf("Registro efetuado!\n");
            break;
        }
    }

    atual->user = malloc(strlen(usuario) + 1);
    strcpy(atual->user, usuario);

    atual->senha = malloc(strlen(senha1) + 1);
    strcpy(atual->senha, senha1);
}

void imprimirContas(Conta *inicio)
{
    Conta *atual = inicio;

    while (atual != NULL)
    {
        printf("Usuário: %s\nSenha: %s\n\n", atual->user, atual->senha);
        atual = atual->prox;
    }
}

int main()
{
    Conta *inicio = NULL;
    Conta *atual;

    char continuar;

    do
    {
        if (inicio == NULL)
        {
            inicio = criarConta();
            atual = inicio;
        }
        else
        {
            atual->prox = criarConta();
            atual = atual->prox;
        }

        Cadastro(atual);

        printf("Deseja adicionar outro registro? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's');

    printf("\n======= REGISTROS =======\n\n");
    imprimirContas(inicio);
    return 0;
}
