#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct aluno{
    int matricula;
    int cr;
    char nome[121];
    char curso[121];    
}Aluno;

int menu(void);
void imprimir (Fila f);

int main(void){
    int opcao_menu;
    Fila p;
    p=inicializar();
    int a;
    Aluno *y;
    void *v;
    do{
        opcao_menu=menu();
        if(opcao_menu==1){
            Aluno *x;
            x=(Aluno*)malloc(sizeof(struct aluno));
            printf("digite a matricula do aluno: ");
            scanf("%d", &x->matricula);
            printf("digite o nome do aluno: ");
            scanf("%s", x->nome);
            printf("digite o curso do aluno: ");
            scanf("%s", x->curso);
            printf("digite o cr do aluno: ");
            scanf("%d", &x->cr);
            p=inserir(p, x);           
        }
        if(opcao_menu==2){
            if(vazia(p)==1){
                printf("Nao foi possivel remover elementos");
            }
            else{
                p=remover(p, &v);
                y=(Aluno*)v;
                printf("\n");
                printf("aluno removido\n");
                printf("matricula: %d\n", y->matricula);
                printf("nome: %s\n", y->nome);
                printf("curso: %s\n", y->curso);
                printf("cr: %d\n", y->cr);
            }
        }
        if(opcao_menu==3){
            imprimir(p);       
        }
        if(opcao_menu==4)
            p=destruir(p);        
    }while(opcao_menu!=4);
    printf("finalizado com sucesso\n");    
    return 0;
}

void imprimir (Fila f){
    Fila aux=inicializar();
    void *c;
    while(vazia(f)==0){
        f=remover(f, &c);
        aux=inserir(aux, c);   
    }
    while(vazia(aux)==0){
        Aluno *a;
        aux=remover(aux, &c);
        a=(Aluno*)c;
        printf("------aluno------ \n");
        printf("matricula: %d\n", a->matricula);
        printf("nome: %s\n", a->nome);
        printf("curso: %s\n", a->curso);
        printf("cr: %d\n", a->cr);
        printf("\n");
        f=inserir(f, c);       
    }    
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