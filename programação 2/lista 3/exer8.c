#include <stdio.h>
#include <stdlib.h>
int* uneVet(int *vet1, int *vet2, int m, int n);

int main(){
	int vet1[]={1, 3, 5};
	int vet2[]={2, 4, 6};
	int *vet3;
	int m=3, n=3, i;
	vet3 = uneVet(vet1, vet2, m, n);
	for(i=0; i<6; i++){
		printf("%d ", vet3[i]); 
	}
}

int* uneVet(int *vet1, int *vet2, int m, int n){
	int *vet3 = (int*)malloc((m+n)*sizeof(int));
	int i, j, pos, aux;
	for(i=0; i<3; i++){
		j=i+3;
		vet3[i] = vet1[i];
		vet3[j] = vet2[i];
	}	
	
	//organiza o vetor
	for (i=0; i<6; i++){
		pos=i;
		for (j=(i+1);j<6; j++) {
			if(vet3[j] < vet3[pos]) 
			pos=j;
		}
		if (i != pos) {
			aux=vet3[i];
			vet3[i]=vet3[pos];
			vet3[pos]=aux;
		}
	}
	return vet3;
}
