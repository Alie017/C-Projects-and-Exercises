#include <stdio.h>
#include <string.h>
#include <ctype.h>
//I wass waalkinng in thhee Ankarraa.
//Ppeaace is the resullt of retrraining yYyyour miiind to proccess liife as it is ,ratheer than as you think it shhould be .
//ssSpaccce TttrRavel is life - enhancing ,,,,AaaAnd anything that' s life - enhanncing is woOorth doinnng....

void deleteDuplicate(char str[500]){
	///ascii +32 -32
	int i,j=1;
	char newStr[500];
	newStr[0]=str[0];
	
	
	for(i=1;i<strlen(str);i++){
		if(newStr[j-1]==str[i] || newStr[j-1]==str[i]+32 || newStr[j-1]==str[i]-32){

		}else{
			newStr[j]=str[i];
			j++;	
		
		}
	}
	newStr[j]='\0';
	memset(str,0,strlen(str));
	strcpy(str,newStr);
	
}

void rulePunct(char str[500]){
	char newStr[500];
	int i,j=0;

	for(i=0;i<strlen(str);i++){
		
		if(isblank(str[i])){
			if(ispunct(str[i+1])){
				newStr[j]=str[i+1];
				++j;
				newStr[j]=str[i];
				++j;
				i++;
			}else{
				newStr[j]=str[i];
				++j;
			}
			
		}else if(ispunct(str[i])){
			//example jese,joel = jese, joel
			if(isalpha(str[i-1]) && isalpha(str[i+1])){
				newStr[j]=str[i];
				j++;
				newStr[j]=' ';
				j++;
			}else{
				newStr[j]=str[i];
				j++;
			}
			
		}else{
			newStr[j]=str[i];
			j++;
		}	
	
	}
	
	newStr[j]='\0';
	memset(str,0,strlen(str));
	strcpy(str,newStr);
	deleteDuplicate(str);
}


int main(){
	char str[500];
	printf(" Enter a string: ");
	gets(str);
	
	printf("\n\n");
	deleteDuplicate(str);
	printf(" Fixed duplicates:\n%s\n\n",str);
	rulePunct(str);
	printf(" Fixed spaces:\n%s\n\n",str);
	printf(" Final version of the String:\n%s",str);
	
}
