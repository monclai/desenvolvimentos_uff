#include <stdio.h>

#define pes_cm 30.48f
#define pol_cm 2.54f
double metros(int pes, int polegadas);

int main(){
	int pes, polegadas;
	double metro;
	printf ("digite a altura em pes e polegadas\n");
	printf ("digite o pes: ");
	scanf("%d", &pes);
	printf("digite as polegadas: ");
	scanf("%d", &polegadas);
	metro = metros(pes, polegadas);
	printf("a conversao da %.3lf metros", metro);
}

double metros(int pes, int polegadas){
	double conver_pes, conver_pol, metros;
	conver_pes = pes * pes_cm;
	conver_pol = polegadas * pol_cm;
	metros = conver_pes + conver_pol;
	if (metros >= 100)
		return (metros/100.0);
	else
		return metros;
	
}
