#include <stdio.h>

void imprimir_combinacoes(int *vet, int pos, int n, int *comb){
    if(pos==n){
        int i, cont=0, cont_1=0;
        for(i=0; i<n; i++){
            if(vet[i]==1)
                cont++;
            else    
                cont_1++;
        }
        if(cont_1>cont)
            *comb=*comb+1;
    }
    else{
        int i;
        for(i=0; i<=1; i++){
            vet[pos]=i;
            imprimir_combinacoes(vet, pos+1, n, comb);            
        }      
    }    
}

int main(void){
    int vet[3];
    int pos=0;
    int n, comb=0;
    printf("digite o numero de bytes: ");
    scanf("%d", &n);
    imprimir_combinacoes(vet, pos, n, &comb);
    printf("o numero de combinaçoes com mais zeros do que uns e: %d", comb);    
    return 0;
}
