#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int destino;
  int custo;
  struct lista *prox;
}lista;

//prototipos
int menu();
lista *criar_no(lista *l, int destino, int custo);
void imprimir_grafo(lista **g, int vertice);
lista **novo_grafo(lista **g, int *vertices);
void imprimir_caminhos(int *vet, int pos, int destin, lista **g);
int existe(int *vet, int pos, int test);
int conta_aresta(lista **g, int vertice);
lista **nova_aresta(lista **g, int vertices);
int no_entrada(lista **g, int vertice, int escolha);
int no_saida(lista *g);
void imprimir_caminhosintermediario(int *vet, int pos, int destin, lista **g, int interm);
void maior_caminhos(int *vet, int *aux, int *test, int pos, int destin, lista **g);
lista **destruir(lista **g, int vertices);

int main(void){
	int opcao_menu, vertices, escolha;
	int *vet, destin, pos=1;
	lista **g=NULL;
	do{
		opcao_menu=menu();
		if(opcao_menu==1){
			g=novo_grafo(g, &vertices);
		}
		if(opcao_menu==2){
			imprimir_grafo(g, vertices);
		}
		if(opcao_menu==3){
			g=nova_aresta(g, vertices);			
		}
		if(opcao_menu==5){
			int entrada, saida, grau;
			printf("digite o vertice: ");
			scanf("%d", &escolha);
			entrada=no_entrada(g, vertices, escolha);
			saida=no_saida(g[escolha]);
			printf("sao %d nos de saida\n", saida);
			printf("sao %d nos de entrada\n", entrada);
			grau=saida+entrada;
			printf("grau do vertice: %d", grau);		
		}
		if(opcao_menu==6){
			int total_arestas, total, espaco;
			total_arestas=conta_aresta(g, vertices);
			total=(vertices*(vertices-1));
			espaco=total*0.7;
			if(total_arestas<=espaco)
				printf("e um grafo espaco");
			else
				printf("nao e um grafo espaco");					
		}
		if(opcao_menu==7){
			vet=(int*)malloc(vertices*sizeof(int));
			printf("digite o destino: ");
			scanf("%d", &destin);
			vet[0] = 1;
			imprimir_caminhos(vet, pos, destin, g);			
		}
		if(opcao_menu==8){
			int intermediario;
			pos=1;
			vet=(int*)malloc(vertices*sizeof(int));
			vet[0]=1;
			printf("digite o destino");
			scanf("%d", &destin);
			printf("digite o no intermediario: ");
			scanf("%d", &intermediario);
			imprimir_caminhosintermediario(vet, pos, destin, g, intermediario);
		}
		if(opcao_menu==9){
			int test, *aux;
			pos=1; test=1;
			vet=(int*)malloc(vertices*sizeof(int));
			vet[0]=1;
			aux=(int*)malloc(vertices*sizeof(int));
			printf("digite o destino: ");
			scanf("%d", &destin);
			maior_caminhos(vet, aux, &test, pos, destin, g);		
		}
		if(opcao_menu==10){
			g=destruir(g, vertices);
		}		
	}while(opcao_menu!=10);
	return 0;	
}

lista **destruir(lista **g, int vertices){
		int i;
		for(i=0; i<vertices; i++){
			lista *p=g[i];
			while(p!=NULL){
				lista *t=p;
				p=p->prox;
				free(t);
			}
		}	
    free(g);
    return NULL;
}

void maior_caminhos(int *vet, int *aux, int *test, int pos, int destin, lista **g){
	if(vet[pos-1]==destin){
		if(pos>*test){
			*test=pos;
			int i;
			for(i=1; i<pos; i++)
				aux[i]=vet[i];
			}
	}
	else{
		lista *p=g[vet[pos-1]];
		while(p!=NULL){
			if(existe(vet, pos, p->destino)==0){
				vet[pos]=p->destino;
				maior_caminhos(vet, aux, test, pos+1, destin, g);				
			}
			p=p->prox;
		}	
	}	
}

void imprimir_caminhosintermediario(int *vet, int pos, int destin, lista **g, int interm){
	if(vet[pos-1]==destin){
		if(existe(vet, pos, interm)==0){
			int i;
			for(i=0; i<pos; i++)
				printf("%d", vet[i]);
			printf("\n");
		}
	}
	else{
		lista *p=g[vet[pos-1]];
		while(p!=NULL){
			if(existe(vet, pos, p->destino)==0){
				vet[pos]=p->destino;
				imprimir_caminhosintermediario(vet, pos+1, destin, g, interm);				
			}
			p=p->prox;
		}	
	}	
}

int no_saida(lista *g){
	int cont=0;
  while(g!=NULL){
		cont++;
		g=g->prox;
	}
  return cont;	
}

int no_entrada(lista **g, int vertice, int escolha){
	int i, cont=0;
  for(i=1; i<vertice; i++){
    lista *p=g[i];
    while(p!=NULL){
			if(p->destino==escolha)
			cont++;
      p=p->prox;
    }
  }
  return cont;	
}

lista **nova_aresta(lista **g, int vertices){
	int escolha, destin, cust;
	printf("digite uma vertice entre 1 e %d: ", vertices-1);
	scanf("%d", &escolha);
	printf("digite o destino: ");
	scanf("%d", &destin);
	printf("digite o custo: ");
	scanf("%d", &cust);
	g[escolha]=criar_no(g[escolha], destin, cust);
	return g;
}

int conta_aresta(lista **g, int vertice){
  int i, cont=0;
  for(i=1; i<vertice; i++){
    lista *p=g[i];
    while(p!=NULL){
      cont++;
      p=p->prox;
    }
  }
  return cont;
}

void imprimir_caminhos(int *vet, int pos, int destin, lista **g){
	if(vet[pos-1]==destin){
		int i;
		for(i=0; i<pos; i++)
			printf("%d", vet[i]);
		printf("\n");		
	}
	else{
		lista *p=g[vet[pos-1]];
		while(p!=NULL){
			if(existe(vet, pos, p->destino)==0){
				vet[pos]=p->destino;
				imprimir_caminhos(vet, pos+1, destin, g);				
			}
			p=p->prox;
		}	
	}	
}

int existe(int *vet, int pos, int test){
	int i, cont=0;
	for(i=0; i<=pos; i++){
		if(vet[i]==test)
			break;
		else{
			cont++;
		}		
	}
	if(cont<pos)
		return 1;
	else
		return 0;
}

void imprimir_grafo(lista **g, int vertice){
  int i, cont=1;
  for(i=1; i<vertice; i++){
		printf("-- %d vertice --\n", i);
    lista *p=g[i];
    while(p!=NULL){
			printf("-- %d aresta --\n", cont);
      printf("destino: %d\n", p->destino);
      printf("custo: %d\n", p->custo);
      cont++;
      p=p->prox;
    }
    cont=1;
    printf("\n");
  }
}

lista **novo_grafo(lista **g, int *vertices){
	int arestas, destino, custo, i, x;
	printf("digite o numero de vertices: ");
	scanf("%d", vertices);
	*vertices=*vertices+1;
	g=(lista**)malloc(*vertices*sizeof(lista*));
	for(i=0; i<*vertices; i++){
		g[i]=NULL;		
	}
	destino=-1; custo=-1;
	g[0]=criar_no(g[0], destino, custo);
	for(i=1; i<*vertices; i++){
		printf("-- %d vertice --\n", i);
		printf("digite o numero de arestas: ");
		scanf("%d", &arestas);
		if(arestas>=1){			
			for(x=0; x<arestas; x++){
				printf("-- %d aresta --\n", x+1);			
				printf("digite o destino: ");
				scanf("%d", &destino);
				printf("digite o custo: ");
				scanf("%d", &custo);
				g[i]=criar_no(g[i], destino, custo);				
			}
		}		
	}
	return g;	
}

lista *criar_no(lista *l, int destino, int custo){
  lista *no=(lista*)malloc(sizeof(struct lista));
  no->destino=destino;
  no->custo=custo;
  no->prox=l;
  l=no;
  return l;
}

int menu(){
  int opcao;
  printf("\n-------------menu--------------\n");
  printf("1-ler um grafo\n");//es
  printf("2-imprimir um grafo\n");//es
  printf("3-inserir uma nova aresta no grafo\n");//es
  printf("4-remover uma aresta do grafo\n");
  printf("5-verificar um grau do vertice\n");//es
  printf("6-verificar se o grafico é espaço\n");//es
  printf("7-imprimir todos os caminhos entre origem e destino\n");//es
  printf("8-imprimir todos os caminhos entre origem e destino que\n");//es
  printf("  passam por um x intermediario\n");//es
  printf("9-imprimir o maior caminho entre uma origem e destino\n");//es
  printf("10-sair\n");
  printf("digite uma opcao: ");
  scanf("%d", &opcao);
  return opcao;
}
