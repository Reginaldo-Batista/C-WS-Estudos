#include <stdio.h>
#include <stdlib.h>
#define vazio 0
#define tempTam 3

typedef struct FilaCircular{

    int *vetor;
    int tamanho;
    int inicio;
    int fim;

}filaCircular;

void resetFilaCircular(filaCircular *filaCircular) {
    for (int i = 0; i < filaCircular->tamanho; i++) {
        filaCircular->vetor[i] = vazio;
    }
}

void constructFilaCircular(filaCircular *filaCircular) {
    filaCircular->tamanho = tempTam;
    filaCircular->inicio = 0;
    filaCircular->fim = 0;

    int *aux = (int *) malloc(sizeof(int) * filaCircular->tamanho);

    if (aux){
        filaCircular->vetor = aux;
        resetFilaCircular(filaCircular);
    }
    else
        printf("Erro ao alocar memoria!\n");

}

void push(filaCircular *fila, int novoValor) {
    int *vetor = fila->vetor; 

    if (vetor[fila->fim] == vazio) {

        vetor[fila->fim++] = novoValor;

        if (fila->fim > fila->tamanho - 1) {
            fila->fim = 0;
        }
        printf("Valor %d adicionado!\n", novoValor);
    }
    else
        printf("Fila circular cheia! Nao foi possivel adicionar o valor: %d\n", novoValor);
}

void pop(filaCircular *fila) {
    int *vetor = fila->vetor;

    if (vetor[fila->inicio] != vazio) {

        vetor[fila->inicio++] = vazio;

        if (fila->inicio > fila->tamanho - 1)
            fila->inicio = 0;
        printf("Elemento removido!\n");
    }
    else
        printf("Fila circular vazia!\n");

}


void printFilaCircular(const filaCircular *fila) {
    int inicio = fila->inicio;
    int tamanho = fila->tamanho;
    int fim = fila->fim;
    int i;

    if (inicio < fim) {
        for (i = inicio; i < fim; i++) {
            printf("%d ", fila->vetor[i]);
        }
    }

    else if (inicio > fim) {
        for (i = inicio; i < tamanho; i++) {
            printf("%d ", fila->vetor[i]);
        }

        for (i = 0; i < fim; i++) {
            printf("%d ", fila->vetor[i]);
        }
    }
    else if (inicio == fim) {
        if (fila->vetor[fim] != vazio) {
            for (i = inicio; i < tamanho; i++) {
                printf("%d ", fila->vetor[i]);
            }
            for (i = 0; i < fim; i++) {
                printf("%d ", fila->vetor[i]);
            }
        }
        else
            printf("Impressao invalida! Fila circular vazia!\n");
    }
    printf("\n");
}
int main() {

    filaCircular fila;

    constructFilaCircular(&fila);

    printFilaCircular(&fila);
    
    pop(&fila);

    push(&fila, 1);
    push(&fila, 2);
    push(&fila, 3);

    printFilaCircular(&fila);

    pop(&fila);

    printFilaCircular(&fila);

    push(&fila, 4);

    printFilaCircular(&fila);

    return 0;
}