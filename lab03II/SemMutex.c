#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

double pi = 0;

void* Thread_sum(void* rank) {
  int* my_rank = (int*) rank;
  double factor;
  int n = my_rank[0];
  int slice = my_rank[1];

  double sum = 0.0;
  int first = slice * n;
  int last = first + slice;

  if(first % 2 == 0) {
    factor = 1.0;
  } else {
    factor = -1.0;  
  }

  for(int i = first; i < last; i++, factor = -factor) {
    sum += factor/(2*i+1);
  }

  pi += sum;
  free(rank); 
}

int main(int argc, char* argv[]) {
  int n = strtol(argv[1], NULL, 10);
  int slice = strtol(argv[2], NULL, 10);

  pthread_t* thread_array = malloc(n * sizeof(pthread_t));

  for (int i = 0; i < n; i++) {
    int * rank = (int*) malloc(2 * sizeof(int));
    rank[0] = i;
    rank[1] = slice;
    pthread_create(&thread_array[i], NULL, Thread_sum, (void*)rank);
  }

  for (int i = 0; i < n; i++) {
    pthread_join(thread_array[i], NULL);
  }

  pi = 4 * pi;
  printf("A quantidade de threads é %d, e o valor de pi é %.10lf\n", n, pi);

  free(thread_array);
  return 0;
}
