#include <stdio.h>

void imprimir_combinacoes(int *vet, int pos, int n){
    if(pos==n){
        int i, cont=0;
        for(i=0; i<n; i++){
            if(vet[i]==1)
                cont++;
						if(cont>=2)
                break;
				}
        if(cont>=2){
            for(i=0; i<n; i++)
                printf("%d", vet[i]);
            printf("\n");
        }
    }
    else{
        int i;
        for(i=0; i<=1; i++){
            vet[pos]=i;
            imprimir_combinacoes(vet, pos+1, n);            
        }      
    }    
}

int main(void){
    int vet[3];
    int pos=0;
    int n;
    printf("digite o numero de bytes: ");
    scanf("%d", &n);
    imprimir_combinacoes(vet, pos, n);    
    return 0;
}
