#include <stdio.h>
#include <stdlib.h>
#define fimMenu 4

unsigned int quantidadeDeNodes = 0;

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
        quantidadeDeNodes++;
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
            quantidadeDeNodes++;
        }
        else {
            node *auxNode = *inicio;
            while (auxNode->proximo) {
                auxNode = auxNode->proximo;
            }
            auxNode->proximo = novoNode;
            quantidadeDeNodes++;
        }

    }
    else
        printf("Erro ao alocar memoria!\n");

}

void inserirNode(node **inicio, unsigned int indice, int novoValor) {

    node *novoNode = (node*) malloc(sizeof(node));

    if (novoNode) {
        novoNode->valor = novoValor;
        
        if (*inicio == NULL) {
            novoNode->proximo = NULL;
            *inicio = novoNode;
            quantidadeDeNodes++;
        }
        else if (indice > quantidadeDeNodes - 1 || indice <= 0) {
            printf("Posicao invalida!\n");
            free(novoNode);
        }
        else {
            node *auxNode1 = *inicio;
            node *auxNode2 = *inicio;
            unsigned int auxIndiceNode1 = 0;
            unsigned int auxIndiceNode2 = 0;
            while (auxIndiceNode1 < indice) {
                auxNode1 = auxNode1->proximo;
                auxIndiceNode1++;
            }
            while (auxIndiceNode2 < indice - 1) {
                auxNode2 = auxNode2->proximo;
                auxIndiceNode2++;
            }
            novoNode->proximo = auxNode1;
            auxNode2->proximo = novoNode;
            quantidadeDeNodes++;
        }

    }
    else
        printf("Erro ao alocar memoria!\n");

}

int main() {

    node *inicio = NULL; // A inicialização do ponteiro 'inicio' com NULL é extremamente necessária!
    int loopMenu, novoValor, indice;

    do {
        system("cls");
        printf("Quantidade de nodes: %d\n", quantidadeDeNodes);
        imprimeNode(inicio);

        printf("\nMenu:\n");
        printf("1 - Inserir node no inicio\n");
        printf("2 - Inserir node no fim\n");
        printf("3 - Inserir node em determinado indice\n");
        printf("%d - Sair\n", fimMenu);
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
                printf("Digite um numero inteiro: ");
                scanf("%d", &novoValor);
                printf("Digite o indice desejado: ");
                scanf("%d", &indice);
                inserirNode(&inicio, indice, novoValor);
                break;
            case fimMenu:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (loopMenu != 4);

    return 0;
    
}