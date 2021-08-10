#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10
#define MAXLOOP 100000

void *thread_function(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// variável global:
int  counter = 0;

int main() {
   pthread_t thread_id[NTHREADS];
   int i, j;

   for(i=0; i < NTHREADS; i++)
      pthread_create( &thread_id[i], NULL, thread_function, NULL );

   for(j=0; j < NTHREADS; j++)
      pthread_join( thread_id[j], NULL);

   printf("Valor final de counter: %d\n", counter);
}

void *thread_function(void *dummyPtr) {
   int i;
   printf("Thread number %ld\n", pthread_self());
   for (i=0;i<MAXLOOP;i++) {
       pthread_mutex_lock( &mutex1 );
       counter++;
       pthread_mutex_unlock( &mutex1 );
   }
}