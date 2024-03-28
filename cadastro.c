#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente/* Definição da estrutura para os dados do cliente*/
{
    char *nome;
    int senha;
    struct cliente *proximo;
    
}cliente;

cliente *criar_cliente(char *nome,int senha){/*Função para criar um novo cadastro*/
    cliente *novo = (cliente *)malloc(sizeof(cliente));
    novo->nome = strdup(nome);
    novo->senha = senha;
    novo->proximo = NULL;
    return novo;
}

cliente *insere_cliente(cliente *lista, char *nome, int senha) {/*Função para inserir o cliente na lista*/
    cliente *novo = cria_cliente(nome, senha);
    novo->proximo = lista;
    return novo;
}

void exibe_clientes(cliente *lista) {/*Função para exibir todos os clientes*/
    for (cliente *cliente = lista; cliente != NULL; cliente = cliente->proximo) {
        printf("Nome: %s", cliente->nome);
    }
}

/*Adicionar "#include 'cadastro.c'" no codigo principal*/