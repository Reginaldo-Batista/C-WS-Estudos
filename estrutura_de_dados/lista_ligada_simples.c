#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int valor;
    struct Node *proximo;

}node;

void InserirNodeInicio(node **inicio, int novoValor) {

    node *novoNode = (node*) malloc(sizeof(node));

    if (novoNode) {
        novoNode->valor = novoValor;
        novoNode->proximo = *inicio;
        *inicio = novoNode;
    }
    else
        printf("Erro ao alocar memoria!\n");

}

void InserirNodeFim(node **inicio, int novoValor) {
    
}

int main() {

    node *inicio;

    InserirNodeInicio(&inicio, 21);

    printf("valor: %d", inicio->valor);

    return 0;
}