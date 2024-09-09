#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "forca.h"
#include <time.h>



char palavrasecreta[TAMANHO_PALAVRA];
char chutes[ALFABETO];
int chutesdados = 0;

void abertura(){
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n");
}

void chuta () {
	char chute;
	printf("Qual letra? ");
	scanf(" %c", &chute);
	chutes[chutesdados] = chute;
	chutesdados++;
}

int jachutou(int letra) {
	int achou = 0;
	int j;
	for(j = 0; j < chutesdados; j++){
		if (chutes[j] == letra){
			achou = 1;
			break;
		}
 	}
 	return achou;
}

void desenhaforca() {
	int i;
    int erros = chuteserrados();
    printf("  _______       \n");
    printf(" |/      |      \n");
    // Cabeça
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));

    // Tronco
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));

    // Barriga (tronco)
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));

    // Pernas
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");
	
	for(i = 0; i < strlen(palavrasecreta); i++){
		int achou = jachutou(palavrasecreta[i]);
		if (achou){
			printf("%c ", palavrasecreta[i]);
		}else{
			printf("_ ");
		}
	}
}

void adicionapalavra() {
	char quer;
	printf("Gostaria de adicionar uma palavra ao jogo? (S/N)");
	scanf(" %c",&quer);
	
	if (quer == 'S'){
		char novapalavra[TAMANHO_PALAVRA];
		printf("Qual palavra? ");
		scanf("%s", &novapalavra);
		
		FILE* f = fopen("palavras.txt", "r+");
		if (f== 0){
			printf("Banco de dados não disponivel \n\n");
			exit(1);
		}
		
		int qtd;
		fscanf(f,"%d", &qtd);
		qtd++;
		
		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qtd);
		
		fseek(f,0, SEEK_END);
		fprintf(f,"\n%s",novapalavra);
		fclose(f);
	}
}

void escolhepalavra() {
	FILE* f;
	
	f = fopen("palavras.txt", "r");
	if (f== 0){
		printf("Banco de dados não disponivel \n\n");
		exit(1);
	}
	
	int qtdepalavras, i;
	fscanf(f, "%d", &qtdepalavras);
	srand(time(0));
	int randomico = rand() % qtdepalavras;
	for(i= 0; i<= randomico; i++){
		fscanf(f, "%s", palavrasecreta);
	}
	fclose(f);
	
}

int letraexiste(char letra){
	int j;
	for(j = 0; j < strlen(palavrasecreta); j++){
		if (letra == palavrasecreta[j]){
			return 1;
		}
	}	
	return 0;
}

int chuteserrados() {
	int i, erros = 0;
	for (i = 0; i < chutesdados; i++){
		if (!letraexiste(chutes[i])) {
			erros++;	
		}
	}
	return erros;	
}
int enforcou() {
	return chuteserrados() >= 5;
}

int acertou() {
	int i;
	for(i = 0; i < strlen(palavrasecreta); i++){
		if (!jachutou(palavrasecreta[i])){
			return 0;
		}
	}
	return 1;
}
int main(){
		
	
	abertura();
	escolhepalavra();
	
	do{
		desenhaforca();
		chuta();
		printf("\n");
		
		
	}while (!acertou() && !enforcou());
	if (acertou()){
		printf("Parabens voce GANHOU!!\n");
	printf("   ___________      \n");
    printf("  '._==_==_=_.'     \n");
    printf("  .-\\:      /-.    \n");
    printf(" | (|:.     |) |    \n");
    printf("  '-|:.     |-'     \n");
    printf("    \\::.    /      \n");
    printf("     '::. .'        \n");
    printf("       ) (          \n");
    printf("     _.' '._        \n");
    printf("    '-------'       \n\n");
	}else{
		printf("Puxa, você foi enforcado!");
		printf("A palavra era **%s** \n\n",palavrasecreta);
		printf("    _______________          \n");
		printf("   /               \\        \n");
		printf("  /                 \\       \n");
		printf("//                   \\/\\    \n");
		printf("\\|   XXXX     XXXX   | /    \n");
		printf(" |   XXXX     XXXX   |/      \n");
		printf(" |   XXX       XXX   |       \n");
		printf(" |                   |       \n");
		printf(" \\__      XXX      __/      \n");
		printf("   |\\     XXX     /|        \n");
		printf("   | |           | |         \n");
		printf("   | I I I I I I I |         \n");
		printf("   |  I I I I I I  |         \n");
		printf("   \\_             _/        \n");
		printf("     \\_         _/          \n");
		printf("       \\_______/            \n\n");
	}
	adicionapalavra();
}
