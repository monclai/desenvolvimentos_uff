#include <stdio.h>
#include <stdlib.h>

typedef struct generico{
	char tipo;
	void *info;	
}generico;

void inserir(generico *vet, int pos);
int soma_inteiros(generico *vet);

int main(void){
	generico vet[10];
	int i, x;
	for(i=0; i<10; i++){
		vet[i].info=NULL;		
	}
	inserir(vet, 0);
	inserir(vet, 3);
	inserir(vet, 9);
	x=soma_inteiros(vet);
	printf("a soma dos inteiros foi: %d", x);
	return 0;	
}

void inserir(generico *vet, int pos){
	int op;
	printf("\n 1-int \n 2-float\n");
	printf("opção: ");
	scanf("%d", &op);
	printf("numero: ");
	if(op==1){
		int *a;
		a=(int*)malloc(sizeof(int));
		scanf("%d", a);
		vet[pos].tipo='i';
		vet[pos].info=a;		
	}
	else{
		float *b;
		b=(float*)malloc(sizeof(float));
		scanf("%f", b);
		vet[pos].tipo='f';
		vet[pos].info=b;	
	}
}

int soma_inteiros(generico *vet){
		int i, ret=0;
		for(i=0; i<10; i++){
			if(vet[i].info!=NULL){
				if(vet[i].tipo=='i'){
					int *w;
					w=(int*)vet[i].info;
					ret=ret+(*w);				
				}				
			}
		}
		return ret;	
}



