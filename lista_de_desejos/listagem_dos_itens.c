#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição das estruturas para lista de contas e senhas
typedef struct senhaNode {
    char *senha;
    struct senhaNode *prox;
} SenhaNode;

typedef struct conta {
    char *user;
    struct conta *prox;
    struct senhaNode *senhas;
} Conta;

// Função para criar uma nova conta
Conta* criarConta() {
    Conta* novaConta = (Conta*)malloc(sizeof(Conta));
    novaConta->user = NULL;
    novaConta->prox = NULL;
    novaConta->senhas = NULL;
    return novaConta;
}

// Função para criar um novo nó de senha
SenhaNode* criarSenhaNode() {
    SenhaNode* novaSenha = (SenhaNode*)malloc(sizeof(SenhaNode));
    novaSenha->senha = NULL;
    novaSenha->prox = NULL;
    return novaSenha;
}

// Função para cadastrar uma nova conta
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
            printf("Registre sua senha:\n");
            scanf("%s", senha1);
            printf("Confirme sua senha:\n");
            scanf("%s", senha2);
        } else {
            printf("Registro efetuado!\n");
            break;
        }
    }

    conta->user = malloc(strlen(usuario) + 1);
    if (conta->user == NULL) {
        printf("Erro ao alocar memória para o usuário\n");
        exit(1);
    }
    strcpy(conta->user, usuario);

    SenhaNode *novaSenha = criarSenhaNode();
    novaSenha->senha = malloc(strlen(senha1) + 1);
    if (novaSenha->senha == NULL) {
        printf("Erro ao alocar memória para a senha\n");
        exit(1);
    }
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

// Função para imprimir todas as contas e senhas
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

// Função de login
int Login(Conta *inicio, const char *usuario, const char *senha, char *usuarioLogado) {
    Conta *atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->user, usuario) == 0) {
            SenhaNode *senhaAtual = atual->senhas;
            while (senhaAtual != NULL) {
                if (strcmp(senhaAtual->senha, senha) == 0) {
                    strcpy(usuarioLogado, usuario); // Armazena o nome do usuário logado
                    return 1; // Login bem-sucedido
                }
                senhaAtual = senhaAtual->prox;
            }
        }
        atual = atual->prox;
    }
    return 0; // Falha no login
}

// Definição das estruturas para lista de jogos
typedef struct NO {
    char dado[100];
    struct NO* prox;
} NO;

typedef struct Lista {
    NO* inicio;
    NO* fim;
} Lista;

Lista L = {NULL, NULL};

// Função para inserir um elemento no início da lista
void InserirNoInicio(char* elemento) {
    NO *ptr = (NO*)malloc(sizeof(NO));
    if(ptr == NULL){
        printf("Erro de Alocação!!!\n");
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

// Função para inserir um elemento no fim da lista
void InserirNoFim(char* elemento) {
    NO *ptr = (NO*)malloc(sizeof(NO));
    if(ptr == NULL){
        printf("Erro de Alocação!!!\n");
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

// Função para imprimir todos os elementos da lista
void imprimir() {
    NO* ptr = L.inicio;
    printf("INICIO--->\n");
    while(ptr != NULL){
        printf("%s\n", ptr->dado);
        ptr = ptr->prox;
    }
    printf("<---FIM\n\n");
}

// Função para remover um elemento da lista
void remover2(Lista *l){
    NO *aux, *prev = NULL;
    aux = l->inicio;
    if(aux == NULL){
        printf("Lista vazia!!!\n");
    } else {
        char remover[100];
        printf("Informe o jogo a ser removido: ");
        scanf("%s", remover);
        while(aux != NULL){
            if(strcmp(remover, aux->dado) == 0){
                if(aux == l->inicio){
                    l->inicio = aux->prox;
                } else {
                    prev->prox = aux->prox;
                }
                free(aux);
                break;
            }
            prev = aux;
            aux = aux->prox;
        }
    }
}

// Função para exibir o menu
void menu() {
    printf("1- Para inserir no inicio da Lista\n");
    printf("2- Para inserir no fim da Lista\n");
    printf("3- Para remover item da Lista\n");
    printf("4- Para imprimir a Lista\n");
    printf("5- Para sair da conta\n");
    printf("0- Para encerrar\n");
}

// Função para salvar o usuário logado e a lista de jogos em um arquivo txt
void salvarEmArquivo(const char* usuario, int session) {
    char filename[50];
    sprintf(filename, "dados_%s_%d.txt", usuario, session);
    FILE *arquivo = fopen(filename, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    fprintf(arquivo, "Usuário logado: %s\n", usuario);
    fprintf(arquivo, "Jogos:\n");

    NO* ptr = L.inicio;
    while (ptr != NULL) {
        fprintf(arquivo, "%s\n", ptr->dado);
        ptr = ptr->prox;
    }

    fclose(arquivo);
}

int main() {
    Conta *inicio = NULL;
    Conta *atual;
    char continuar;
    char usuarioLogado[20] = {0}; // Buffer para armazenar o nome do usuário logado
    int session = 0;

    // Criação de contas e login
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

    int loggedIn = 0;
    int opcao;

    do {
        if (!loggedIn) {
            // Tentar login
            char usuario[20], senha[20];
            printf("======LOGIN======\n\nDigite seu nome de usuario:\n");
            scanf("%s", usuario);
            printf("Digite sua senha:\n");
            scanf("%s", senha);

            if (Login(inicio, usuario, senha, usuarioLogado)) {
                printf("Login bem-sucedido!\n");
                loggedIn = 1;
                session++;
            } else {
                printf("Falha no login! Usuario ou senha incorretos.\n");
                continue;
            }
        }

        // Operações na lista de jogos
        do {
            menu();
            scanf("%d", &opcao);
            char jogo[100];

            switch (opcao) {
                case 1:
                    printf("Informe o nome do jogo para inserir no inicio: ");
                    scanf("%s", jogo);
                    InserirNoInicio(jogo);
                    salvarEmArquivo(usuarioLogado, session);
                    break;
                case 2:
                    printf("Informe o nome do jogo para inserir no fim: ");
                    scanf("%s", jogo);
                    InserirNoFim(jogo);
                    salvarEmArquivo(usuarioLogado, session);
                    break;
                case 3:
                    remover2(&L);
                    salvarEmArquivo(usuarioLogado, session);
                    break;
                case 4:
                    imprimir();
                    break;
                case 5:
                    loggedIn = 0; // Sair da conta atual
                    break;
                case 0:
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
            }
        } while (opcao != 0 && loggedIn);

        // Limpar a lista de jogos ao sair da conta
        NO *noAtual = L.inicio;
        while (noAtual != NULL) {
            NO *noParaLiberar = noAtual;
            noAtual = noAtual->prox;
            free(noParaLiberar);
        }
        L.inicio = L.fim = NULL;

    } while (opcao != 0);

    // Liberação da memória alocada
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
