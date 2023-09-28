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

  float valor = (*contasArray[2]).saldo;

  pthread_mutex_lock(&mutex);

  if ((*contasArray[0]).saldo >= valor) {
    (*contasArray[0]).saldo -= valor;
    (*contasArray[1]).saldo += valor;
  } else {
    if (!erro_impresso) {
      printf("Erro: Saldo insuficiente na conta from\n");
      erro_impresso = 1;
    }
  }

  pthread_mutex_unlock(&mutex);

  return NULL;

}

int main() {
  int qtde;
  float valor;
  
  printf("Digite a quantidade de transações: ");
  if (scanf("%d", &qtde) != 1) {
    printf("Erro ao ler a quantidade das transações.\n");
    return 1;
  }
  printf("Digite o valor das transações: ");
  if (scanf("%f", &valor) != 1) {
    printf("Erro ao ler o valor das transações.\n");
    return 1;
  }

  conta from, to, valores;
  from.saldo = 100;
  to.saldo = 100;
  valores.saldo = valor;

  conta **arg = (conta **)malloc(3 * sizeof(conta *));

  arg[0] = &from;
  arg[1] = &to;
  arg[2] = &valores;

  if (pthread_mutex_init(&mutex, NULL) != 0) {
    printf("O mutex falhou!");
    return 1;
  }

  pthread_t *thread_array = malloc(qtde * sizeof(pthread_t));
  
  for (int i = 0; i < qtde; i++) {
    pthread_create(&thread_array[i], NULL, transferencia, (void *)arg);
  }

  for (int i = 0; i < qtde; i++) {
    pthread_join(thread_array[i], NULL);
  }

  if (!erro_impresso) {
    printf("Transferindo %.2f para a conta to\n\n", valor);
    printf("Conta from: %.2f\n", from.saldo);
    printf("Conta to: %.2f\n\n", to.saldo);
    printf("Transferência concluída com sucesso!\n");
  }

  pthread_mutex_destroy(&mutex);
  free(thread_array);

  free(arg);

  return 0;
}
