//Criando um objeto Vetor com atributos interessantes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Personagem{
    int valorElemento;
    int indiceValor;
};

struct vetor{
    char nome[30];
    int tamanho;
    struct Personagem *arrayOrdenado;
};

// Função para realizar o Bubble Sort
void bubbleSort_Vetor(struct Personagem *arr, int n) {
    struct Personagem temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].valorElemento > arr[j+1].valorElemento) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void atribuindoValoresArray_Vetor(struct vetor *vetor){
    int tamanho = vetor->tamanho;
    printf("Insira os valores de cada posicao do vetor %s\n\n", vetor->nome);
    for (int i = 0; i < tamanho; i++) {
        printf("Indice[%d]: ", i);
        scanf("%d", &vetor->arrayOrdenado[i].valorElemento);
        vetor->arrayOrdenado[i].indiceValor = i;
        getchar();
        printf("\n");
    }
    bubbleSort_Vetor(vetor->arrayOrdenado, tamanho);
}

void construtorVetor(struct vetor *vetor, char nome[30], int tamanho){
    strcpy(vetor->nome, nome);
    vetor->tamanho = tamanho;
    vetor->arrayOrdenado = (struct Personagem *) malloc(tamanho * sizeof(struct Personagem));
    if (vetor->arrayOrdenado == NULL){
        printf("Memoria insuficiente\n");
    }
    else {
        atribuindoValoresArray_Vetor(vetor);
        printf("Vetor %s construido com sucesso!\n", vetor->nome);
        printf("Tamanho: %d\n\n", vetor->tamanho);
    }
}



int main() {

    struct vetor pirulei;
    construtorVetor(&pirulei, "Jorginho", 5);

    printf("Valores do vetor ordenados:\n");
    for (int i = 0; i < pirulei.tamanho; i++) {
        printf("%d ", pirulei.arrayOrdenado[i].valorElemento); 
    }
    printf("\n\n");

    return 0;
}