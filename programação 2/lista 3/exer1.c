#include <stdio.h>

char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media);
int main(){
	float p1, p2, p3, media;	
	int faltas, aulas;
	char result;
	printf("digite as notas p1, p2, p3: ");
	scanf("%f %f %f", &p1, &p2, &p3);
	printf("digite o numero de aulas: ");
	scanf("%d", &aulas);
	printf("digite o numero de faltas: ");
	scanf("%d", &faltas);
	result = situacao(p1, p2, p3, faltas, aulas, &media);
	printf("\n a = aprovado\n r = reprovado\n f = reprovado por faltas\n");
	printf("situacao do aluno foi %c", result);
}

char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media){
	char resp;
	*media =  (p1 + p2 + p3)/3;
	if(faltas > (0.25 * aulas))
		return resp = 'f';
	else if(*media > 6.0)
		return resp  = 'a';
	else
		return resp = 'r';	
}
