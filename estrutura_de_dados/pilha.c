#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    int *vetor;
    int tamanho;
    int topo;
}pilha;

void constructPilha(pilha *pilha) {

    pilha->topo = -1;

    printf("Insira o tamanho maximo da pilha: ");
    scanf("%d", &pilha->tamanho);

    int *p = (int*) malloc(sizeof(int) * pilha->tamanho);
    if (p) {
        pilha->vetor = p;
        for (int i = 0; i < pilha->tamanho; i++)
            pilha->vetor[i] = 0;
    }
    else
        printf("Erro ao alocar a memoria!\n");
}

void printPilha(const pilha *pilha) {
    for (int i = 0; i < pilha->tamanho; i++){
        printf("%d ", pilha->vetor[i]);
    }
    printf("\n");
}

void pushPilha(pilha *pilha, int novoValor) {
    if (pilha->topo == pilha->tamanho - 1)
        printf("Pilha cheia!\n");
    else {
        pilha->topo++;
        pilha->vetor[pilha->topo] = novoValor;
    }
}

void popPilha(pilha *pilha) {
    if (pilha->topo == -1)
        printf("Pilha vazia!");
    else {
        pilha->vetor[pilha->topo] = 0;
        pilha->topo--;
    }
}

int main() {
    
    pilha pilha;

    constructPilha(&pilha);

    printPilha(&pilha);

    pushPilha(&pilha, 5);
    pushPilha(&pilha, 2);
    pushPilha(&pilha, 1);
    pushPilha(&pilha, 3);
    pushPilha(&pilha, 4);

    printPilha(&pilha);

    popPilha(&pilha);

    printPilha(&pilha);
    
    free(pilha.vetor);

    return 0;
}