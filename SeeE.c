#include <stdio.h>
#include <string.h>

typedef char cTopic[20];
typedef char cChoice[30];
typedef char cQuestion[150];
typedef char User[100];

struct records {
	cTopic cTopic1, cNumber;
	cQuestion cQuestion1;
	cChoice cChoice1, cChoice2, cChoice3, cAnswer;
};

struct Account {
	User Name;
	User Pass; 
};
struct records cRecords[100];
struct Account cAccount[100];

void Records (struct records cRecords[]){
    int i;
    int number = 0;
    char chars[100];
    FILE *Data;
    Data = fopen("Data.txt", "r");
    for (i=0; fgets(chars, 500, Data); i++){ 
		if (i<8){
			if (i%7 == 0){
	            strcpy(cRecords[number].cNumber, chars);
	        }
	        else if (i%7 == 1){
	            strcpy(cRecords[number].cTopic1, chars);
	        }
	        else if (i%7 == 2) {
	            strcpy(cRecords[number].cQuestion1, chars);
	        }   
	        else if (i%7 == 3) {
	            strcpy(cRecords[number].cChoice1, chars);    
	        }
	        else if (i%7 == 4) {
	            strcpy(cRecords[number].cChoice2, chars);        
	        }
	        else if (i%7 == 5) {
	            strcpy(cRecords[number].cChoice3, chars);            
	        }
	        else if (i%7 == 6) {
	            strcpy(cRecords[number].cAnswer, chars);          
				number++;  
	        }
		} else {
			if (i%8 == 0){
	            strcpy(cRecords[number].cNumber, chars);
	        }
	        else if (i%8 == 1){
	            strcpy(cRecords[number].cTopic1, chars);
	        }
	        else if (i%8 == 2) {
	            strcpy(cRecords[number].cQuestion1, chars);
	        }   
	        else if (i%8 == 3) {
	            strcpy(cRecords[number].cChoice1, chars);    
	        }
	        else if (i%8 == 4) {
	            strcpy(cRecords[number].cChoice2, chars);        
	        }
	        else if (i%8 == 5) {
	            strcpy(cRecords[number].cChoice3, chars);            
	        }
	        else if (i%8 == 6) {
	            strcpy(cRecords[number].cAnswer, chars);          
				number++;  
	        }			
		}
		}
	printf("%s\n", cRecords[0].cNumber);
	printf("%s\n", cRecords[0].cTopic1);
    printf("%s\n", cRecords[0].cQuestion1);
    printf("%s\n", cRecords[0].cChoice1);
    printf("%s\n", cRecords[0].cChoice2);
    printf("%s\n", cRecords[0].cChoice3);
}



int menu (){
int nChoice, nInvalid = 1;
printf("[1] Manage Data as an admin\[2] Play as a player\n[3] Exit Program\n\nInput your choice: ");
scanf("%d", &nChoice);
if (nChoice == 1 || nChoice == 2 || nChoice == 3){
	system("cls");
	return nChoice;
}
while (nInvalid==1){
	printf("Input valid input");
	scanf("%d", &nChoice);
	
if (nChoice == 1 || nChoice == 2 || nChoice == 3){
	system("cls");
	return nChoice;
}
}
}

int pPassValid (){
	char cPass[11], cKey[10] = "AdminPass", cAdd[11];
	int i, j, nAsterisks = 0;
	cPass[0] = '\0';
	while (strcmp(cKey,cPass) != 0) {
		nAsterisks = strlen(cPass);
		printf("*****Manage Data*****");
		printf("\nInput Password (9): ");
		for (j=0; j<nAsterisks; j++)
			printf("*");
		scanf("%s", cAdd);
		strcat(cPass,cAdd);
		system("cls"); 
		if (strcmp(cKey,cPass) != 0 && cPass[10] != '\0'){
			for (i=0; i<11; i++)
				cPass[i] = '\0';
		}
	}
	return 1;
}
int mData(struct records cRecords[]){
	int nAct, i=0;
	char ch;
	char strInput [150];
	if (pPassValid() == 1)
	printf("[1] Add a record\n[2] Edit a record\n[3] Delete a record\n[4]Import data\n\nInput direction of activity: ");
	scanf("%d",&nAct);
	if(nAct == 1){
		printf("Input a question: ");
do {
    getchar(); // consume newline character
    scanf(" %c", &ch);
} while (ch != '\n');
		printf("%s",strInput);
	} else if (nAct == 2){
		
	} else {
		
	}
	
}

void pPlay(){
	printf("Play");	
}

int main (){
int i;
Records (cRecords);
if (menu() == 1)
mData(cRecords);
else if (menu() == 2)
pPlay();
else if (menu() == 3)
return 0;
}
