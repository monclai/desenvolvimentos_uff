#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){

    int size, myRank;
    MPI_Status st;

    /*
        Processo 0 envia valores para cada um dos outros processos
        estes, por sua vez, multiplicam este valor recebido e devolvem o novo 
        valor para o processo 0, que vai soma-los.
    */

   int valorInicial, valorModificado, total, nproc;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

    printf("Hello! Sou o processo %d de um total de %d\n", myRank, size);
    fflush(stdout);

    if(myRank == 0){
        //Sou o processo mestre
        for(nproc = 1; nproc < size; nproc++){
            valorInicial = nproc*10;
            MPI_Send(&valorInicial, 1, MPI_INT, nproc, 0, MPI_COMM_WORLD);
            printf("MESTRE - Enviei %d para PROC(%d)\n", valorInicial, nproc);
            fflush(stdout);
        }
        total = 0;
        for (nproc = 1; nproc < size; nproc++)
        {
            //MPI_Recv(&valorModificado, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &std); Para receber de qualquer processo e qualquer tag
            MPI_Recv(&valorModificado, 1, MPI_INT, nproc, 1, MPI_COMM_WORLD, &st);
            printf("MESTRE - Recebi o valor valor modificado %d\n", valorModificado);
            fflush(stdout);

            total += valorModificado;
        }

        printf("MESTRE - Total do processamento = %d\n", total);
        fflush(stdout);
        

    }
    else{
        //Sou um dos esccravos
        MPI_Recv(&valorInicial, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
        printf("ESCRAVO (%d) - Recebi %d do mestre\n", myRank, valorInicial);
        fflush(stdout);

        valorModificado = valorInicial * 10;

        MPI_Send(&valorModificado, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
        printf("ESCRAVO(%d) - Valor Modificado = %d\n", myRank, valorModificado);
    }


    MPI_Finalize();


    return 0;
}