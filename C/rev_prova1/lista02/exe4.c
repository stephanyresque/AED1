// Crie um vetor de registros de funcionários e informe os dados via teclado. Um funcionário possui
// nome, cargo, salário-base, CPF e departamento. Em seguida, calcule e exiba o salário médio de
// todos os funcionários. No cálculo de cada salário considere os seguintes adicionais, a partir do
// salário-base, por cargo: Assistente (5%), Supervisor (10%), Gerente(15%), Outras categorias
// (2%). Obs.: salário-base contempla somente o valor registrado em carteira/tabela de
// remuneração

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct departamento{
    char nome_d[25];
    int anos_exit;
};
typedef struct funcionarios{
    char nome_f[25];
    char cargo[25];
    float salario_base;
    int cpf;
    struct departamento dp[25];

}Funcionarios;


int main(){

    int n,i;

    printf("Informe o numero de funcionarios: ");
    scanf("%d", &n);

    Funcionarios fp[n];

    for(i=0;i<n;i++){
        printf("Nome: ");
        fflush(stdin);
        fgets(fp[i].nome_f,25,stdin);
        printf("Cargo: ");
        fgets(fp[i].cargo,25,stdin);
        printf("Salario base: ");
        scanf("%f", &fp[i].salario_base);
        printf("Nome departamento: ");
        fflush(stdin);
        fgets(fp[i].dp[i].nome_d,25,stdin);
        printf("Anos de existencia: ");
        scanf("%d", &fp[i].dp[i].anos_exit);

        system("cls");
    }

    system("cls");

    for(i=0;i<n;i++){
        printf("Nome: %s", fp[i].nome_f);
        printf("Cargo: %s", fp[i].cargo);
        printf("Salario base: R$%.2f\n", fp[i].salario_base);
        if((strcmp(fp[i].cargo, "Assistente")) == 0){
            printf("Salario reajustado: R$%.2f\n", 1.05*(fp[i].salario_base));
        }else if((strcmp(fp[i].cargo, "Supervisor")) == 0){
            printf("Salario reajustado: R$%.2f\n", 1.1*(fp[i].salario_base));
        }else if((strcmp(fp[i].cargo, "Gerente")) == 0){
            printf("Salario reajustado: R$%.2f\n", 1.15*(fp[i].salario_base));
        }else{
            printf("Salario reajustado: R$%.2f\n", 1.02*(fp[i].salario_base));
        }
        printf("Nome departamento: %s", fp[i].dp[i].nome_d);
        printf("Anos de existencia: %d\n", fp[i].dp[i].anos_exit);

    }

    return 0;
}