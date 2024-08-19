typedef struct Vetor{

    char nome[30];
    int tamanho;
    int *array; // aponta para o primeiro elemento do array

}vetor;

void fAdjustString(char *string){
    fgets(string, 30, stdin);
    string[strlen(string) - 1] = '\0';
}

void alocaVetor(vetor *vetor){

    int *aux = (int *) malloc(sizeof(vetor->tamanho));

    if (aux) {
        vetor->array = aux;
    } else 
        printf("Erro ao alocar memoria!\n");

}

void atribuiValoresVetor(vetor *vetor) {

    printf("Insira os valores!\n");
    for (int i = 0; i < vetor->tamanho; i++) {
        printf("%s[%d]: ", vetor->nome, i);
        scanf("%d", &vetor->array[i]);
    }

}

void inicializaVetor(vetor *vetor) {

    printf("Nome do vetor: ");
    fAdjustString(vetor->nome);

    printf("\nTamanho do vetor: ");
    scanf("%d", &vetor->tamanho);

    alocaVetor(vetor);
    printf("\n");
    atribuiValoresVetor(vetor);
    system("cls");

}

void imprimeVetor(vetor vetor) {
    
    printf("Nome do vetor: %s", vetor.nome);
    printf("\nTamanho do vetor: %d", vetor.tamanho);
    printf("\nConteudo do vetor: ");

    for (int i = 0; i < vetor.tamanho; i++) {
        printf("%d ", vetor.array[i]);
    }
    printf("\n");

}