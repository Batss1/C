#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	// imprimindo cabecalho do jogo
	printf("\n\n");
	printf("          P  /_\\  P                             \n"); 
	printf("         /_\\_|_|_/_\\                           \n"); 
	printf("     n_n | ||. .|| | n_n         Bem vindo ao    \n");
	printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!\n");
	printf("    |     |  |_|  |     |                        \n");
	printf("    |_____| ' _ ' |_____|                        \n");
	printf("          \\__|_|__/                             \n");
	printf("\n\n");    
    
    // declarando variaveis
    int nivel, numtentativas;
	int chute, i, tentativa = 1; 
	int acertou;
	
	// definindo a quantidade de pontos inicial
    double pontos = 1000;
    
    // gerando um numero secreto aleatorio
	srand(time(0));
	int numerogrande = rand();
    int numsecreto = (numerogrande % 100);
    
    // escolha do nivel de dificuldade
	printf("Qual nivel voce gostaria de jogar?\n");
    printf("(1)Facil  (2)Medio  (3)Dificil\n\n");
    printf("Escolha: ");
    scanf("%d",&nivel);
	
	switch (nivel){
		case(1): numtentativas = 15;break;
		case(2): numtentativas = 9;break;
		default: numtentativas = 6;
	}
	
	// loop principal do jogo
	for(i=1; i<= numtentativas; i++){
    	printf("\nTentativa %d \n",tentativa);
	    printf("Qual seu chute? ");
		scanf("%d", &chute);
		printf("Seu chute foi %d\n",chute);
	    int maior = (chute > numsecreto);
	    acertou = (chute == numsecreto);
	    
	    // tratando chute de numero negativo
		if (chute < 0){
			printf("Voce nao pode digitar numeros negativos");
			continue;
		}
		
		// verifica se acertou, foi maior ou menor
		if(acertou){
	    	break;
		}
		else if (maior){
	   		printf("Seu chute foi maior do que o numero secreto\n");
		}
		else {
			printf("Seu chute foi menor do que o numero secreto\n");
		}
		tentativa++;
		
		// calcula a quantidade de pontos
		double pontosperdidos = abs(chute - numsecreto) / (double)2;
		pontos -= pontosperdidos;
	}
	
	// imprimindo mensagem de vitoria ou derrota
	printf("\nFIM DE JOGO\n\n");
	if (acertou){
		printf("Parabens, voce GANHOU\n");
		printf("Voce acertou em %d tentativas\n",tentativa);
		printf("Voce fez %.1f pontos\n",pontos);
		   
                                                  
	    printf("  ##      ####                ##        ##    \n");
	    printf("  ####      ##              ####      ##      \n");
	    printf("    ##        ##            ##      ####      \n");
	    printf("      ##      ####        ##        ##        \n");
	    printf("      ####      ##      ####      ####        \n");
	    printf("        ##              ##      ####          \n");
	    printf("          ##          ##        ##            \n");
	    printf("          ####      ####      ##              \n");
	    printf("            ##  ################              \n");
	    printf("            ##################                \n");
	    printf("            ####################              \n");
	    printf("          ########      ##########            \n");
	    printf("          ########      ##########            \n");
	    printf("        ############    ##########            \n");
	    printf("        ############    ##########            \n");
	    printf("          ##########    ##########            \n");
	    printf("          ##########    ##########            \n");
	    printf("          ######################              \n");
	    printf("            ####################              \n");
	    printf("              ##############                  \n");
	    printf("                    ####                      \n");
                                                  
                                                  
	}
	else{
		printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
		printf("Voce PERDEU, Tente novamente!!");
	}
}
