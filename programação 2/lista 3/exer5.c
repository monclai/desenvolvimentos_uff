#include <stdio.h>

int ordenado(int *vet, int n);
int main(){
	int vet[] = {2,10,18,26,34}, n = 5, result;
	result = ordenado(vet, n);
	if (result == 1)
		printf("ordenado em ordem crescente");
	else if(result == -1)
		printf("ordenado em ordem decrescente");
	else
		printf("vetor desordenado");	
}

int ordenado(int *vet, int n){
	int x, maior, menor, cont =0;
	//determinar qual é o maior e o menor numero
		maior = menor = vet[0];
		for(x=0; x<n; x++){
			if (vet[x] > maior)
				maior = vet[x];
		}
		for(x=0; x<n; x++){
			if (vet[x] < menor)
				menor = vet[x];
		}
	
	/*se o menor for o primeiro numero da sequencia, os restantes são maiores
	 então é crescence, o mesmo para o decrescente*/
	 		
	//determinar se e crescente, decrescente ou desordenado
	if(menor == vet[0])
	{
		for(x=0; x<n; x++)
		{
			if(vet[x] >= menor)
			{
					menor = vet[x];
					cont++;
			}
			else
				break;
		}
		if (cont == n)
			return 1;
		else 
			return 0;
	}
	else if(maior == vet[0])
	{
		for(x=0; x<n; x++)
		{
			if(vet[x] <= maior)
			{
					maior = vet[x];
					cont++;			
			}
			else
				break;
		}
		if (cont == n)
			return -1;
		else 
			return 0;
		
	}
	else
		return 0;
}
