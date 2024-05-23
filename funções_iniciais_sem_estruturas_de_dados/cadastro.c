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

void libera_cliente(cliente *cliente) {
    free(cliente->nome); // Libera o nome do cliente
    free(cliente); // Libera o nó do cliente
}

void libera_lista(cliente *lista) {/*função que percorre toda a lista e libera cada cliente*/
    cliente *atual = lista;
    while (atual != NULL) {
        cliente *proximo = atual->proximo;
        libera_cliente(atual);
        atual = proximo;
    }
}


int main() {
    cliente *lista = NULL;
    lista = insere_cliente(lista, "Alice",3245 );
    lista = insere_cliente(lista, "Bob", 1254);
    lista = insere_cliente(lista, "Carol", 3451);

    exibe_clientes(lista);
    libera_lista(lista);

    return 0;
}
*
/*Adicionar "#include 'cadastro.c'" no codigo principal*/