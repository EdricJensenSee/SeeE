#include <stdio.h>
#include <string.h>
#include <time.h>

typedef char cTopic[40];
typedef char cChoice[30];
typedef char cQuestion[150];
typedef char Users[100];

struct records {
	cTopic cTopic1, cNumber, prevRecord;
	cQuestion cQuestion1;
	cChoice cChoice1, cChoice2, cChoice3, cAnswer;
	int nNumber;
};

struct players {
	Users pName;
	int pScore;
};

struct records cRecords[100];
struct players cPlayers[100];

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

int playerCount(struct players cPlayers[], int *pNumber) {
    int i, number = 0;
    for (i = 0; i < 100; i++) {
        if (strlen(cPlayers[i].pName) > 0) {
            number++;
        }
    }
    *pNumber = number;
}

void ImportRecords(struct records cRecords[], int *Number) {
    int i, j, counter = 0;
    int number = *Number, nNum;
    char chars[150], fileName[50];
    FILE *Data;
    printf("Input file: ");
	do {
        scanf("%s", fileName);
        Data = fopen(fileName, "r");
        if (Data == NULL) {
            printf("Invalid file name. Please try again\nExport File:");        
        }
    } while (Data == NULL);
    for (i=0; fgets(chars, 150, Data); i++) { 
        if (i < 8) {
            if (i % 7 == 0) {
                strcpy(cRecords[number].cTopic1, chars);
            } else if (i % 7 == 1) {
                strcpy(cRecords[number].cNumber, chars);
            } else if (i % 7 == 2) {
                strcpy(cRecords[number].cQuestion1, chars);
            } else if (i % 7 == 3) {
                strcpy(cRecords[number].cChoice1, chars);    
            } else if (i % 7 == 4) {
                strcpy(cRecords[number].cChoice2, chars);        
            } else if (i % 7 == 5) {
                strcpy(cRecords[number].cChoice3, chars);            
            } else if (i % 7 == 6) {
                if (chars[0] != '\n') {
             	chars[strcspn(chars, "\n")] = '\0';
                strcpy(cRecords[number].cAnswer, chars);        
                number++;               	
				}
                else
                    i -= 6;   
            }
        } else {
            if (i % 8 == 0) {
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
                if (chars[0] != '\n') {
					chars[strcspn(chars, "\n")] = '\0';   
					strcpy(cRecords[number].cAnswer, chars);        
                    number++;
				}
                else 
                    i-=7;     
            }       
		}
    }
    *Number = number;
    fclose(Data);
}

void assignTopicNumbers(struct records cRecords[], int *Number) {
    int i, j, topicNum, matchingTopics[100], matchingRecords[100], numMatches1 = 0, numMatches2 = 0;
    for (i = 0; i < *Number; i++) {
        int isUnique = 1;
        for (j = i - 1; j >= 0; j--) {
            if (strcmp(cRecords[i].cTopic1, cRecords[j].cTopic1) == 0) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            matchingTopics[numMatches1++] = i;
        }
    }

    for (i = 0; i < numMatches1; i++) {
        int counter = 0;
        numMatches2 = 0;
        for (j = 0; j < *Number; j++) {
            if (strcmp(cRecords[j].cTopic1, cRecords[matchingTopics[i]].cTopic1) == 0) {
                matchingRecords[numMatches2++] = j;
            }
        }
        for (j = 0; j < numMatches2; j++){
            cRecords[matchingRecords[j]].nNumber = counter+1;
            counter++;
        }
    }
}


void ExportRecords(struct records cRecords[], int *Number) {
    FILE *Data;
    char fileName[50];
    int i;
    printf("Export file: ");
    do {
        scanf("%s", fileName);
        Data = fopen(fileName, "a");
        if (Data == NULL) {
            printf("Invalid file name. Please try again\nExport File:");
        }
    } while (Data == NULL);
    printf("%d", *Number);
    assignTopicNumbers(cRecords, Number);
    for (i=0; i<*Number; i++){
        fprintf(Data, "%s", cRecords[i].cTopic1);
        fprintf(Data, "%d\n", cRecords[i].nNumber); 
        fprintf(Data, "%s", cRecords[i].cQuestion1);
        fprintf(Data, "%s%s%s", cRecords[i].cChoice1, cRecords[i].cChoice2, cRecords[i].cChoice3);
        fprintf(Data, "%s\n", cRecords[i].cAnswer);
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
}

void editRecord(struct records cRecords[], int *Number) {
	int i, j, choice = '\0', recordNum, fieldNum, topicNum, matchingTopics[100], matchingRecords[100], numMatches = 0;
	int topicCount = 0, currNum = 1;
    char topic[20], newValue[150];

printf("Available Topics:\n");
for (i = 0; i < *Number; i++) {
    int isUnique = 1;
    for (j = i - 1; j >= 0; j--) {
        if (strcmp(cRecords[i].cTopic1, cRecords[j].cTopic1) == 0) {
            isUnique = 0;
            break;
        }
    }
    if (isUnique) {
        matchingTopics[numMatches++] = i;
        printf("[%d] %s\n", currNum, cRecords[i].cTopic1);
        currNum++;
    }
}

printf("Choose a topic to edit (enter the number): ");
scanf("%d", &topicNum);

topicNum = matchingTopics[topicNum - 1];

numMatches = 0;
for (i = 0; i < *Number; i++) {
    if (strcmp(cRecords[i].cTopic1, cRecords[topicNum].cTopic1) == 0) {
        matchingRecords[numMatches++] = i;
    }
}

printf("\nRecords in %s\n", cRecords[topicNum].cTopic1);
for (i = 0; i < numMatches; i++) {
    printf("[%d] %s\n", i+1, cRecords[matchingRecords[i]].cQuestion1);
}

printf("Choose a record to edit: ");
scanf("%d", &choice);
recordNum = matchingRecords[choice - 1];

printf("\nCurrent Record:\n");
printf("Topic: %s\n", cRecords[recordNum].cTopic1);
printf("Question: %s\n", cRecords[recordNum].cQuestion1);
printf("Choice 1: %s\n", cRecords[recordNum].cChoice1);
printf("Choice 2: %s\n", cRecords[recordNum].cChoice2);
printf("Choice 3: %s\n", cRecords[recordNum].cChoice3);
printf("Answer: %s\n\n", cRecords[recordNum].cAnswer);


printf("Which field do you want to modify?\n");
printf("[1] Topic\n");
printf("[2] Question\n");
printf("[3] Choice 1\n");
printf("[4] Choice 2\n");
printf("[5] Choice 3\n");
printf("[6] Answer\n");
printf("Enter field number: ");
scanf("%d", &fieldNum);
getchar();
printf("Enter new value: ");
fgets (newValue, 150, stdin);

switch (fieldNum) {
    case 1:
        strcpy(cRecords[recordNum].cTopic1, newValue);
        break;
    case 2:
        strcpy(cRecords[recordNum].cQuestion1, newValue);
        break;
    case 3:
        strcpy(cRecords[recordNum].cChoice1, newValue);
    case 4:
         strcpy(cRecords[recordNum].cChoice2, newValue);
        break;
    case 5:
		strcpy(cRecords[recordNum].cChoice3, newValue);
        break;
    case 6:
		strcpy(cRecords[recordNum].cAnswer, newValue);
        break;
    default:
        printf("Invalid choice.\n");
        break;
}
}

void deleteRecord(struct records cRecords[], int *Number) {
    char strInput[150], strNumber[10];
 	int nConfirm, nDel = -1;
    int i, j, choice = '\0', recordNum, fieldNum, topicNum, matchingTopics[100], matchingRecords[100], numMatches = 0;;
	int topicCount = 0, currNum = 1;
    char topic[20];

printf("Available Topics:\n");
for (i = 0; i < *Number; i++) {
    int isUnique = 1;
    for (j = i - 1; j >= 0; j--) {
        if (strcmp(cRecords[i].cTopic1, cRecords[j].cTopic1) == 0) {
            isUnique = 0;
            break;
        }
    }
    if (isUnique) {
        matchingTopics[numMatches++] = i;
        printf("[%d] %s\n", currNum, cRecords[i].cTopic1);
        currNum++;
    }
}

printf("Choose a topic to delete: ");
scanf("%d", &topicNum);

topicNum = matchingTopics[topicNum - 1];

numMatches = 0;
for (i = 0; i < *Number; i++) {
    if (strcmp(cRecords[i].cTopic1, cRecords[topicNum].cTopic1) == 0) {
        matchingRecords[numMatches++] = i;
    }
}

printf("\nRecords in %s\n", cRecords[topicNum].cTopic1);
for (i = 0; i < numMatches; i++) {
    printf("[%d] %s\n", i+1, cRecords[matchingRecords[i]].cQuestion1);
}

printf("Choose a record to delete: ");
scanf("%d", &choice);
recordNum = matchingRecords[choice - 1];

    for (i = 0; i < *Number; i++) {
	        if (strcmp(cRecords[recordNum].cTopic1, cRecords[i].cTopic1) == 0) {
	            nDel = recordNum;
        }
    }
    if (nDel >= 0) {
        printf("\nAre you sure you want to delete this question? (1 = yes, 0 = no): ");
        scanf("%d", &nConfirm);
        if (nConfirm == 1) {
            for (i = nDel; i < *Number - 1; i++) {
                strcpy(cRecords[i].cTopic1, cRecords[i + 1].cTopic1);
                strcpy(cRecords[i].cNumber, cRecords[i + 1].cNumber);
                strcpy(cRecords[i].cQuestion1, cRecords[i + 1].cQuestion1);
                strcpy(cRecords[i].cChoice1, cRecords[i + 1].cChoice1);
                strcpy(cRecords[i].cChoice2, cRecords[i + 1].cChoice2);
                strcpy(cRecords[i].cChoice3, cRecords[i + 1].cChoice3);
                strcpy(cRecords[i].cAnswer, cRecords[i + 1].cAnswer);
            }
            strcpy(cRecords[*Number - 1].cTopic1, "");
            strcpy(cRecords[*Number - 1].cNumber, "");
            strcpy(cRecords[*Number - 1].cQuestion1, "");
            strcpy(cRecords[*Number - 1].cChoice1, "");
            strcpy(cRecords[*Number - 1].cChoice2, "");
            strcpy(cRecords[*Number - 1].cChoice3, "");
            strcpy(cRecords[*Number - 1].cAnswer, "");
            (*Number)--;
            printf("\nRecord successfully deleted.\n");
        } else {
            printf("\nRecord not deleted.\n");
        }
    } else {
        printf("\nQuestion number not found for topic %s.\n");
    }
}

int mData(struct records cRecords[], int *Number){
	int nAct, i=0;
	cQuestion strInput; 
	cChoice Answer;
	if (pPassValid() == 1)
	do {
		system("cls");
		printf("[1] Add a record\n[2] Edit a record\n[3] Delete a record\n[4] Import data\n[5] Export data\n[6] Return to main menu\n\nInput direction of activity: ");
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
		deleteRecord (cRecords, Number);
	} else if (nAct == 4){
		ImportRecords (cRecords, Number);
	} else if (nAct == 5){
		ExportRecords (cRecords, Number);
	} 
	} while (nAct >0 && nAct <6);
}

void Play(struct records cRecords[], int* Number) {
    int i, j, currNum, randNum, pCount, recordNum, fieldNum, topicNum, matchingTopics[100], matchingRecords[100], numMatches = 0;
    char ans[30];
    int Continue = 1, Return;
	playerCount(cPlayers, &pCount);
    printf("Input Player Name: ");
    scanf("%s", cPlayers[pCount].pName);
    getchar();
    do{
    	printf("[1] Continue\n[2] End Game");
    	scanf("%d", &Return);
    	if (Return == 1){
    	numMatches=0;
		printf("Available Topics:\n");
    	currNum = 1;
    	for (i = 0; i < *Number; i++) {
        int isUnique = 1;
        for (j = i - 1; j >= 0; j--) {
            if (strcmp(cRecords[i].cTopic1, cRecords[j].cTopic1) == 0) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            matchingTopics[numMatches++] = i;
            printf("[%d] %s\n", currNum, cRecords[i].cTopic1);
            currNum++;
        }
    	}
    	printf("Choose a topic to answer a random question from: ");
    	scanf("%d", &topicNum);
    	topicNum = matchingTopics[topicNum - 1];
		numMatches = 0;
    	for (i = 0; i < *Number; i++) {
        if (strcmp(cRecords[i].cTopic1, cRecords[topicNum].cTopic1) == 0) {
            matchingRecords[numMatches++] = i;
        }
    	}
    	randNum = rand() % numMatches;
    	system("cls");
    	printf("Points:%d\nAnswer the Question: %s\n", cPlayers[pCount].pScore, cRecords[matchingRecords[randNum]].cQuestion1);
    	scanf("%s", ans);
    	if (strcmp(cRecords[matchingRecords[randNum]].cAnswer, ans) == 0){
    		printf("Correct!\n");
    		cPlayers[pCount].pScore+=1;
    		system("pause");
		} else {
			printf("Incorrect\n");
			system("pause");
		}	
	} else {
		printf("YOUR FINAL SCORE: %d\n", cPlayers[pCount].pScore);
		Continue = 0;
		system("pause");
	}
	} while (Continue);
}

	
void pPlay(struct records cRecords[], int *Number){
	int nDirection;
	printf("[1] Play\n[2] View Scores\n[3] Exit\n\nInput Direction of Activity:");	
	scanf("%d", &nDirection);
	if (nDirection == 1 ){
		Play(cRecords, Number);
	} else if (nDirection == 2){
		
	} else if (nDirection ==3){
		
	}
}

int main (){
time_t t;
srand((unsigned) time( & t));
int i, Number = 0, menuVal; 
while (menuVal!=3) {
numCount (cRecords, &Number);
records (cRecords, &Number);
menuVal = menu();
if (menuVal == 1)
mData(cRecords, &Number);
else if (menuVal == 2)
pPlay(cRecords, &Number);
system("cls");	
}
}
