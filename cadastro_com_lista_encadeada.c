#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contas
{
    char *user;
    char *senha;
    struct contas *proximo;
};

typedef struct contas Contas;

void Cadastro(char *registro_user, char *registro_senha){

    char r_user[20], r_senha1[20], r_senha2[20];

    scanf("%s", r_user);

    scanf("%s", r_senha1);

    scanf("%s", r_senha2);

    if(strcmp(r_senha1, r_senha2) == 0){
        strcpy(registro_user, r_user);
        strcpy(registro_senha, r_senha1);

        printf("Registro aprovado\n");

    } else {
        while (1) {
            scanf("%s", r_senha1);
            scanf("%s", r_senha2);
            if(strcmp(r_senha1, r_senha2) == 0){
                strcpy(registro_user, r_user);
                strcpy(registro_senha, r_senha1);
                break;
            }
        }
    }
}

void lista_Cadastro(Contas **conta, char user[20], char senha[20]){

    *conta = (Contas*) malloc(sizeof(Contas)); 
    (*conta)->user = strdup(user); 
    (*conta)->senha = strdup(senha); 
}

void Login (Contas *conta, char user[20], char senha[20]){

    scanf("%s", user);
    scanf("%s", senha);

    if(conta != NULL && strcmp(conta->user, user) == 0 && strcmp(conta->senha, senha) == 0){
        printf("Login aprovado\n");
    }
    else {
        printf("Login falhou\n");
    }
}

int main (){

    Contas *conta1 = NULL;
    char user[20], senha[20];

    Cadastro(user, senha);

    lista_Cadastro(&conta1, user, senha);

    Login(conta1, user, senha);

    return 0;
}
