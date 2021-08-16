typedef struct fila *Fila;
Fila inicializar(void);
Fila inserir(Fila p, void *x);
Fila remover(Fila p, void **x);
int vazia(Fila p);
int cheia(Fila p);
Fila destruir(Fila p);