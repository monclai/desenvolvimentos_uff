#include <stdio.h>
#include <stdlib.h>
//prototipos
int menu(void);
void inserir_prior(int *vet_prior, int *pos_prior);
void inserir_comum(int *vet_com, int *pos_com);
int remover_prior(int *vet_prior, int *pos_prior);
int remover_com(int *vet_com, int *pos_com);
void imprimir(int *vet_prior, int *vet_com, int pos_prior, int pos_com);

int main(void){
	//variaves
	int opcao_menu;
	int control;
	int vet_prior[10], vet_com[10];
	int pos_prior=0, pos_com=0;	
	//corpo
	do{
	opcao_menu = menu();	
	if(opcao_menu==1){
		printf("digite 1 para prioridade e 2 para comum: ");
		scanf("%d", &control);
		if(control==1)
			inserir_prior(vet_prior, &pos_prior);
		if(control==2)
			inserir_comum(vet_com, &pos_com);		
	}	
	if(opcao_menu==2){
		if(vet_prior[0]<vet_com[0])
			control=remover_prior(vet_prior, &pos_prior);
		else
			control=remover_com(vet_com, &pos_com);
		printf("valor removido: %d\n", control);	
	}	
	if(opcao_menu==3){
		imprimir(vet_prior, vet_com, pos_prior, pos_com);
	}		
	}while(opcao_menu!=4);
}

void imprimir(int *vet_prior, int *vet_com, int pos_prior, int pos_com){
		int i;
		printf("fila prioridaria: ");
		for(i=0; i<pos_prior; i++){
			printf("%d ", vet_prior[i]);
		}
		printf("\nfila comum: ");	
		for(i=0; i<pos_com; i++){
			printf("%d ", vet_com[i]);
		}
		printf("\n");
}

int remover_prior(int *vet_prior, int *pos_prior){
	int x = vet_prior[0];
	int i;
	for(i=0; i<=*pos_prior; i++)
		vet_prior[i]=vet_prior[i+1];
	*pos_prior=*pos_prior-1;
	return x;
}

int remover_com(int *vet_com, int *pos_com){
	int x = vet_com[0];
	int i;
	for(i=0; i<=*pos_com; i++)
		vet_com[i]=vet_com[i+1];
	*pos_com=*pos_com-1;
	return x;
}

void inserir_comum(int *vet_com, int *pos_com){
	int insert;
	printf("digite o valor a ser inserido: ");
	scanf("%d", &insert);
	vet_com[*pos_com]=insert;
	*pos_com=*pos_com+1;	
}

void inserir_prior(int *vet_prior, int *pos_prior){
	int insert;
	printf("digite o valor a ser inserido: ");
	scanf("%d", &insert);
	vet_prior[*pos_prior]=insert;
	*pos_prior=*pos_prior+1;	
}

int menu(void){
	int opcao;
	printf("digite a opcao desejada\n");
	printf("1- inserir um elemento\n");
	printf("2- remover elemento\n");
	printf("3- imprimir\n");
	printf("4- sair\n");
	printf("opcao: ");
	scanf("%d", &opcao);
	return opcao;
}
