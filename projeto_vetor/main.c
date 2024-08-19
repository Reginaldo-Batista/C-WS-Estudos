#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"

int main() {

    vetor vetor;

    inicializaVetor(&vetor);

    imprimeVetor(vetor);
    
    free(vetor.array); 
    
    system("pause");

    return 0;

}