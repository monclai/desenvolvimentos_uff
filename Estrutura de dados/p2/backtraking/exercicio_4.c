#include <stdio.h>

void moedas(int *vet_cent, int *vet_total, int quant, int moeda, int pos);

int main(void){
    int vet_total[4];
    int vet_cent[4];
    int moeda, pos=0, quant=4;
    vet_cent[0]=1;
    vet_cent[1]=5;
    vet_cent[2]=10;
    vet_cent[3]=25;
    printf("digite o total de moedas: ");
    scanf("%d", &moeda);
    printf("1 | 5 | 10 | 25\n\n");       
    moedas(vet_cent, vet_total, quant, moeda, pos);
    return 0;
}

void moedas(int *vet_cent, int *vet_total, int quant, int moeda, int pos){
    if(pos==4){
        int soma=0, i;
        for(i=0; i<quant; i++){
            soma=soma+(vet_total[i]*vet_cent[i]);
        }
        if(soma==moeda){
            for(i=0; i<quant; i++){
                printf("%d   ", vet_total[i]);
            }
            printf("\n");
        }        
    }
    else{
        int max, i;
        max=moeda/vet_cent[pos];
        for(i=0; i<=max; i++){
            vet_total[pos]=i;
            moedas(vet_cent, vet_total, quant, moeda, pos+1);
        }        
    }   
}
