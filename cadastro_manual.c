#include <stdio.h>
#include <string.h>

// conceito da função: registrar e armazenar dados do usuario para efetuar a verificação no Login.

// OBS.: Como a função não precisa retornar nenhum valor, 
// é usadp o "void", o que significa que a função irá 
// retorna  um valor vazio.
void Cadastro(char *r_user, char *senha1, char *senha2, char *login, char *senha_final){ // OBS.: peguntei pro chatGPT pq a função tava dando erro, e ele me disse que essa porra
                                                                                         // precisa de ponteiro, eu ainda não sei o q é direito mas aparentemente precisa pois eu
                                                                                         // estou atribuindo e modificando valores de variaveis dentro da função.

    if (strcmp(senha1, senha2) == 0) { // OBS.: "strcmp()" usado para comparar 2 strings. essa função recebe 2 parametros, são as variaveis que vão ser comparadas. Basicamente,
                                       // ela faz a pegunta: "senha1 é diferente de senha2?" se sim, ela retorna 1 (diferentes), se não, ela retorna 0 (iguais). no caso do código 
                                       // ela verifica: "Se senha1 for igual a senha2, então {...}".

        strcpy(login, r_user);         // OBS.: para a atribuir valores de outra variavel em uma string é necessário usar o "strcpy()" (da biblioteca string.h), e não o "==" como 
        strcpy(senha_final, senha2);   // no python. a função "strcpy()" recebe 2 parametros, o 1º é o ponteiro que vai receber o valor, e o 2º é o ponteiro que guarda o valor
        printf("Cadastro realizado com sucesso!\n");
        
    } else {
        while (1) {
            printf("As senhas nao correspondem, tente novamente.\n \nRegistre sua senha: \n");
            scanf("%s", senha1);
            printf("\nConfirme sua senha: \n");
            scanf("%s", senha2);

            if (strcmp(senha1, senha2) == 0) { // OBS.: no código original eu esqueci de usar o "strcmp()" e usei o "==" direto, e como são 2 strings sendo comparadas, deu erro.
                                               
                printf("\nCadastro realizado com sucesso!\n");
                strcpy(login, r_user);
                strcpy(senha_final, senha2);
                break;
            }
        }
    }
    
}

// conceito da função: ver se o user após o login é == "fulano" e o return == 1, se sim, então o acesso do "banco de dados é liberado"

int Login (char *login, char *senha, char *login_final, char *senha_final, int contador){

    if(strcmp(login, login_final) == 0 && strcmp(senha, senha_final) == 0){
        printf("Login realizado com sucesso!\n");
        return 1;

    } else {
        printf("Login ou senha incorretos, voce tem 3 tentativas para tentar logar.\n");
        while (1)
        {
            
            printf("\n[TENTATIVA NUMERO %d]\n\nInsira seu nome de usuario: \n", contador+1);
            scanf("%s", login_final);

            printf("\nInsira sua senha: \n");
            scanf("%s", senha_final);
            
            contador++;

            if(strcmp(login, login_final) == 0 && strcmp(senha, senha_final) == 0){
            printf("Login realizado com sucesso!\n");
            return 1;
            break;
        }

            if(contador==3){
                printf("Acesso negado!\nConta Bloqueada\n");
                return 0;
                break;
            }
        
        }
}
}
//teste da função "Cadastro" e "Login":

int main(){
//                               OBS.: correspondentes da função "Login" -  *login              *senha          *login_final      *senha_final
    char registro_usuario[21], registro_senha1[21], registro_senha2[21], login_usuario[21], login_senha[21], final_usuario[21], final_senha[21];
    int contador = 0;

// CADASTRO:

    printf("\nRegistre seu nome de usuario: \n");
    scanf("%s", registro_usuario);

    printf("\nRegistre sua senha: \n");
    scanf("%s", registro_senha1);

    printf("\nConfirme sua senha: \n");
    scanf("%s", registro_senha2);

    Cadastro(registro_usuario, registro_senha1, registro_senha2, login_usuario, login_senha);

// LOGIN (aparentemente tudo funcionando nessa função): 

    printf("\n[LOGIN]\n\nUsuario: \n");
    scanf("%s", final_usuario);

    printf("\nSenha: \n");
    scanf("%s", final_senha);

    Login(login_usuario, login_senha, final_usuario, final_senha, contador);

    //printf("%s\n%s",login_usuario, login_senha); // confirmação para ver se a função realmente está atribuindo os valores do register no login.

    return 0;
}

/*

---------------> código da função "Cadastro"(feito do 0 por mim😏) que foi corrigido pelo chat GPT <----------------------

int Cadastro(char r_user, char senha1, char senha2, char login, char senha_final){

    if(strcomp(senha1,senha2) == 0){
        login = r_user;
        senha_final = senha2;
        printf("Cadastro realizado com sucesso!\n");
    } else {
        while (1) {
        printf("As senha não correspondem, tente novamente: ");
        scanf("%s", senha1);
        scanf("%s", senha2);
        if(senha1 == senha2){
            printf("Cadastro realizado com sucesso!\n");
            login = r_user;
            senha_final = senha2;
            break;
        }
        }
        
    }
    return 0;
}

*/