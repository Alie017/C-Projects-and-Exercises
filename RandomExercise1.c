#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void checkGuess(int *guess1,int *guess2,int guess,int *flag,int *inc1,int *inc2){
	int prox1,prox2;
	if(*guess1 <=0 || *guess2 <=0){
		printf("\nThere is an invalid guess! Try again.\n");
	}
	else
	{
		prox1=abs(guess-(*guess1));
		prox2=abs(guess-(*guess2));
		printf("\nProxymity of Player 1's guess to the lucky number is: %d\n",prox1);
		printf("Proxymity of Player 2's guess to the lucky number is: %d\n",prox2);
		if(*guess1 == guess && *guess2 == guess){
			printf("Player 2 and Player 1 has guessed the number correctly!.\n");
			(*inc1)++;
			(*inc2)++;
			*flag=1;
		}else if(*guess2 == guess){
			printf("Player 2 has guessed the number correctly!.\n");
			(*inc2)++;
			*flag=1;
		}else if(*guess1 == guess ){
			printf("Player 1 has guessed the number correctly!.\n");
			(*inc1)++;
			*flag=1;
		}
		
		if(prox1>prox2){
			printf("\nPlayer 2's guess is the closest guess to the lucky number");
			(*inc2)++;
		}else if(prox1<prox2){
			printf("\nPlayer 1's guess is the closest guess to the lucky number");
			(*inc1)++;
		}else{
			printf("\nPlayer 1's and Player 2's are the same guesses.");
			(*inc1)++;
			(*inc2)++;
		}
				
	}

}
int main(){
	int playerOneGuess,playerTwoGuess;
	int pro1,pro2;
	int playerOneCount=0,playerTwoCount=0;
	int luckyNum,flag=0;
	
	srand(time(0));
	luckyNum=(rand()%1000)+1;
	
	printf("\n A lucky number has been generated randomly.\n");
	printf(" The lucky number is: %d\n",luckyNum);
	
	do{
		printf("\n********************************\n");
		printf("  Player 1 enter your guess: ");
		scanf("%d",&playerOneGuess);
		printf("  Player 2 enter your guess: ");
		scanf("%d",&playerTwoGuess);
		
		checkGuess(&playerOneGuess,&playerTwoGuess,luckyNum,&flag,&playerOneCount,&playerTwoCount);
		

		
	}while(flag != 1);
	printf("\n\nThe scores are\n");
	printf("Player 1: %d\n",playerOneCount);
	printf("Player 2: %d",playerTwoCount);
}
