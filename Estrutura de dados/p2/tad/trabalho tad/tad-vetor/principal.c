#include <stdio.h>
#include "fila.h"

int menu(void);

int main(void){
	int aux, opcao_menu;
	Fila p;
	p=inicializar();
	do{
		opcao_menu=menu();
		if(opcao_menu==1){
			printf("digite o a valor a ser inserido: ");
			scanf("%d", &aux);
			p=inserir(p, aux);			
		}
		if(opcao_menu==2){
			p=remover(p, &aux);
			printf("o valor removido foi: %d", aux);
			printf("\n");
		}
		if(opcao_menu==3){
			imprimir(p);
		}
		if(opcao_menu==4)
		p=destruir(p);
	}while(opcao_menu!=4);
	printf("execucao finalizada com sucesso!!!\n");
	return 0;	
}

int menu(void){
	int opcao;
	printf("----------menu------------\n");
	printf("1-inserir elemento\n");
	printf("2-remover elemento\n");
	printf("3-imprimir fila\n");
	printf("4-sair\n");
	printf("digite uma opcao: ");
	scanf("%d", &opcao);
	return opcao;
}