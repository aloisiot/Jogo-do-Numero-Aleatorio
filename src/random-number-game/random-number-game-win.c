#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tentativas;
int recorde;
int rNumber;
int option;
int newGame;
int resp;

int RandomN()
{
	int x;
	srand(time(NULL));
	x = rand()% 10;
	return x;
}


 void Menu()
 {
 	int imp;
	
	printf("\nEscolha uma das opcoes:\n");
	printf("1 Novo jogo \n");
	printf("2 Ver recorde \n");
	printf("3 Limpar recorde \n");
	printf("4 Sair \n\n");
	
	scanf("%d", &imp);
	
	if (imp<= 4 || imp >=1)
 	{
 		option= imp;	
	}
	 else 
	{
	 	Menu();
	}
 }
 
 int NextAction()
{
	int resp = 0;

	printf("\nEscolha uma das opcoes:\n");
	printf("Novo Jogo: 1 \n");
	printf("Menu Principal: 0 \n");
	scanf("%d", &resp);
	
	if (resp==1 || resp == 0)
 	{
		return resp; 
	}
	 else 
	{
	 	NextAction();
	}
}

 
void Game()
{
		
	int chute;
	printf("Escolha um numero entre 0 e 10 \n");
	printf("Insira um numero negativo para sair do jogo \n\n");
	scanf("%d", &chute);
	
	tentativas++;
	
		
	if(chute < 0)
	{
		system("cls");
		printf("\nPartida finalizada. \n\n");
	}
	else if(chute == rNumber)
	{
		system("cls");
		printf("\nPARABENS, VOCE ACERTOU!!! \n\n");
		recorde ++;
	}
	else if (chute < rNumber) 
	{
		printf("\nTente um numero Maior! \n");
		Game();
	}
	else if (chute > rNumber)
	{
		printf("\nTente um numero Menor! \n");
		Game();
	}
	
}
 
void Action(int opt)
 {
 	
 	
  	if(opt == 1 )
 	{
		system("cls");
 		rNumber=RandomN();
		printf("\nUm numero foi sorteado. \nTente adivinha-lo!\n");
		Game();

		while (NextAction()==1)
		{
			rNumber=RandomN();
			printf("\nUm numero foi sorteado. \nTente adivinha-lo!\n");
			Game();
		}
			
		Menu();
		Action(option);
 		
	}
	else if (opt == 2)
	{
		system("cls");
		printf("\nO recorde atual e: %d\n", recorde); 
		Menu();
		Action(option);
		
	}
	else if(opt == 3)
	{
		system("cls");
		recorde=0;
		printf("Recorde zerado.");
		Menu();
		Action(option);
	}
	else if(opt == 4)
	{
		system("cls");
		printf("\nAte a proxima \n");
	}	
 	
 }


int main(){
	
	system("cls");
	printf("\nOla, bem vida(o)! \n");
	
	Menu();
	
	Action(option);
	
	return 0;

}
