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

struct records cRecords[100];

void records (struct records cRecords[], int *Number){
	printf("%s", cRecords[0].cQuestion1);
	printf("%d", *Number);
}

int numCount(struct records cRecords[], int *Number) {
    int i, number = 0;
    for (i = 0; i < 100; i++) {
        if (strlen(cRecords[i].cQuestion1) > 0) {
            number++;
        }
    }
    *Number = number;
    return number;
}

void ImportRecords (struct records cRecords[], int *Number){
    int i;
    int number = 0;
    char chars[150];
    FILE *Data;
    Data = fopen("sample-records.txt", "r");
    for (i=0; fgets(chars, 150, Data); i++){ 
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
	            strcpy(cRecords[number].cTopic1, chars);
	        }
	        else if (i%8 == 1){
	            strcpy(cRecords[number].cNumber, chars);
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
	fclose(Data);
}

int menu (){
    int nChoice, nInvalid = 1;
    printf("[1] Manage Data as an admin\n[2] Play as a player\n[3] Exit Program\n\nInput your choice: ");
    scanf("%d", &nChoice);
    if (nChoice == 1 || nChoice == 2 || nChoice == 3){
        system("cls");
        nInvalid = 0;
        return nChoice;
    } 
    while (nInvalid==1){
        printf("Input valid input: ");
        scanf("%d", &nChoice);
        
        if (nChoice == 1 || nChoice == 2 || nChoice == 3){
            system("cls");
            nInvalid = 0;
            return nChoice;
        }
    }
    return 0;
}


int pPassValid (){
    char cPass[11] = "", cKey[10] = "AdminPass", cAdd[11];
    int i, j, nAsterisks = 0;
    fflush(stdin);
    do {
        printf("*****Manage Data*****");
        printf("\nInput Password (9): ");
        for (j=0; j<nAsterisks; j++)
            printf("*");
        scanf("%s", cAdd);
        nAsterisks += strlen(cAdd);
        strcat(cPass,cAdd);
        system("cls"); 
        if (strlen(cPass) >= 9) {
            if (strcmp(cKey, cPass) == 0) {
                return 1;
            }
            for (i=0; i<11; i++)
                cPass[i] = '\0';
            nAsterisks = 0;
        }
    } while (1);
}


int checkRecord(struct records cRecords[], char strInput[], char Answer[]) {
    int i;
    for (i = 0; i < 7; i++) {
        if (strcmp(strInput, cRecords[i].cQuestion1) == 0 && strcmp(Answer, cRecords[i].cAnswer))
			return 1;
		else
			return 0;
	}
	return 0;
}

void inputRecord (struct records cRecords[], int Number, char strInput[], char Answer[]){
	cTopic Topic;
	cChoice Choice1, Choice2, Choice3;
		printf("Input the topic of the problem: ");
			scanf("%s", cRecords[Number].cTopic1);
		printf("Enter The first choice: ");
			scanf("%s", cRecords[Number].cChoice1);
		printf("Enter the second choice: ");
			scanf("%s", cRecords[Number].cChoice2);
		printf("Enter the third choice: ");
			scanf("%s", cRecords[Number].cChoice3); 
			strcpy(cRecords[Number].cQuestion1, strInput);
			strcpy(cRecords[Number].cAnswer, Answer);
	/*FILE *Data;
    Data = fopen("Data.txt", "a");
    
		printf("Input the topic of the problem: ");
			scanf("%s", Topic);
		printf("Enter The first choice: ");
			scanf("%s", Choice1);
		printf("Enter the second choice: ");
			scanf("%s", Choice2);
		printf("Enter the third choice: ");
			scanf("%s", Choice3);
						
		fprintf(Data, "\n\n%s\n", Topic);
		fprintf(Data, "%d", Number+1);
		fprintf(Data, "%s", strInput);
		fprintf(Data, "%s\n%s\n%s\n", Choice1, Choice2, Choice3);
		fprintf(Data, "%s", Answer);
		
	fclose(Data);*/
}

void editRecord(struct records cRecords[], int *Number) {
    int nChoice, i, j, nTopicCount = 0, dChoice, pChoice;
    cTopic Topic;
    cQuestion Question;
    cChoice Choice1, Choice2, Choice3, Answer;
    char cTopicList[100][20], chars;
    FILE *Data;
    Data = fopen("Data.txt", "r");

    printf("Topic list:\n");
    for (i = 0; i < *Number; i++) {
        int isUnique = 1;
        for (j = 0; j < nTopicCount; j++) {
            if (strcmp(cRecords[i].cTopic1, cTopicList[j]) == 0) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            strcpy(cTopicList[nTopicCount], cRecords[i].cTopic1);
            nTopicCount++;
        }
    }
    for (i = 0; i < nTopicCount; i++) {
        printf("%d. %s\n", i + 1, cTopicList[i]);
    }
    printf("\nEnter the number of the topic you want to edit: ");
    scanf("%d", &dChoice);
    
    printf("Questions for topic:\n", cTopicList[dChoice-1]);
    int foundQuestions = 0;
    for (i = 0; i < *Number; i++) {
        if (strcmp(cRecords[i].cTopic1, cTopicList[dChoice-1]) == 0) {
            printf("- %s\n", cRecords[i].cQuestion1);
            foundQuestions = 1;
        }
    }
    if (!foundQuestions) {
        printf("No questions found for topic '%s'.\n", cTopicList[dChoice-1]);
        return;
    }

    printf("\nDo you want to replace a question?\n[1] Yes\n[2] No\n"); 
    scanf("%d", &nChoice);
    if (nChoice == 1) {
        printf("Enter the number of the question to replace: ");
        scanf("%d", &dChoice);
        if (dChoice < 1 || dChoice > *Number) {
            printf("Invalid question number.\n");
            return;
        }
        printf("Enter the new question: ");
        scanf(" %[^\n]s", cRecords[dChoice-1].cQuestion1);
        printf("Enter the new first choice: ");
        scanf("%s", cRecords[dChoice-1].cChoice1);
        printf("Enter the new second choice: ");
        scanf("%s", cRecords[dChoice-1].cChoice2);
        printf("Enter the new third choice: ");
        scanf("%s", cRecords[dChoice-1].cChoice3);
        printf("Enter the new answer: ");
        scanf("%s", cRecords[dChoice-1].cAnswer);
        printf("Question has been replaced.\n");
    } else {
        printf("Question not replaced.\n");
        return;
    }
}

int mData(struct records cRecords[], int *Number){
	int nAct, i=0;
	cQuestion strInput; 
	cChoice Answer;
	if (pPassValid() == 1)
	do {
		printf("[1] Add a record\n[2] Edit a record\n[3] Delete a record\n[4] Import data\n\nInput direction of activity: ");
		scanf("%d",&nAct);
		system("cls");
		getchar();
		if(nAct == 1){
		printf("Input a question: ");
		fgets (strInput, 150, stdin);
		printf("Input the answer to the question: " );
		scanf("%s", Answer);
		if (checkRecord(cRecords, strInput, Answer) == 1)
			printf("It is already listed");
		else{
			inputRecord (cRecords, *Number, strInput, Answer);
		}
	} else if (nAct == 2){	
		editRecord (cRecords, Number);
	} else if (nAct == 3){
	} else if (nAct == 4){
		ImportRecords (cRecords, Number);
	}
	} while (nAct < 1 || nAct >4);
}

void pPlay(){
	printf("Play");	
}

int main (){
int i, Number = 0, menuVal; 
while (menuVal!=3) {
numCount (cRecords, &Number);
records (cRecords, &Number);
menuVal = menu();
if (menuVal == 1)
mData(cRecords, &Number);
else if (menuVal == 2)
pPlay();
system("cls");	
}
}
