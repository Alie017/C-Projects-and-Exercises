#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int position[]={0,0};
//PREPARE DÝSPLAY MATRÝX
void prepareDisplayMatrix(int x,int y,char displayMatrix[20][30]){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			displayMatrix[i][j]=-78;
		}
	}
	displayMatrix[0][0]='P';
	displayMatrix[0][1]=-80;
	displayMatrix[1][0]=-80;
	displayMatrix[1][1]=-80;
}
//PREPARE PLACEMENT MATRÝX
void preparePlacementMatrix(int x,int y,char placementMatrix[20][30],int tree,int enemy){
	int i=0,j=0;
	int randomPositon1,randomPositon2;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			placementMatrix[i][j]=' ';
		}
	}
	i=0;
	while(i<tree){

		srand(time(NULL));
		randomPositon1 = rand() % x; 
		randomPositon2 = rand() % y;
		if(randomPositon1 !=0 && randomPositon2 !=0){
			if(placementMatrix[randomPositon1][randomPositon2]==' '){
				placementMatrix[randomPositon1][randomPositon2]='T';
				i++;	
			}
						
		}
	}
	i=0;
	while(i<enemy){

		srand(time(NULL));
		randomPositon1 = rand() % x; 
		randomPositon2 = rand() % y;
		if(randomPositon1 !=0 && randomPositon2 !=0){
			if(placementMatrix[randomPositon1][randomPositon2]==' '){
				placementMatrix[randomPositon1][randomPositon2]='E';
				i++;	
			}
						
		}	
	}
}
//PREPARE THE GAMME
void prepareTheGame(int x,int y,char displayMatrix[20][30],char placementMatrix[20][30],int tree,int enemy){
	
	prepareDisplayMatrix(x,y,displayMatrix);
	preparePlacementMatrix(x,y,placementMatrix,tree,enemy);
	
}
//DISPLAY
void display(int x,int y,char displayMatrix[20][30]){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			printf("%c",displayMatrix[i][j]);
		}
		printf("\n");
	}

}
//DISPLAY GOD MODE
void displayGodMode(int x,int y,char displayMatrix[20][30],char placementMatrix[20][30]){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(displayMatrix[i][j]==-78){
				if(placementMatrix[i][j]==' '){
					printf("%c",-80);
				}else{
					printf("%c",placementMatrix[i][j]);
				}
			}else{
				printf("%c",displayMatrix[i][j]);	
			}
		}
		printf("\n");
	}

}
//FIGHT WÝTH ENEMY
void fightWithTheEnemy(int x,int y,char placementMatrix[20][30],char displayMatrix[20][30],char inputChar,int *ref){
	if(inputChar == 'h'){

		if(placementMatrix[position[0]+1][position[1]]=='E'){
			placementMatrix[position[0]+1][position[1]]=' ';
			displayMatrix[position[0]+1][position[1]]=-80;
			(*ref)--;
		}else if(placementMatrix[position[0]][position[1]+1]=='E'){
			placementMatrix[position[0]][position[1]+1]=' ';
			displayMatrix[position[0]][position[1]+1]=-80;
			(*ref)--;			
		}else if(placementMatrix[position[0]][position[1]-1]=='E'){
			placementMatrix[position[0]][position[1]-1]=' ';
			displayMatrix[position[0]][position[1]-1]=-80;
			(*ref)--;			
		}else if(placementMatrix[position[0]-1][position[1]]=='E'){
			placementMatrix[position[0]-1][position[1]]=' ';
			displayMatrix[position[0]-1][position[1]]=-80;
			(*ref)--;			
		}else if(placementMatrix[position[0]-1][position[1]-1]=='E'){
			placementMatrix[position[0]-1][position[1]-1]=' ';
			displayMatrix[position[0]-1][position[1]-1]=-80;
			(*ref)--;				
		}else if(placementMatrix[position[0]+1][position[1]-1]=='E'){
			placementMatrix[position[0]+1][position[1]-1]=' ';
			displayMatrix[position[0]+1][position[1]-1]=-80;
			(*ref)--;				
		}else if(placementMatrix[position[0]+1][position[1]+1]=='E'){
			placementMatrix[position[0]+1][position[1]+1]=' ';
			displayMatrix[position[0]+1][position[1]+1]=-80;
			(*ref)--;				
		}else if(placementMatrix[position[0]-1][position[1]+1]=='E'){
			placementMatrix[position[0]-1][position[1]+1]=' ';
			displayMatrix[position[0]-1][position[1]+1]=-80;
			(*ref)--;				
		}
		
	}
	
}
//UPDATE DÝSPLAY MATRÝX
void updateDisplayMatrix(int x,int y,char displayMatrix[20][30],char placementMatrix[20][30],char inputChar){
	int i,j;
	if(inputChar=='w'){
		if(placementMatrix[position[0]-1][position[1]]=='E' || placementMatrix[position[0]-1][position[1]] == 'T'){
			if(placementMatrix[position[0]-1][position[1]]=='E'){
				displayMatrix[position[0]-1][position[1]]='E';
			}else{
				displayMatrix[position[0]-1][position[1]]='T';
			}			
		}else{
			if(!(position[0]-1<0)){
				displayMatrix[position[0]][position[1]]=-80;
				position[0]-=1;
				displayMatrix[position[0]][position[1]]='P';
			}
			
			for(i=position[0]-1;i<position[0]+2;i++){
				for(j=position[1]-1;j<position[1]+2;j++){
					if(i>=0 && i<x){
						if(j>=0 && j<y){
							
							if(placementMatrix[i][j]==' '&& displayMatrix[i][j]==-78){
								displayMatrix[i][j]=-80;	
							}else{
								if(placementMatrix[i][j]=='T'){
									displayMatrix[i][j]='T';
								}else if(placementMatrix[i][j]=='E' ){
									displayMatrix[i][j]='E';
								}
							}
						}
					}
				}

			}

				
		}
	}else if(inputChar=='a'){
		if(placementMatrix[position[0]][position[1]-1]=='E' || placementMatrix[position[0]][position[1]-1]=='T'){
			if(placementMatrix[position[0]][position[1]-1]=='E'){
				displayMatrix[position[0]][position[1]-1]='E';
			}else{
				displayMatrix[position[0]][position[1]-1]='T';
			}
		}else{
			if(!(position[1]-1<0)){
				displayMatrix[position[0]][position[1]]=-80;
				position[1]-=1;
				displayMatrix[position[0]][position[1]]='P';
			}
			for(i=position[0]-1;i<position[0]+2;i++){
				for(j=position[1]-1;j<position[1]+2;j++){
					if(i>=0 && i<x){
						if(j>=0 && j<y){
							if(placementMatrix[i][j]==' '&& displayMatrix[i][j]==-78){
								displayMatrix[i][j]=-80;	
							}else{
								if(placementMatrix[i][j]=='T'){
									displayMatrix[i][j]='T';
								}else if(placementMatrix[i][j]=='E' ){
									displayMatrix[i][j]='E';
								}
							}
						}
					}
				}

			}	
		}		
	}else if(inputChar=='s'){
		if(placementMatrix[position[0]+1][position[1]]=='E' || placementMatrix[position[0]+1][position[1]]=='T'){
			if(placementMatrix[position[0]+1][position[1]]=='E'){
				displayMatrix[position[0]+1][position[1]]='E';
			}else{
				displayMatrix[position[0]+1][position[1]]='T';
			}
		}else{
			if(!(position[0]+1>x-1)){
				displayMatrix[position[0]][position[1]]=-80;
				position[0]+=1;
				displayMatrix[position[0]][position[1]]='P';
			}
			for(i=position[0]-1;i<position[0]+2;i++){
				for(j=position[1]-1;j<position[1]+2;j++){
					if(i>=0 && i<x){
						if(j>=0 && j<y){
							if(placementMatrix[i][j]==' '&& displayMatrix[i][j]==-78){
								displayMatrix[i][j]=-80;	
							}else{
								if(placementMatrix[i][j]=='T'){
									displayMatrix[i][j]='T';
								}else if(placementMatrix[i][j]=='E' ){
									displayMatrix[i][j]='E';
								}
							}
						}
					}
				}

			}			
		}		
	}else if(inputChar=='d'){
		if(placementMatrix[position[0]][position[1]+1]=='E' || placementMatrix[position[0]][position[1]+1]=='T'){
			if(placementMatrix[position[0]][position[1]+1]=='E'){
				displayMatrix[position[0]][position[1]+1]='E';
			}else{
				displayMatrix[position[0]][position[1]+1]='T';
			}
		}else{
			if(!(position[1]+1>y-1)){
				displayMatrix[position[0]][position[1]]=-80;
				position[1]+=1;
				displayMatrix[position[0]][position[1]]='P';
			}
			for(i=position[0]-1;i<position[0]+2;i++){
				for(j=position[1]-1;j<position[1]+2;j++){
					if(i>=0 && i<x){
						if(j>=0 && j<y){
							if(placementMatrix[i][j]==' '&& displayMatrix[i][j]==-78){
								displayMatrix[i][j]=-80;	
							}else{
								if(placementMatrix[i][j]=='T'){
									displayMatrix[i][j]='T';
								}else if(placementMatrix[i][j]=='E' ){
									displayMatrix[i][j]='E';
								}
							}

						}
					}
				}

			}
		}		
	} 
}

//UPDATE
void update(int x,int y,char displayMatrix[20][30],char placementMatrix[20][30],int enemy){
	char ch;
	int flag=0,godMode=0;
	prepareTheGame(x,y,displayMatrix,placementMatrix,6,enemy);
	
	do{
		
		if(godMode==0){
			system("cls");
			display(x,y,displayMatrix);	
		}else{
			system("cls");
			displayGodMode(x,y,displayMatrix,placementMatrix);	
		}
		ch=getch();
		if(ch=='c'){
			if(godMode==0){
				godMode=1;
			}else{
				godMode=0;
			}
			
		}else if(ch == 'q' || enemy == 0){
			flag=-1;
		}else{

			updateDisplayMatrix(x,y,displayMatrix,placementMatrix,ch);	
			fightWithTheEnemy(x,y,placementMatrix,displayMatrix,ch,&enemy);
			
		}
		
			
		

		
	}while(flag != -1);
}

int main(){

	int i,j;
	char displayMatrix[20][30];
	char placementMatrix[20][30];
	update(20,30,displayMatrix,placementMatrix,6);

}

