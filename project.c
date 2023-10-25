#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct list {

    char nome[100], email[50], endereco[70], sex[13], tel[17];
    int idade, senha, dependente, num_casa;
    float altura;
};

int main() {
    
    struct list cadastro;

    do {
    system("cls");
    printf("Digite o seu nome: ");
    scanf(" %s", cadastro.nome);
    } while(strlen(cadastro.nome) <= 1);

    do {
    system("cls");
    printf("Digite o seu E-mail: ");
    scanf(" %s", cadastro.email);
    } while(strlen(cadastro.email) <= 10);

    int senha, senha_confirm;
    system("cls");
    printf("Digite sua senha(sao permito apenas numeros): ");
    scanf(" %d", &senha);

    do{
        system("cls");
        printf("Confirme sua senha: ");
        scanf(" %d", &senha_confirm);
    } while (senha != senha_confirm);

    cadastro.senha = senha;
    printf(" %d", cadastro.senha);

    do {
    system("cls");
    printf("Digite o seu endereço: ");
    scanf(" %s", cadastro.endereco);
    } while(strlen(cadastro.endereco) <= 10);

    system("cls");
    printf("Digite o numero da casa: ");
    scanf(" %d", &cadastro.num_casa);

    time_t data_atual;
    struct tm *tempo;

    time(&data_atual);

    tempo = localtime(&data_atual);

    int year = tempo->tm_year + 1900;
    printf(" %d",year);

    int ano_nascimento;

    do{
        system("cls");
        printf("digite seu ano de nascimento(precisa conter 4 digitos): ");
        scanf(" %d", &ano_nascimento);
    }while(ano_nascimento < 1000 || ano_nascimento > 9999);

    cadastro.idade = year - ano_nascimento;

    int pergunta_dep;
    
    do {
    system("cls");
    printf("Possui filhos:\n[1] Sim\n[2] Nao\n");
    scanf(" %d", &pergunta_dep);
    } while(pergunta_dep != 1 && pergunta_dep != 2);

    if(pergunta_dep == 1) {
         int quant;
        do {
            system("cls");
            printf("Quantos Filhos possui: ");
            scanf(" %d", &quant);
        } while(quant == 0);
        cadastro.dependente = quant;
    } else {
        cadastro.dependente = 0;
    }

    int per_sex;
    do{
        system("cls");
        printf("Digite o seu Sexo:\n[1] Masculino\n[2] Feminino\n[3] Outros:\n");
        scanf(" %d", &per_sex);
    } while(per_sex > 3);

    switch(per_sex) {
        case 1:
            strcpy(cadastro.sex,"Masculino");
            break;
        case 2:
            strcpy(cadastro.sex,"Feminino");
            break;
        case 3:
            strcpy(cadastro.sex,"Outros");
            break;
    }

    do {
        system("cls");
        printf("digite seu telefone: ");
        scanf(" %s", cadastro.tel);
    } while(strlen(cadastro.tel) <= 10);


    system("cls");
    printf("digite o sua altura: ");
    scanf("%f",&cadastro.altura);

    system("cls");

    printf("\nNome: %s\n",cadastro.nome);
    printf("Email: %s\n",cadastro.email);
    printf("Endereco: %s, N %d\n",cadastro.endereco,cadastro.num_casa);
    printf("Sexo: %s\n",cadastro.sex);
    printf("idade: %d\n",cadastro.idade);
    printf("Depedente: %d\n",cadastro.dependente);
    printf("Telefone: %s\n",cadastro.tel);
    printf("Altura: %f\n",cadastro.altura);

    printf("\nCADASTRADO CONCLUIDO!\n");

    return 0;
}