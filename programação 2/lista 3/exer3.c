#include <stdio.h>

int max_vet (int n, float *vet);
int main(){
		float vet[] = {1, 9, 4, 5, 2}; 
		int n = 5, maior; 
		maior = max_vet (n, vet);
		printf("o maior valor e %d", maior);
}

int max_vet (int n, float *vet){
		int x, maior;
		maior = vet[0];
		for(x=0; x<n; x++){
			if (vet[x] > maior)
				maior = vet[x];
		}
		return maior;
}
