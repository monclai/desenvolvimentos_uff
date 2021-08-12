#include <stdio.h>

int inverte(int num);
int main(){
    unsigned int valor, invert;
    printf("inverte valores\n");
    printf("*-------------*\n");
    printf("Digite o valor entre 0 e 999\n");
    scanf("%d", &valor);
    invert = inverte(valor);
    printf("o valor invertido e: %d", invert);
}

int inverte(int num){
    int part_1, part_2, part_3, novo;
    if (num <= 99){
        part_1 = (num/10);
        part_2 = num%10;
        novo = (part_2*10)+part_1;
    }
        if (num <= 999 && num >= 100){
        part_1 = num/100;
        part_2 = (num%100)/10;
        part_3 = (num%100)%10;
        novo = (part_3*100)+(part_2*10)+(part_1);
    }
    return novo;
}
