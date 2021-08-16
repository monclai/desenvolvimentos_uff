#include <stdio.h>
#include <stdlib.h>
//prototipos
int menu(void);
void push(int *vet, int *pos);
int pop(int *vet, int *pos);
void imprimir(int *vet, int *pos);

int main(void){
	int opcao_menu, pos=0, control;
	int vet[10];
	do{
	opcao_menu=menu();
	if(opcao_menu==1)
		push(vet, &pos);
	if(opcao_menu==2){
		control=pop(vet, &pos);
		printf("valor removido: %d\n", control);
	}
	if(opcao_menu==3)
			imprimir(vet, &pos);
	}while(opcao_menu!=4);
	return 0;	
}

int menu(void){
	int opcao;
	printf("digite a opcao desejada\n");
	printf("1- inserir elemento\n");
	printf("2- remover elemento\n");
	printf("3- imprimir elemento\n");
	printf("4- sair\n");
	printf("opcao: ");
	scanf("%d", &opcao);	
	return opcao;	
}

void push(int *vet, int *pos){
	int num;
	printf("digite um numero: ");
	scanf("%d", &num);
	vet[*pos]=num;
	*pos=*pos+1;
}

int pop(int *vet, int *pos){
	int num;
	*pos=*pos-1;
	num=vet[*pos];
	return num;	
}

void imprimir(int *vet, int *pos){
	int i;
	for(i=0; i<*pos; i++){
		printf("%d ", vet[i]);		
	}	
}
