#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t childpid = 0;
    int i, n;
    if (argc != 2) {
        printf("Uso: %s processos\n", argv[0]);  // Imprimir em stdout em vez de stderr
        return 1;
    }
    n = atoi(argv[1]);
    for (i = 1; i < n; i++) {
        if (childpid = fork()) {
            break;
        }
    }
    printf("i:%d ID do processo:%ld ID do pai:%ld ID do filho:%ld\n",  // Imprimir em stdout em vez de stderr
           i, (long)getpid(), (long)getppid(), (long)childpid);
    return 0;
}

