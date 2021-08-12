#include <stdio.h>
#include <stdlib.h>

int menor_valor_unico(float *valores, int n);

int main(){
	float valores [10] = {8, 5, 2, 6, 9, 3, 1, 4, 0, 7};
	int resp, n = 10;
	resp = menor_valor_unico(valores, n);
	printf("o indice do menor valor unico e: %d\n", resp);
	printf("o menor valor unico e: %.2f", valores[resp]);	
}

int menor_valor_unico(float *valores, int n){
	int i, j, pos, aux;
	float menor;
	float *novo = (float*)malloc(n*sizeof(float));
	//copia vetor valores para o vetor novo
	for(i=0; i<n; i++){
		novo[i] = valores[i];		
	}	
	
	//organiza o vetor novo
	for (i=0; i<(n-1); i++){
		pos=i;
		for (j=(i+1);j<n; j++) {
			if(novo[j] < novo[pos]) 
			pos=j;
		}
		if (i != pos) {
			aux=novo[i];
			novo[i]=novo[pos];
			novo[pos]=aux;
		}
	}
	//menor valor unico
	if(novo[0]<novo[1])
		menor = novo[0];
	else{
		for(i=0; i<n; i++){
			if(novo[i-1]<novo[i] && novo[i]<novo[i+1]){
				menor = novo[i];
				break;				
			}
			if(i==n-1)
				menor = novo[n-1];
		}	
	}
	for(i=0; i<n; i++){
		if(menor == valores[i]){
			break;
		}
	}
	return i;	
}








