#include <stdio.h>

int subsequencia(int *seq, int n, int *vet, int m);
int main(){
	int seq[]={34,7,41,52,13};
	int vet[]={9, 34, 12, 7, 41, 52, 9, 27, 13};
	int n, m;
	n=5;
	m=9;
	if(subsequencia(seq, n, vet, m)==0)
		printf("nao e subsequencia.\n");
	else
		printf("e subsequencia.\n");
}

int subsequencia(int *seq, int n, int *vet, int m)
{
    int i, t ,x;
    x=0;
    for(i=0;i<n;i++)
    {
        for(t=x;t<m;t++)
        {
            if(seq[i]==vet[t])
            {
                x=t;
                break;
            }
            if(t==m-1 && seq[i]!=vet[m-1])
                return 0;
        }
    }
    return 1;

}
