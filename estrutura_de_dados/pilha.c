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
        printf("Pilha vazia!\n");
    else {
        pilha->vetor[pilha->topo] = 0;
        pilha->topo--;
    }
}

int main() {
    
    pilha pilha;

    constructPilha(&pilha);

    int escolha;
    int novoValor;
    while (escolha != 3) {
        system("cls");
        escolha = 0;
        printf("Pilha atual: ");
        printPilha(&pilha);
        printf("\n\n[1]Push\n");
        printf("[2]Pop\n");
        printf("[3]Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Insira o novo valor: ");
                scanf("%d", &novoValor);
                pushPilha(&pilha, novoValor);
                break;

            case 2:
                popPilha(&pilha);
                break;

            case 3:
                printf("Saindo...");
                break;

            default:
                printf("Comando invalido!\n");
        }

    }
    
    free(pilha.vetor);

    return 0;
}
