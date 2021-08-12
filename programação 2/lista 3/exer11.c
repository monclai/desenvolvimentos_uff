#include <stdio.h>
#include <stdlib.h>

int* aprovados(int n, int *mat, float *notas, int *tam);
int main(){
	int mat[] = {1, 2, 3};
	float notas[] = {4, 5, 8};
	int n=3, tam, *aprov, i;
	aprov = aprovados(n, mat, notas, &tam);
	for(i=0; i<tam; i++){
		printf("matricula aprovada: %d\n", aprov[i]);
	}	
}

int* aprovados(int n, int *mat, float *notas, int *tam){
	int i, aux=0, j=0;
		
	for(i=0; i<n; i++){
		if(notas[i]>= 5.0)
			aux++;		
	}	
	*tam = aux;
	int *aprov = (int*)malloc(*tam*sizeof(int));
	for(i=0; i<n; i++){
		if(notas[i]>=5.0){
			aprov[j] = mat[i];
			j++;
		}
	}
	return aprov;	
}
