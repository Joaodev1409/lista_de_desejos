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

void Cadastro(Conta *contaPtr)
{
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
            scanf("%s", senha2);
        }
        else
        {
            printf("Registro efetuado!\n");
            break;
        }
    }

    contaPtr->user = malloc(strlen(usuario) + 1);
    strcpy(contaPtr->user, usuario);

    contaPtr->senha = malloc(strlen(senha1) + 1);
    strcpy(contaPtr->senha, senha1);
}

int main()
{
    Conta *conta1 = malloc(sizeof(Conta)); 

    Cadastro(conta1);
    printf("%s\n%s", conta1->user, conta1->senha);

    return 0;
}
