typedef struct fila *Fila;
Fila inicializar(void);
Fila destruir(Fila p);
Fila inserir(Fila p, int x);
Fila remover(Fila p, int *x);
void imprimir(Fila p);
int vazia(Fila p);
int cheia(Fila p);