#include <stdio.h>

void quantidade(float *valores, int n);
int main(){
	float valores[]={-1.7, 3.0, 0.0, 1.5, 0.0, -1.7, 2.3, -1.7};
	int n = 8;
	quantidade(valores, n);	
}

void quantidade(float *valores, int n){
	int i, j, pos;
	float aux;
	
	//organiza o vetor
	for (i=0; i<(n-1); i++)	{
		pos=i;
		for (j=(i+1);j<n; j++) {
			if(valores[j] < valores[pos]) 
			pos=j;
		}
		if (i != pos) {
			aux=valores[i];
			valores[i]=valores[pos];
			valores[pos]=aux;
		}
	}
	
	aux=0;
	i=0;
	do{
		for(j=0; j<n; j++){
			if(valores[i]==valores[j])
				aux++;
			else
				break;
		}
		printf("%f ocorre %.1f vezes\n", valores[i], aux);
		i=i+j;
		aux=0;		
	}while(i<n);	
}
