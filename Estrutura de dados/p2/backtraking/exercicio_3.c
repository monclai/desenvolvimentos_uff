#include <stdio.h>

void imprimir_combinacoes(int *vet, int pos, char *vet_aux){
    if(pos==3){
        int i;
        for(i=0; i<3; i++)
            printf("%c", vet[i]);
        printf("\n");
    }
    else{
        int i;
        for(i=0; i<=2; i++){
            vet[pos]=vet_aux[i];
            imprimir_combinacoes(vet, pos+1, vet_aux);            
        }      
    }    
}

int main(void){
    int vet[3];
    int pos=0;
    char vet_aux[3];
    vet_aux[0]='a';
    vet_aux[1]='e';
    vet_aux[2]='i';
    imprimir_combinacoes(vet, pos, vet_aux);    
    return 0;
}
