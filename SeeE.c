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
struct records cRecords[7];
struct Account cAccount[100];

void Records (struct records cRecords[], int *Number){
    int i;
    int number = 0;
    char chars[100];
    FILE *Data;
    Data = fopen("Data.txt", "r");
    for (i=0; fgets(chars, 500, Data); i++){ 
		if (i<8){
			if (i%7 == 0){
	            strcpy(cRecords[number].cTopic1, chars);
	        }
	        else if (i%7 == 1){
	            strcpy(cRecords[number].cNumber, chars);
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
			*Number = number+1;
		}
}

int menu (){
int nChoice, nInvalid = 1;
printf("[1] Manage Data as an admin\n[2] Play as a player\n[3] Exit Program\n\nInput your choice: ");
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

int checkRecord(struct records cRecords[], char strInput[], char Answer[]) {
    int i;
    for (i = 0; i < 7; i++) {
        if (strcmp(strInput, cRecords[i].cQuestion1) == 0 && strcmp(Answer, cRecords[i].cAnswer))
			return 1;
		else
			return 0;
	}
}

void inputRecord (struct records cRecords[], int Number){
		printf("Input the topic of the problem: ");
			scanf("%s", cRecords[Number].cTopic1);
		printf("Enter The first choice: ");
			scanf("%s", cRecords[Number].cChoice1);
		printf("Enter the second choice: ");
			scanf("%s", cRecords[Number].cChoice2);
		printf("%Enter the third choice: ");
			scanf("%s", cRecords[Number].cChoice3);
}

int mData(struct records cRecords[], int *Number){
	int nAct, i=0;
	cQuestion strInput; 
	cChoice Answer;
	if (pPassValid() == 1)
	printf("[1] Add a record\n[2] Edit a record\n[3] Delete a record\n[4]Import data\n\nInput direction of activity: ");
		scanf("%d",&nAct);
	if(nAct == 1){
		getchar();
		printf("Input a question: ");
		fgets (strInput, 150, stdin);
		printf("Input the answer to the question: " );
		scanf("%s", Answer);
		if (checkRecord(cRecords, strInput, Answer) == 1)
			printf("It is already listed");
		else{
			strcpy(cRecords[*Number].cQuestion1, strInput);
			strcpy(cRecords[*Number].cAnswer, Answer);
			inputRecord (cRecords, *Number);
		}
			
	} else if (nAct == 2){
		
	} else {
		
	}
}

void pPlay(){
	printf("Play");	
}

int main (){
int i, Number; 

Records (cRecords, &Number);
if (menu() == 1)
mData(cRecords, &Number);
else if (menu() == 2)
pPlay();
else if (menu() == 3)
return 0;
}
