#include <stdio.h>
#include "Pilha.h"

int menu(void);

int main(void){
	int aux, opcao_menu;
	Pilha p;
	p=inicializar();
	do{
		opcao_menu=menu();
		if(opcao_menu==1){
			printf("digite o numero a ser inserido: ");
			scanf("%d", &aux);
			p=inserir(p, aux);			
		}
		if(opcao_menu==2){
			if(vazia(p)==1)
				printf("A pilha esta vazia!\n");
			else{
			p=remover(p, &aux);
			printf("o valor removido foi: %d", aux);
			printf("\n");
			}
		}
		if(opcao_menu==3){
			imprimir(p);
		}
		if(opcao_menu==4){
			p=destruir(p);
		}
	}while(opcao_menu!=4);
	printf("execucao finalizada com sucesso!!!\n");
	return 0;	
}

int menu(void){
	int opcao;
	printf("----------menu------------\n");
	printf("1-inserir\n");
	printf("2-remover\n");
	printf("3-imprimir\n");
	printf("4-sair\n");
	printf("digite uma opcao: ");
	scanf("%d", &opcao);
	return opcao;	
}
