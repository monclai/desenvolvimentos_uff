#include <stdio.h>
#include <stdlib.h>

float* vet2(int n, float *vet1);
int main(){
	float vet1[] = {1.2, 1.2, 0.9, 1.5, 1.4, 1,5};
	// 1.2 1.2 1.4 1.5
	int n=6, i;
	float *resp = vet2(n, vet1);
	for(i=0; i<(n-2); i++){
		printf("%f ", resp[i]);
	}	
}

float* vet2(int n, float *vet1){
	int x; 
	float maior, menor;
	//determinar qual é o maior e o menor numero
		maior = menor = vet1[0];
		for(x=0; x<n; x++){
			if (vet1[x] > maior)
				maior = vet1[x];
		}
		for(x=0; x<n; x++){
			if (vet1[x] < menor)
				menor = vet1[x];
		}
	
	float *resp = (float*)malloc((n-2)*sizeof(float));
	
	int nme=0, nma=0, j=0;
	for(x=0; x<(n-2); x++){
		if(vet1[j]==menor && nme==0){
			resp[x]=vet1[j];
			nme++;
			j++;
		}
		else if(vet1[j]==menor && nma==0){
			resp[x]=vet1[j];
			nma++;
			j++;
		}
		else{
			resp[x]=vet1[j];
			j++;
		}
	}	
	return resp;
}
