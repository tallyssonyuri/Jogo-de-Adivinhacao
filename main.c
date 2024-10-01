#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  
  // Imprime o cabecalho do jogo
  printf("*********************************\n");
  printf("Bem vindo ao jogo de adivinhacao!\n");
  printf("*********************************\n");

  int segundos = time(0);
  srand(segundos);

  int numero_grande = rand();

  int numerosecreto = numero_grande % 100;
  int chute;
  int tentativas = 1;
  double pontos = 1000;

  int acertou = 0; 

  int nivel;

  int numero_de_tentativas;
  int escolha = 0;
  
  while (escolha == 0){
    printf("\nQual nivel voce deseja jogar?\n");
    printf("(1) Facil | (2) Medio | (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel) {
      case 1:
        numero_de_tentativas = 14;
        escolha = 1;
        printf("Você escolheu o nível fácil!\n\n");
        break;
      case 2:
        numero_de_tentativas = 10;
        escolha = 1;
        printf("Você escolheu o nível médio!\n\n");
        break;
      case 3:
        numero_de_tentativas = 6;
        escolha = 1;
        printf("Você escolheu o nível difícil!\n\n");
        break;
      default:
        printf("Por favor, escolha um nível válido!\n\n");
        continue;
    }
  }


  for(int i = 1; i <= numero_de_tentativas; i++) {
    printf("*********************************\n");
    printf("\nTentativa %d\n", tentativas);
    printf("Qual é o seu chute?\n");

    scanf("%d", &chute);
    printf("Seu chute foi %d\n\n", chute);

    if(chute < 0) {
        printf("Você não pode chutar números negativos!\n");
        continue;
    }

    acertou = (chute == numerosecreto); /*Se essa condição for validada, a variavel acertou será verdadeira*/
    
    int maior = chute > numerosecreto; 

    if(acertou){
        break;
    }

    else if(maior) {
      printf("Seu chute foi maior que o número secreto\n");
    }

    else {
        printf("Seu chute foi menor que o número secreto\n");
    }

    tentativas++; /*Mesma coisa que: tentativas = tentativas + 1;*/

    double pontos_perdidos = abs(chute - numerosecreto) / (double)2; /*Mesmo que 2.0*/
    pontos = pontos - pontos_perdidos;

  }

  printf("Fim de jogo!\n");

  if(acertou) {
    printf("Você ganhou!\n");
    printf("Você acertou em %d tentativas!\n", tentativas);
    printf("Total de pontos: %.1f\n", pontos);
  }
  else {
    printf("Você perdeu! Tente de novo!\n");
  }
}
