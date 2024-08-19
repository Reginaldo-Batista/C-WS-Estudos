#include <stdio.h>
#include <stdlib.h>

typedef struct FilaCircular{

    int *vetor;
    int tamanho;
    int inicio;
    int fim;

}filaCircular;

void resetFilaCircular(filaCircular *filaCircular) {
    for (int i = 0; i < filaCircular->tamanho; i++) {
        filaCircular->vetor[i] = 0;
    }
}

void constructFilaCircular(filaCircular *filaCircular) {
    filaCircular->tamanho = 5;
    filaCircular->inicio = 0;
    filaCircular->fim = filaCircular->tamanho - 1;

    int *aux = (int *) malloc(sizeof(int) * filaCircular->tamanho);

    if (aux){
        filaCircular->vetor = aux;
        resetFilaCircular(filaCircular);
    }
    else
        printf("Erro ao alocar memoria!\n");

}


void printFilaCircular(const filaCircular *filaCircular) {
    for (int i = 0; i < filaCircular->tamanho; i++){
        printf("%d ", filaCircular->vetor[i]);
    }
    printf("\n");
}
int main() {

    filaCircular fila;

    constructFilaCircular(&fila);

    printFilaCircular(&fila);



    return 0;
}