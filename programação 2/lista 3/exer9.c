#include <stdio.h>
#include <stdlib.h>

int* separa (int *vet, int n);
int main(){
	int vet[]={11, 2, 31, 43, 10, 86, 27, 9}, n=8, x, *recebe;
	//vetor de saída: 2 10 86 11 31 43 27 9
	recebe = separa (vet, n);
	for(x=0; x<n; x++){
		printf("%d ", recebe[x]);
	}		
}

int* separa (int *vet, int n){
	int *novo= (int*)malloc(n*sizeof(int));
	int x, y=0;
	
	for(x=0; x<n; x++){
		if(vet[x]%2==0){
			novo[y] = vet[x];
			y++;			
		}
	}
;
	for(x=0; x<n; x++){
		if(vet[x]%2!=0){
			novo[y] = vet[x];
			y++;
		}
	}
	return novo;	
}
