#include <stdio.h>
#include <stdlib.h>
//protótipos
void inserir_comum(int *vet_com, int *pos_com, int x);

int main(void){
	int vet[10];
	int n=0;
	int x;
	do{
		opcao_menu = menu();
		
		if(opcao_menu==1)
			printf("digite o valor");
			scanf("%d", x);
			printf("digite 1 para prioridade");
			printf("digite 2 para comum");
			scanf("%d", &opcao_fila);
			if(opcao_fila==1)
			inserir_prior(vet, &pos);
			if(opcao_fila==2)
			inserir_comum(vet, &pos);
		
		if(opcao_menu==2)
		if(vet_com<vet_prior)
			valor=remove_com(vet, &pos);
			printf("valor removido: %d", valor);
		
		if(opcao_menu==3)
			imprimir(vet, pos);		
	}while(opcao_menu!=4);	
}

void inserir_comum(int *vet_com, int *pos_com, int x){
		vet[*n]=x;
		*pos_com=*pos_com+1;	
}

int menu(void){
		int opcao;
		printf("digite a opcao desejada\n");
		printf("1- inserir um elemento\n");
		printf("2- remover elemento\n");
		printf("3- imprimir\n");
		printf("4- sair\n");
		scanf("%d ", &opcao);
		return opcao;
}
