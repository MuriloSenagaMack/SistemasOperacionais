#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define FIBER_STACK 1024 * 64

pthread_mutex_t mutex;
int erro_impresso = 0; 

struct c {
  float saldo;
};
typedef struct c conta;

void *transferencia(void *arg) {
  conta **contasArray = (conta **)arg;

  float quantia = (*contasArray[2]).saldo;

  pthread_mutex_lock(&mutex);

  if ((*contasArray[0]).saldo >= quantia) {
    (*contasArray[0]).saldo -= quantia;
    (*contasArray[1]).saldo += quantia;
  } else {
    if (!erro_impresso) { 
      printf("Erro: Saldo insuficiente na conta from\n");
      erro_impresso = 1;
    }
  }

  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main(int argc, char *argv[]) {
  int num;
  float quantia;

  printf("Digite a quantidade de transações: ");
  if (scanf("%d", &num) != 1) {
    printf("Erro ao ler a quantidade das transações.\n");
    return 1;
  }

  printf("Digite o valor das transações: ");
  if (scanf("%f", &quantia) != 1) {
    printf("Erro ao ler o valor das transações.\n");
    return 1;
  }

  conta from, to, quantias;
  from.saldo = 100;
  to.saldo = 100;
  quantias.saldo = quantia;

  conta **arg = (conta **)malloc(3 * sizeof(conta *));

  arg[0] = &from;
  arg[1] = &to;
  arg[2] = &quantias;

  pthread_t *thread_array = malloc(num * sizeof(pthread_t));
  if (pthread_mutex_init(&mutex, NULL) != 0) {
    printf("O mutex falhou!");
    return 1;
  }

  for (int i = 0; i < num; i++) {
    pthread_create(&thread_array[i], NULL, transferencia, (void *)arg);
  }

  for (int i = 0; i < num; i++) {
    pthread_join(thread_array[i], NULL);
  }

  if (!erro_impresso) {
    printf("Transferindo %.2f para a conta to\n\n", quantia);
    printf("Conta from: %.2f\n", from.saldo);
    printf("Conta to: %.2f\n\n", to.saldo);
    printf("Transferência concluída com sucesso!\n");
  }

  pthread_mutex_destroy(&mutex);
  free(thread_array);
  free(arg);

  return 0;
}

