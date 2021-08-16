#include <stdio.h>
#include <stdlib.h>

typedef struct generico{
    char tipo;
    void *infog;    
}generico;

typedef struct lista{
    generico info;
    struct lista *prox;
}lista;

//prototipos
int menu();
lista *inserir_int(lista *l, void *x);
lista *inserir_float(lista *l, void *x);
lista *destruir (lista *l);
void imprimir(lista *l);
int contar_elementos(lista *l);
lista *remover(lista *l);

int main(void){
    int opcao_menu, aux_int;
    float aux_float;
    lista *l=NULL;
    do{
        opcao_menu=menu();
        if(opcao_menu==1){
            printf("digite o valor a ser inserido: ");
            scanf("%d", &aux_int);
            l=inserir_int(l, &aux_int);           
        }
        if(opcao_menu==2){
            printf("digite o valor a ser inserido: ");
            scanf("%f", &aux_float);
            l=inserir_float(l, &aux_float); 
        }
        if(opcao_menu==4){
            imprimir(l);           
        }
        if(opcao_menu==5){
            aux_int=contar_elementos(l);
            printf("há %d elemento(s) maiores que 10", aux_int);            
        }
        if(opcao_menu==6){
            l=destruir(l);
        }       
        
        
    }while(opcao_menu!=6);
    printf("finalizado com sucesso\n");
    return 0;   
}

lista *remover(lista *l){
    int opcao;
	printf("1-pra remover um inteiro\n");
    printf("2-para remover um real\n");
    scanf("%d", &opcao);
    if(opcao==1){
        int aux_int, *temp_int;
        printf("digite o numero a ser removido: ");
        scanf("%d", &aux_int);
        lista *t=l;
        lista *aux_ant=NULL;
        lista *aux_prox=NULL;
        while(t->prox!=NULL){
            aux_prox=t->prox;
            aux_ant=t;
            t=t->prox;
            if(t->info.tipo=='i'){
                temp_int=(int*)t->info.infog;
                if(*temp_int==aux_int)
                    break;
            }
        }
        aux_ant=aux_prox->prox;
        free(t);
        return l;	
    }
    else{
        int aux_float, *temp_float;
        printf("digite o numero a ser removido: ");
        scanf("%f", &aux_float);
        lista *t=l;
        lista *aux_ant=NULL;
        lista *aux_prox=NULL;
        while(t->prox!=NULL){
            aux_prox=t->prox;
            aux_ant=t;
            t=t->prox;
            if(t->info.tipo=='f'){
                temp_float=(float*)t->info.infog;
                if(*temp_float==aux_float)
                    break;
            }
        }
        aux_ant=aux_prox->prox;
        free(t);
        return l;
    }  
}

int contar_elementos(lista *l){
    int *i, cont=0;
    float *f;
    lista *p=l;
    printf("valores: ");
    while(p!=NULL){
        if(p->info.tipo=='i'){
            i=(int*)p->info.infog;
            if(*i>10)
                cont++;
        }
        else{
            f=(float*)p->info.infog;
            if(*f>10.0)
                cont++;          
        }
        p=p->prox;
    }
    return cont;
}

void imprimir(lista *l){
    int *i;
    float *f;
    lista *p=l;
    printf("valores: ");
    while(p!=NULL){
        if(p->info.tipo=='i'){
            i=(int*)p->info.infog;
            printf("%d ", *i);
        }
        else{
            f=(float*)p->info.infog;
            printf("%f ", *f);            
        }
        p=p->prox;
    }
    printf("\n");
}

lista *destruir (lista *l){
	while(l!=NULL){
		lista *t=l;
		l=l->prox;
		free(t);
	}
	return l;
}

lista *inserir_float(lista *l, void *x){
    lista *no;
    no=(lista*)malloc(sizeof(struct lista));
    no->info.infog=x;
    no->info.tipo='f';    
    no->prox=l;
    //l=no;
    return no;   
}

lista *inserir_int(lista *l, void *x){
    lista *no;
    no=(lista*)malloc(sizeof(struct lista));
    no->info.infog=x;
    no->info.tipo='i';    
    no->prox=l;
    //l=no;
    return no;   
}


int menu(){
    int menu;
    printf("\n\n-----menu-----\n");
    printf("1 - inserir inteiro\n");
    printf("2 - inserir float\n");
    printf("3 - remover elemento da lista\n");
    printf("4 - imprimir todos os elementos\n");
    printf("5 - contar elementos maiores que 10\n");
    printf("6 - sair\n");
    printf("digite uma opcao: ");
    scanf("%d", &menu);
    return menu;      
}