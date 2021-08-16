#include <stdio.h>
#include <stdlib.h>

void imprimir(int *vet, int n){
	int i;
	for (i=0; i<n; i++){
		printf("%d ", vet[i]);
	}
}

void inserir(int *vet, int *n, int x){
		vet[*n]=x;
		*n=*n+1;	
}

int remover(int *vet, int *n){
		int x=vet[0];
		int i;
		for(i=0; i=*n-1; i++)
			vet[i]=vet[i+1]
		*n=*n-1;
		return x;
}

int main(void){
		int vet[10];
		int n=0;
		int x;	
		
		inserir(vet, &n, 10);
		inserir(vet, &n, 20);
		inserir(vet, &n, 30);
		
		x=remover(vet, &n);
		printf("%d ", x);
		x=remover(vet, &n);
		printf("%d ", x);
		return 0;		
}
