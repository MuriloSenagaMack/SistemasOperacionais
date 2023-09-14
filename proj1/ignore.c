#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct c {
    int saldo;
};

typedef struct c conta;
conta from, to;
int valor;

// Mutex para proteger o acesso às contas
pthread_mutex_t mutex;

// Função que realiza a transferência
void* transferencia(void* arg) {
    pthread_mutex_lock(&mutex);
    
    if (from.saldo >= valor) {
        from.saldo -= valor;
        to.saldo += valor;
    }

    printf("Transferência concluída com sucesso!\n");
    printf("Saldo de c1: %d\n", from.saldo);
    printf("Saldo de c2: %d\n", to.saldo);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[10];
    int i;

    // Inicializa as contas e o mutex
    from.saldo = 100;
    to.saldo = 100;
    valor = 10;
    pthread_mutex_init(&mutex, NULL);

    printf("Transferindo 10 para a conta c2\n");

    for (i = 0; i < 10; i++) {
        if (pthread_create(&threads[i], NULL, transferencia, NULL) != 0) {
            perror("pthread_create");
            exit(2);
        }
    }

    // Aguarda o término das threads
    for (i = 0; i < 10; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(3);
        }
    }

    // Destrói o mutex
    pthread_mutex_destroy(&mutex);

    printf("Transferências concluídas.\n");
    
    return 0;
}
