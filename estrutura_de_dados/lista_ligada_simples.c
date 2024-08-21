#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int valor;
    struct Node *proximo;

}node;

void startInsertNode(node *inicio, int novoValor) {

    node *novoNode = (node*) malloc(sizeof(node));

    if (novoNode) {
        novoNode->valor = novoValor;
        novoNode->proximo = inicio->proximo;
        inicio->proximo = novoNode;
    }
    else
        printf("Erro ao alocar memoria!\n");

}

int main() {

    node inicio;

    startInsertNode(&inicio, 21);

    printf("valor: %d", inicio.proximo->valor);

    return 0;
}