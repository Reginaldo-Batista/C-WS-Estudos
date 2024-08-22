#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int valor;
    struct Node *proximo;

}node;

void imprimeNode(node *inicio) {

    if (inicio == NULL) {
        printf("Lista vazia!\n");
    }
    else {
        unsigned int contadorDeNodes = 0;
        node *auxNode = inicio;
        while (auxNode != NULL) {
            printf("Node[%d] = %d\n", contadorDeNodes, auxNode->valor);
            contadorDeNodes++;
            auxNode = auxNode->proximo;
        }
    }

}

void inserirNodeInicio(node **inicio, int novoValor) {

    node *novoNode = (node*) malloc(sizeof(node));

    if (novoNode) {
        novoNode->valor = novoValor;
        novoNode->proximo = *inicio;
        *inicio = novoNode;
    }
    else
        printf("Erro ao alocar memoria!\n");

}

void inserirNodeFim(node **inicio, int novoValor) {

    node *novoNode = (node*) malloc(sizeof(node));

    if (novoNode) {
        novoNode->valor = novoValor;
        novoNode->proximo = NULL;
        
        if (*inicio == NULL) {
            *inicio = novoNode;
        }
        else {
            node *auxNode = *inicio;
            while (auxNode->proximo) {
                auxNode = auxNode->proximo;
            }
            auxNode->proximo = novoNode;
        }

    }
    else
        printf("Erro ao alocar memoria!\n");

}

int main() {

    node *inicio = NULL; // A inicialização do ponteiro 'inicio' com NULL é extremamente necessária!
    int loopMenu, novoValor;

    do {
        system("cls");
        imprimeNode(inicio);

        printf("\nMenu:\n");
        printf("1 - Inserir node no inicio\n");
        printf("2 - Inserir node no fim\n");
        printf("3 - Sair\n");
        printf("\nSua escolha: ");
        scanf("%d", &loopMenu);

        switch (loopMenu) {
            case 1:
                printf("Digite um numero inteiro: ");
                scanf("%d", &novoValor);
                inserirNodeInicio(&inicio, novoValor);
                break;
            case 2:
                printf("Digite um numero inteiro: ");
                scanf("%d", &novoValor);
                inserirNodeFim(&inicio, novoValor);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (loopMenu != 3);

    return 0;
    
}