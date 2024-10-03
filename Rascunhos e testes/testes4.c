#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void limpandoString(char *string, int sizeof_string) {

    for(int i = 0; i < sizeof_string; i++) {
        string[i] = ' ';
    }
    string[sizeof_string] = '\0';

}

int main() {
    char alfabeto[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    // A inserção do texto se faz dentro do código-fonte, porém pode-se alterar para ser feito no terminal.
    // Por enquanto só é aceitado letras maiúsculas e espaço em branco.
    char entrada[] = "INSIRA O SEU TEXTO AQUI";
    int entrada_tamanho = strlen(entrada);

    // Fazendo alocação dinâmica de memória para a "string", de acordo com o tamanho da entrada.
    char *saida = (char *) malloc((entrada_tamanho + 1) * sizeof(char));
    limpandoString(saida, entrada_tamanho);

    int cont;

    for(int i = 0; i < entrada_tamanho; i++) {
        cont = 0;
        while(saida[i] != entrada[i]) {
            saida[i] = alfabeto[cont++];
            printf("%s\n", saida);
            Sleep(35);
        }
    }
    printf("%s", saida);

    return 0;
}
