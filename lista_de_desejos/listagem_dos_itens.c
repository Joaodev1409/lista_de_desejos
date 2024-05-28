#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct senhaNo {
    char *senha;
    struct senhaNo *prox;
} SenhaNo;

typedef struct conta {
    char *usuario;
    struct conta *prox;
    struct senhaNo *senhas;
} Conta;

Conta* criarConta() {
    Conta* novaConta = (Conta*)malloc(sizeof(Conta));
    novaConta->usuario = NULL;
    novaConta->prox = NULL;
    novaConta->senhas = NULL;
    return novaConta;
}

SenhaNo* criarSenhaNo() {
    SenhaNo* novaSenha = (SenhaNo*)malloc(sizeof(SenhaNo));
    novaSenha->senha = NULL;
    novaSenha->prox = NULL;
    return novaSenha;
}

void limparTerminal() {
    system("cls");
}

void cadastrarConta(Conta *conta) {
    char usuario[20], senha1[20], senha2[20];

    printf("============= REGISTRO =============\n\nRegistre seu nome de usuario:\n");
    scanf("%s", usuario);
    printf("Registre sua senha:\n");
    scanf("%s", senha1);
    printf("Confirme sua senha:\n");
    scanf("%s", senha2);

    while (1) {
        if (strcmp(senha1, senha2) != 0) {
            printf("As senhas nao correspondem. Tente de novo:\n\n");
            printf("Registre sua senha:\n");
            scanf("%s", senha1);
            printf("Confirme sua senha:\n");
            scanf("%s", senha2);
        } else {
            printf("Registro efetuado!\n");
            break;
        }
    }

    conta->usuario = malloc(strlen(usuario) + 1);
    if (conta->usuario == NULL) {
        printf("Erro ao alocar memória para o usuário\n");
        exit(1);
    }
    strcpy(conta->usuario, usuario);

    SenhaNo *novaSenha = criarSenhaNo();
    novaSenha->senha = malloc(strlen(senha1) + 1);
    if (novaSenha->senha == NULL) {
        printf("Erro ao alocar memória para a senha\n");
        exit(1);
    }
    strcpy(novaSenha->senha, senha1);

    if (conta->senhas == NULL) {
        conta->senhas = novaSenha;
    } else {
        SenhaNo *atualSenha = conta->senhas;
        while (atualSenha->prox != NULL) {
            atualSenha = atualSenha->prox;
        }
        atualSenha->prox = novaSenha;
    }

    limparTerminal();  
}

void imprimirContas(Conta *inicio) {
    Conta *atual = inicio;
    while (atual != NULL) {
        printf("Usuario: %s\n", atual->usuario);
        SenhaNo *senhaAtual = atual->senhas;
        while (senhaAtual != NULL) {
            printf("Senha: %s\n", senhaAtual->senha);
            senhaAtual = senhaAtual->prox;
        }
        printf("\n");
        atual = atual->prox;
    }
}

int login(Conta *inicio, const char *usuario, const char *senha, char *usuarioLogado) {
    Conta *atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->usuario, usuario) == 0) {
            SenhaNo *senhaAtual = atual->senhas;
            while (senhaAtual != NULL) {
                if (strcmp(senhaAtual->senha, senha) == 0) {
                    strcpy(usuarioLogado, usuario);
                    return 1;
                }
                senhaAtual = senhaAtual->prox;
            }
        }
        atual = atual->prox;
    }
    return 0;
}

typedef struct NO {
    char dado[100];
    struct NO* prox;
} NO;

typedef struct lista {
    NO* inicio;
    NO* fim;
} Lista;

Lista L = {NULL, NULL};

void inserirNoInicio(char* elemento) {
    NO *ptr = (NO*)malloc(sizeof(NO));
    if(ptr == NULL){
        printf("erro de alocacao\n");
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

void inserirNoFim(char* elemento) {
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

void imprimirLista() {
    NO* ptr = L.inicio;
    printf("Sua Wishlist: \n\n");
    while(ptr != NULL){
        printf("%s\n", ptr->dado);
        ptr = ptr->prox;
    }
}

void removerItem(Lista *l){
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

void menu() {
    printf("\n\n");
    printf("1- Para inserir no inicio da Lista\n");
    printf("2- Para inserir no fim da Lista\n");
    printf("3- Para remover item da Lista\n");
    printf("4- Para sair da conta\n");
    printf("0- Para encerrar\n");
}

void salvarEmArquivo(const char* usuario) {
    char filename[50];
    sprintf(filename, "dados_%s.txt", usuario);
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
/*
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
*/