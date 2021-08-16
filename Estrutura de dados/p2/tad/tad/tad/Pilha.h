typedef struct pilha *Pilha;
Pilha inicializar(void);
Pilha destruir(Pilha p);
Pilha inserir(Pilha p, int x);
Pilha remover(Pilha p, int *x);
void imprimir(Pilha p);
