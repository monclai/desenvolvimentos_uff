#include <stdio.h>

int teste_PA(int *v, int n);
int main(){
		int v[] = {2,10,18,26,34}, n = 5, result;
		result = teste_PA(v, n);
		if (result ==  0)
			printf("nao e uma p.a.");
		else 
			printf("e uma p.a. de razao %d", result);	
}

int teste_PA(int *v, int n){
	int k, x, cont=0;
	k = v[1] - v[0];
	for(x=0; x<n; x++){
		if(v[x] == v[0] + (x*k))
			cont+=1;		
	}
	if (cont == n)
		return k;
	else 
		return 0;
}
