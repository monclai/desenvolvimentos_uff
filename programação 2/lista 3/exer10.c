#include <stdio.h>
#include <stdlib.h>

float* acima_da_media(int n, float *vet, int *tam);
int main(){
		float vet[] = {5.5, 3.2, 2.5, 9.4, 7.5, 4.1, 5.4, 8.0, 6.9};
		float *maior;
		int n=9, tam, i;
		maior = acima_da_media(n, vet, &tam);
		for(i=0; i<tam; i++){
			printf("%.2f ", maior[i]);			
		}
}

float* acima_da_media(int n, float *vet, int *tam){
		int i, j=0, aux=0;
		float soma, media;
		
		for(i=0; i<n; i++){
			soma += vet[i];			
		}		
		media = soma/n;
		
		for(i=0; i<n; i++){
		if (vet[i] > media)
			aux++;
		}
		*tam = aux;
				
		float *maior = (float*)malloc(*tam*sizeof(float));
		
		for(i=0; i<n; i++){
			if(vet[i] > media){
				maior[j] = vet[i];
				j++;
			}
		}
		return maior;
}
