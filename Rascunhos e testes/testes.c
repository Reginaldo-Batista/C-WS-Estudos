#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define stringCharMax 30 + 2

typedef struct Personagem {
	char nome[stringCharMax];
    short int modForca;
	short int modDestreza;
	short int modConstituicao;
	short int modInteligencia;
	short int modSabedoria;
	short int modCarisma;
}personagem;

typedef struct Vetor {
    struct Personagem *array;
    int tamanho;
}vetor;

void adjustString(char *string) {
    fgets(string, stringCharMax, stdin);
    string[strlen(string) - 1] = '\0';
}
void construtorPersonagemPadrao(personagem *player) {
	char nome[stringCharMax];
	printf("Nome do personagem: ");
	adjustString(nome);
	strcpy(player->nome, nome);

	printf("Modificador de força: ");
	scanf("%hd", &player->modForca);
	printf("Modificador de destreza: ");
	scanf("%hd", &player->modDestreza);
	printf("Modificador de constituição: ");
	scanf("%hd", &player->modConstituicao);
	printf("Modificador de inteligência: ");
	scanf("%hd", &player->modInteligencia);
	printf("Modificador de sabedoria: ");
	scanf("%hd", &player->modSabedoria);
	printf("Modificador de carisma: ");
	scanf("%hd", &player->modCarisma);
	getchar();
}

void printPersonagem(personagem *personagem) {
	printf("Nome: %s\n", personagem->nome);
	printf("Força: %hd\n", personagem->modForca);
	printf("Destreza: %hd\n", personagem->modDestreza);
	printf("Constituição: %hd\n", personagem->modConstituicao);
	printf("Inteligência: %hd\n", personagem->modInteligencia);
	printf("Sabedoria: %hd\n", personagem->modSabedoria);
	printf("Carisma: %hd\n", personagem->modCarisma);
	printf("\n");
}

int main() {
	char nomeTemp[30];
	char *nome;
	unsigned int quantidadeDeLetrasDeNome = strlen(nome)

	personagem teste;
	construtorPersonagemPadrao(&teste);
	printPersonagem(&teste);

	return 0;
}