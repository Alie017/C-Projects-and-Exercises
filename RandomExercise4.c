#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/*structs*/

struct position{
	/*position struct*/
	int positionX;
	int positionY;
	
};

struct character{
	/*character struct*/
	struct position characterPosition;
	char characterName;
	
};
/*functions*/
void fillTheChars(struct character characterFillTheChars[],int r,int c,int total);
void display(struct character characterDisplay[],int r,int c,int total);
/*create an array to store characters and get input from user*/
int main(){
	/*variables*/
	struct character chs[20];//character struct array
	int c,r,total;

	
	printf("Enter the sizes of the matrix(col-row): ");
	scanf("%d",&c);
	scanf("%d",&r);
	
	
	printf("Enter the character count: ");
	scanf("%d",&total);
	
	fillTheChars(chs,r,c,total);
	display(chs,r,c,total);	
	
}
/* create random charecter name with ascii code */
void fillTheChars(struct character characterFillTheChars[],int r,int c,int total){

	int i,randN,randR,randC;
	
	
	srand(time(0));
	for(i=0;i<total;i++){
		
		randR = rand() % r;
	    randC = rand() % c;		
		randN = rand() % (91 - 65) + 65; 


		characterFillTheChars[i].characterPosition.positionX=randR;	
		characterFillTheChars[i].characterPosition.positionY=randC;	    
		characterFillTheChars[i].characterName=randN;

					
	}

		
}
/*It shows ¤ (ASCII = -49) if there is no character located in the
cell, otherwise shows the name of the character.*/

void display(struct character characterDisplay[],int r,int c,int total){
	
	int handle=1,i=0,j=0,k=0;
												
	for(i=0;i<r;i++){
		
		for(j=0;j<c;j++){
			
			handle=1;
			
			for(k=0;k<total;k++){
				
				if(characterDisplay[k].characterPosition.positionX == i ){
					
					if(characterDisplay[k].characterPosition.positionY == j){
						
						handle=0;
						printf("%c",characterDisplay[k].characterName);
						
						
					}
					
				}
				
			}
			if(handle){
				
				printf("%c",-49);	
				
			}
				
		}
		
		printf("\n");
		
	}	

}
