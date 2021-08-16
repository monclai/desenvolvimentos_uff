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
lista *remover_auxint(lista *l, int *aux_int, int valor_int);
lista *remover_auxfloat(lista *l, float *aux_float, int valor_float);

int main(void){
    int opcao_menu, total_maior;
    lista *l=NULL;
    do{
        opcao_menu=menu();
        if(opcao_menu==1){
						int *point_int;
            printf("digite o valor a ser inserido: ");
            point_int=(int*)malloc(sizeof(int));
            scanf("%d", point_int);
            l=inserir_int(l, point_int);           
        }
        if(opcao_menu==2){
						float *point_float;
            printf("digite o valor a ser inserido: ");
            point_float=(float*)malloc(sizeof(float));
            scanf("%f", point_float);
            l=inserir_float(l, point_float); 
        }
        if(opcao_menu==3){
					l=remover(l);				
				}
        if(opcao_menu==4){
            imprimir(l);           
        }
        if(opcao_menu==5){
            total_maior=contar_elementos(l);
            printf("há %d elemento(s) maiores que 10", total_maior);            
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
	printf("digite uma opcao\n");
	printf("1-inteiro\n");
	printf("2-float\n");
	printf("opcao: ");
	scanf("%d", &opcao);
	if(opcao==1){
		int valor_int;
		int *aux_int;
		aux_int=(int*)malloc(sizeof(int));
		printf("digite o valor a ser removido: ");
		scanf("%d", &valor_int);
		l=remover_auxint(l, aux_int, valor_int);
		printf("valor removido %d", *aux_int);
	}
	else{
		float valor_float;
		float *aux_float;
		aux_float=(float*)malloc(sizeof(float));
		printf("digite o valor a ser removido: ");
		scanf("%f", &valor_float);
		l=remover_auxfloat(l, aux_float, valor_float);
		printf("valor removido %f", *aux_float);
	}
	return l;
}

lista *remover_auxfloat(lista *l, float *aux_float, int valor_float){
	lista *t=l;
	lista *aux_ant=NULL;
	while(t->prox!=NULL){
			aux_ant=t;
			t=t->prox;
			if(aux_ant->info.tipo=='f')
				aux_float=aux_ant->info.infog;
			if(*aux_float==valor_float)
				break;
	}
	if(aux_ant==NULL){
			if(t->info.tipo=='f')
				aux_float=t->info.infog;
			if(*aux_float==valor_float){		
				free(t);
				t=NULL;
			}
	}
	else if(aux_ant!=NULL && t->prox==NULL){
		if(t->info.tipo=='f')
			aux_float=t->info.infog;
		if(*aux_float==valor_float)
			free(t);		
	}
	else{
			aux_ant->prox=t->prox;
			free(t);
	}
	return t;
}


lista *remover_auxint(lista *l, int *aux_int, int valor_int){
	lista *t=l;
	lista *aux_ant=NULL;
	while(t->prox!=NULL){
			aux_ant=t;
			t=t->prox;
			if(aux_ant->info.tipo=='i')
				aux_int=aux_ant->info.infog;
			if(*aux_int==valor_int)
				break;
	}
	if(aux_ant==NULL){
			if(t->info.tipo=='i')
				aux_int=t->info.infog;
			if(*aux_int==valor_int){		
				free(t);
				t=NULL;
			}
	}
	else if(aux_ant!=NULL && t->prox==NULL){
		if(t->info.tipo=='i')
			aux_int=t->info.infog;
		if(*aux_int==valor_int)
			free(t);		
	}
	else{
			aux_ant->prox=t->prox;
			free(t);
	}
	return t;
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
            printf("%.2f ", *f);            
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
    return no;   
}

lista *inserir_int(lista *l, void *x){
    lista *no;
    no=(lista*)malloc(sizeof(struct lista));
    no->info.infog=x;
    no->info.tipo='i';    
    no->prox=l;
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
