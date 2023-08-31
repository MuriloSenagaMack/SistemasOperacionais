#include <stdio.h>

int main() {
    int tamanho = 3;
    
    int matriz[3][3] = {
        {5, 12, 8},
        {3, 9, 1},
        {7, 2, 10}
    };
    
    int linhaMenor = 0;
    int menorNumero = matriz[0][0];
    
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (matriz[i][j] < menorNumero) {
                menorNumero = matriz[i][j];
                linhaMenor = i;
            }
        }
    }
    
    printf("Número da linha que contém o menor dentre todos os números lidos: %d.\n", linhaMenor + 1);
    
    return 0;
}
