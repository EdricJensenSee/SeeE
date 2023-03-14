#include <stdio.h>
#include <string.h>

typedef char cTopic[20];
typedef char cChoice[30];
typedef char cQuestion[150];
typedef char User[100];

struct records {
	cTopic cTopic1;
	cQuestion cQuestion1;
	cChoice cChoice1, cChoice2, cChoice3, cAnswer;
};

struct Account {
	User Name;
	User Pass; 
};
struct records cRecords[20];
struct Account cAccount[100];

void providedRecords (struct records cRecords[]){
int i;
FILE *topics, *questions, *choices1, *choices2, *choices3, *answer;
topics = fopen("Topic.txt", "r");
questions = fopen("Questions.txt", "r");
choices1 = fopen("Choices1.txt", "r");
choices2 = fopen("Choices2.txt", "r");
choices3 = fopen("Choices3.txt", "r");
answer = fopen("Answer.txt", "r");

char chars[100];
    for (i=0; fscanf(topics, "%[^\n]%*c", chars) == 1; i++){
		if (i%6 == 0)
			strcpy(cRecords[i].cTopic1, chars);
		if (i%6 == 1) 
			strcpy(cRecords[i].cQuestions, chars);
		if (i%6 == 2) 
			strcpy(cRecords[i].cChoice1, chars);
		if (i%6 == 3) 
			strcpy(cRecords[i].cChoice2, chars);
		if (i%6 == 4) 
			strcpy(cRecords[i].cChoice3, chars);
    		
    		
	}
    for (i = 0; fscanf(questions, "%[^\n]%*c", cRecords[i].cQuestion1) == 1; i++) {
    }
    for (i = 0; fscanf(choices1, "%[^\n]%*c", cRecords[i].cChoice1) == 1; i++) {
    }
    for (i = 0; fscanf(choices2, "%[^\n]%*c", cRecords[i].cChoice2) == 1; i++) {
    }
    for (i = 0; fscanf(choices3, "%[^\n]%*c", cRecords[i].cChoice3) == 1; i++) {
    }
    for (i = 0; fscanf(answer, "%[^\n]%*c", cRecords[i].cAnswer) == 1; i++) {
    }
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
	providedRecords (cRecords);
if (menu() == 1)
mData(cRecords);
else if (menu() == 2)
pPlay();
else if (menu() == 3)
return 0;
}
