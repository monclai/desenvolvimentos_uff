#include <stdio.h>
#include <stdlib.h>

void imprimir_combinacoes(int *vet, int pos, char *vet_aux, int n){
    if(pos==n){
        int i;
        int cont_i=0, cont_a=0, cont_e=0;
				for(i=0; i<n; i++){
					if(vet[i]=='i')
						cont_i++;
					if(vet[i]=='a')
						cont_a++;
					if(vet[i]=='e')
						cont_e++;
				}
				if(cont_a>=1 && cont_e>=1 && cont_i>=1){
					for(i=0; i<n; i++)
							printf("%c", vet[i]);
					printf("\n");
				}
    }
    else{
        int i;
        for(i=0; i<=2; i++){
            vet[pos]=vet_aux[i];
            imprimir_combinacoes(vet, pos+1, vet_aux, n);
        }
    }
}

int main(void){
    int *vet;
    int pos=0, quant;
    char vet_aux[3];
    vet_aux[0]='a';
    vet_aux[1]='e';
    vet_aux[2]='i';
    printf("digite a quantidade de letras: ");
    scanf("%d", &quant);
    vet=(int*)malloc(quant*sizeof(int));
    imprimir_combinacoes(vet, pos, vet_aux, quant);
    return 0;
}
