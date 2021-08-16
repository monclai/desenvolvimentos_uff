typedef struct fila *Fila;
Fila inicializar(void);
Fila inserir(Fila p, int mat, char* nome, int nota);
void imprimir(Fila p);
Fila remover(Fila p, int *mat, char *nome, int *nota );
int vazia(Fila p);
int cheia(Fila p);
Fila destruir(Fila p);