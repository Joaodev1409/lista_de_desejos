#include <stdio.h>
#include <string.h>

// conceito da função: registrar e armazenar dados do usuario para efetuar a verificação no Login.

// OBS.: Como a função não precisa retornar nenhum valor, 
// é usadp o "void", o que significa que a função irá 
// retorna  um valor vazio.
void Cadastro(char *r_user, char *senha1, char *senha2, char *login, char *senha_final){ // OBS.: peguntei pro chatGPT pq a função tava dando erro, e ele me disse que essa porra
                                                                                         // precisa de ponteiro, eu ainda não sei o q é direito mas aparentemente precisa pois eu
    printf("\nRegistre seu nome de usuario: \n");                                        // estou atribuindo e modificando valores de variaveis dentro da função.
    scanf("%s", r_user);

    printf("\nRegistre sua senha: \n");
    scanf("%s", senha1);

    printf("\nConfirme sua senha: \n");
    scanf("%s", senha2);
                                                                                    
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

//  IDEIA ABSTRATA USANDO A FUNÇÃO "Cadastro(...)"":        (31/3/23)
//  pretendo usar essa função para de alguma forma pegar nome de usuario registrado e transformar em uma espécie ID para pegar os jogos escolhido por ele e armazenar em um  
// "banco de dados" de forma individual, como a função "Cadastro(...)" só retorna o user e senha quando o registro é bem sucedido, dá pra usar o user registrado como uma "chave" para
//  acessar uma "celula(?)" específica do "banco de dados". (A ideia de como a gente vai armazenar os jogos e suas informações ainda está sendo discutida, estamos pensando em fazer
//  um banco de dados fictício para a execução do programa usando SQL, mas caso não dê certo vamos usar um array de caracteres e fazer um "banco de dados" dentro do próprio programa,)

// conceito da função: ver se o user após o login é == "fulano" e o return == 1, se sim, então o acesso do "banco de dados é liberado"

int Login (char *login, char *senha, char *login_final, char *senha_final, int contador){// esse contador tem q ser uma variavel dentro da função, não? 27/04

    printf("\n[LOGIN]\n\nUsuario: \n");
    scanf("%s", login_final);

    printf("\nSenha: \n");
    scanf("%s", senha_final);

    if(strcmp(login, login_final) == 0 && strcmp(senha, senha_final) == 0){
        printf("Login realizado com sucesso!\n");
        return 1;

    } else {//esse while tinha q ta fora desse else,não? pq o else deveria retornar 0 e enquanto for 0 vai pedindo a senha e login dnv 3 vezes
        printf("Login ou senha incorretos, restam 2 tentativas de login .\n");
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

// IDEIA ABSTRATA USANDO A FUNÇÃO "Login(...)"":         (31/3/23)
// ja com essa função sera mais simples (eu acho), vou usar o retorno dela para acessar o "banco de dados", na função ela retorna um Int, return 1 se o login for sucedido, e 
// return 0 se a conta for bloqueada, estou pensando em usar um loop para fazer o acesso das funções manualmente, e implementar outra opção, a "[SAIR]" para quebrar o loop e
// encerrar o programa, a ideia ainda está meio abstrata mas pretento estudar um pouco sobre funções de OS para limpar o terminal, adicionar timers nas ações e fazer o programa
// ficar menos "cru" e aparentemente funcional, não tenho a certeza se vamos fazer um front-end de fato, mas enquanto não tenho a resposta, é melhor eu prevendo e previnir futuros
// atrasos.


//teste da função "Cadastro" e "Login":

// modificação 01/04/24: O input dos dados vai ser dentro da função para deixar o código principal mais limpo, aparentemente continua tudo funcionando, nada significativo,
// ficou um pouco menos fácil de entender mas nada de mais, até porque é uma logica extremamente simples

int main(){
//                               OBS.: correspondentes da função "Login" -  *login              *senha          *login_final      *senha_final
    char registro_usuario[21], registro_senha1[21], registro_senha2[21], login_usuario[21], login_senha[21], final_usuario[21], final_senha[21];
    int contador = 0, opcao;


while(1){
    printf("--------------->BEM-VINDO!!!<---------------");
    printf("[1] - REGISTRAR\n");
    printf("[2] - LOGIN\n");
    
    printf("[0] - ENCERRAR PROGRAMA\n");
    
    scanf("%d", &opcao);

    if(opcao == 1){
        Cadastro(registro_usuario, registro_senha1, registro_senha2, login_usuario, login_senha);
        contador++;
        }

    if (opcao == 2){
        if(contador > 0){
            Login(login_usuario, login_senha, final_usuario, final_senha, contador);
        } else {
            printf("Nenhum usuario cadastrado. Voltando para tela inical.\n");
        }
        }

    if(opcao == 0){
        printf("Encerrando programa...\n");
        printf("--------------->   CREDITOS   <---------------");
        printf("--------------> ARTHUR NICOLAS <--------------");
        printf("-------------->  JOÃO VICTOR  <---------------");
        break;
    }


    }
    return 0;
}

/*

---------------> código da função "Cadastro"(feita do 0 por mim😏) que foi corrigido pelo chat GPT <----------------------

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