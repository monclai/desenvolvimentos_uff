#include <stdio.h>

void imprimir_combinacoes(int *vet, int pos){
    if(pos==3){
        int i;
        for(i=0; i<3; i++)
            printf("%d", vet[i]);
        printf("\n");
    }
    else{
        int i;
        for(i=0; i<=1; i++){
            vet[pos]=i;
            imprimir_combinacoes(vet, pos+1);            
        }      
    }    
}

int main(void){
    int vet[3];
    int pos=0;
    imprimir_combinacoes(vet, pos);    
    return 0;
}