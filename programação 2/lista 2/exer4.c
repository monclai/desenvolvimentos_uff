#include <stdio.h>

double harmonico(int n);
int main(){
		int pos;
		double resp;
		printf("digite a posição do n-esimo numero a ser calculado");
		scanf("%d", &pos);
		resp = harmonico(pos);
		printf("o somatório é %.7f", resp);	
}

 double harmonico(int n){
	if (n==1)
		return 1;
	else
		return (1.0/n) + (harmonico(n-1));
}
