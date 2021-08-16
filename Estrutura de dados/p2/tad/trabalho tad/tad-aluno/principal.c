#include <stdio.h>
#include "fila.h"

int menu(void);

int main(void){
    int opcao_menu;
    Fila p;
    p=inicializar();
    int mat, nota;
    char nome[121];
    do{
        opcao_menu=menu();
        if(opcao_menu==1){
            printf("digite a matricula do aluno: ");
            scanf("%d", &mat);
            printf("digite o nome do aluno: ");
            scanf("%s", nome);
            printf("digite a nota do aluno: ");
            scanf("%d", &nota);
            p=inserir(p, mat, nome, nota);           
        }
        if(opcao_menu==2){
            p=remover(p, &mat, nome, &nota);
            printf("aluno removido\n");
            printf("matricula: %d\n", mat);
            printf("nome: %s\n", nome);
            printf("nota: %d\n", nota);
        }
        if(opcao_menu==3)
            imprimir(p);
        if(opcao_menu==4)
            p=destruir(p);        
    }while(opcao_menu!=4);
    printf("finalizado com sucesso\n");    
    return 0;
}

int menu(void){
    int opcao;
    printf("\n\n");
    printf("-----menu-----\n");
    printf("1 - inserir novo aluno \n");
    printf("2 - remover aluno \n");
    printf("3 - imprimir fila de alunos\n");
    printf("4 - sair \n");
    printf("digite uma opcao: ");
    scanf("%d", &opcao);
    return opcao;    
}