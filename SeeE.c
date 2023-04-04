#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>

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
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }  
                strcpy(cRecords[number].cTopic1, chars);
            } else if (i % 7 == 1) {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }  
                strcpy(cRecords[number].cNumber, chars);
            } else if (i % 7 == 2) {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }  
                strcpy(cRecords[number].cQuestion1, chars);
            } else if (i % 7 == 3) {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }   
                strcpy(cRecords[number].cChoice1, chars);    
            } else if (i % 7 == 4) {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }   
                strcpy(cRecords[number].cChoice2, chars);        
            } else if (i % 7 == 5) {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }  
                strcpy(cRecords[number].cChoice3, chars);            
            } else if (i % 7 == 6) {
                if (chars[0] != '\n') {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }  
                strcpy(cRecords[number].cAnswer, chars);        
                number++;               	
				}
                else
                    i -= 6;   
            }
        } else {
            if (i % 8 == 0) {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }   
                strcpy(cRecords[number].cTopic1, chars);
            }
            else if (i%8 == 1){
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }  
                strcpy(cRecords[number].cNumber, chars);
            }
            else if (i%8 == 2) {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }  
                strcpy(cRecords[number].cQuestion1, chars);
            }   
            else if (i%8 == 3) {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }  
                strcpy(cRecords[number].cChoice1, chars);    
            }
            else if (i%8 == 4) {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }   
                strcpy(cRecords[number].cChoice2, chars);        
            }
            else if (i%8 == 5) {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }   
                strcpy(cRecords[number].cChoice3, chars);  
            }
            else if (i%8 == 6) {
                if (chars[0] != '\n') {
			    for(j=0; chars[j]!='\0'; j++) {
			        if(chars[j] == '\n') {
			            chars[j] = '\0';
			            break;
			        }
			    }                  	
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
        Data = fopen(fileName, "a"); // open file in write mode to overwrite existing content
        if (Data == NULL) {
            printf("Invalid file name. Please try again\nExport File:");
        }
    } while (Data == NULL);

    assignTopicNumbers(cRecords, Number);
    for (i=0; i<*Number; i++){
        fprintf(Data, "%s\n", cRecords[i].cTopic1); // print topic
        fprintf(Data, "%d\n", cRecords[i].nNumber); // print question number
        fprintf(Data, "%s\n", cRecords[i].cQuestion1); // print question
        fprintf(Data, "%s\n%s\n%s\n", cRecords[i].cChoice1, cRecords[i].cChoice2, cRecords[i].cChoice3); // print choices
        fprintf(Data, "%s\n\n", cRecords[i].cAnswer); // print answer

        strcpy(cRecords[i].cTopic1, "");
        strcpy(cRecords[i].cQuestion1, "");
        strcpy(cRecords[i].cChoice1, "");
        strcpy(cRecords[i].cChoice2, "");
        strcpy(cRecords[i].cChoice3, "");
        strcpy(cRecords[i].cAnswer, "");
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

int pPassValid() {
    char cPass[11] = "", cKey[10] = "AdminPass", cAdd[11], ch;
    int i = 0, j, nAsterisks = 0;

    printf("*****Manage Data*****\n");
    do {
        printf("Input Password (9): ");
        i = 0;
        while ((ch = _getch()) != '\r') { // use '\r' instead of "\n" to read the carriage return character
            if (ch == '\b') { // handle backspace
                if (i > 0) {
                    i--;
                    printf("\b \b");
                }
            } else if (i < 9) { 
                cPass[i] = ch;
                i++;
                printf("*");
            }
        }
        cPass[i] = '\0'; 

        if (strcmp(cPass, cKey) == 0) {
            printf("\nAccess Granted.\n");
            return 1;
        } else {
            printf("\nIncorrect password. Try again.\n");
            sleep(1);
			system("cls");
        }
    } while (1);
}

int checkRecord(struct records cRecords[], char strInput[], char Answer[], int *Number) {
    int i;
    for (i = 0; i < *Number; i++) {
        if (strcmp(strInput, cRecords[i].cQuestion1) == 0 && strcmp(Answer, cRecords[i].cAnswer) == 0)
            return 1;
    }
    return 0;
}

void inputRecord (struct records cRecords[], int Number, char strInput[], char Answer[]) {
    if (cRecords[Number].cTopic1[0] == '\0') {
        printf("Input the topic of the problem: ");
        scanf("%s", cRecords[Number].cTopic1);
    }
    system("cls");
    printf("Input a question: %s\n", strInput);
    printf("Input the answer to the question: %s\n", Answer);
    printf("Input the topic of the problem: %s\n", cRecords[Number].cTopic1);

    do {
    	    system("cls");
    	printf("Input a question: %s\n", strInput);
    	printf("Input the answer to the question: %s\n", Answer);
    	printf("Input the topic of the problem: %s\n", cRecords[Number].cTopic1);
        printf("Enter the first choice: ");
        scanf("%s", cRecords[Number].cChoice1);
        printf("Enter the second choice: ");
        scanf("%s", cRecords[Number].cChoice2);
        printf("Enter the third choice: ");
        scanf("%s", cRecords[Number].cChoice3);

        if (strcmp(cRecords[Number].cChoice1, cRecords[Number].cChoice2) == 0 ||
            strcmp(cRecords[Number].cChoice1, cRecords[Number].cChoice3) == 0 ||
            strcmp(cRecords[Number].cChoice2, cRecords[Number].cChoice3) == 0) {
            printf("Choices must be unique. Please enter valid choices.\n");
            system("pause");
            system("cls");
        }
    } while (strcmp(cRecords[Number].cChoice1, cRecords[Number].cChoice2) == 0 ||
             strcmp(cRecords[Number].cChoice1, cRecords[Number].cChoice3) == 0 ||
             strcmp(cRecords[Number].cChoice2, cRecords[Number].cChoice3) == 0);

    if (strcmp(cRecords[Number].cChoice1, Answer) != 0 &&
        strcmp(cRecords[Number].cChoice2, Answer) != 0 &&
        strcmp(cRecords[Number].cChoice3, Answer) != 0) {
        printf("The answer is not in the choices. Please input valid choices.\n");
        system("pause");
        system("cls");
        inputRecord(cRecords, Number, strInput, Answer);
        return;
    }
    strcpy(cRecords[Number].cQuestion1, strInput);
    strcpy(cRecords[Number].cAnswer, Answer);
    Number++;
}



void editRecord(struct records cRecords[], int *Number) {
	int i, j, choice = '\0', recordNum, fieldNum, topicNum, matchingTopics[100], matchingRecords[100], numMatches = 0;
	int topicCount = 0, currNum = 1;
    char topic[20], newValue[150];
    if (*Number == 0) {
        printf("There are currently no records.\n");
        system("pause");
        return;
    }
system("cls");
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
system("cls");
printf("\nRecords in %s\n", cRecords[topicNum].cTopic1);
for (i = 0; i < numMatches; i++) {
    printf("[%d] %s\n", i+1, cRecords[matchingRecords[i]].cQuestion1);
}

printf("Choose a record to edit: ");
scanf("%d", &choice);
recordNum = matchingRecords[choice - 1];
system("cls");
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
        break;
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
    if (*Number == 0) {
        printf("There are currently no records.\n");
        system("pause");
        return;
    }
system("cls");
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
system("cls");
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
		numCount (cRecords, Number);
		system("cls");
		printf("[1] Add a record\n[2] Edit a record\n[3] Delete a record\n[4] Import data\n[5] Export data\n[6] Return to main menu\n\nInput direction of activity: ");
		scanf("%d",&nAct);
		system("cls");
		getchar();
		if(nAct == 1){
		printf("Input a question: ");
		fgets (strInput, 150, stdin);
			    for(i=0; strInput[i]!='\0'; i++) {
			        if(strInput[i] == '\n') {
			            strInput[i] = '\0';
			            break;
			        }
			    } 
		printf("Input the answer to the question: " );
		scanf("%s", Answer);
		if (checkRecord(cRecords, strInput, Answer, Number) == 1){
			printf("It is already listed\n");
			system("pause");	
		}
		else{
			inputRecord (cRecords, *Number, strInput, Answer);
		}
		numCount (cRecords, Number);
	} else if (nAct == 2){	
		editRecord (cRecords, Number);
	} else if (nAct == 3){
		deleteRecord (cRecords, Number);
	} else if (nAct == 4){
		ImportRecords (cRecords, Number);
	} else if (nAct == 5){
		ExportRecords (cRecords, Number);
	} 
	} while (nAct != 6);
}
void answeredRecord(struct records cRecords[], int* Number){
	
}

void Play(struct records cRecords[], int* Number) {
    int i, j, currNum, randNum, pCount, recordNum, fieldNum, topicNum, matchingTopics[100], matchingRecords[100], numMatches = 0;
    char ans[30];
    int Continue = 1, Return, nNum = 0;
	playerCount(cPlayers, &pCount);
	if (*Number == 0) {
		system("cls");
        printf("There are currently no records.\n");
        system("pause");
        return;
    }
    printf("Input Player Name: ");
    scanf("%s", cPlayers[pCount].pName);
    system("cls");
    printf("[1] Start\n[2] End Game\n\nEnter Course of Action: ");
    scanf("%d", &Return);
    getchar();
    do{
    	system("cls");
    	    if (nNum == 1){
    			printf("Current Points: %d\n\n[1] Continue\n[2] End Game\n\nEnter Course of Action: ", cPlayers[pCount].pScore);
    			scanf("%d", &Return);
    			if (Return == 1)
    				nNum = 0;
    			system("cls");
			}
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
    	printf("Points:%d\nAnswer the Question: %s\nAnswer: ", cPlayers[pCount].pScore, cRecords[matchingRecords[randNum]].cQuestion1);
    	scanf("%s", ans);
    	if (strcmp(cRecords[matchingRecords[randNum]].cAnswer, ans) == 0){
    		nNum = 1;
    		printf("Correct!\n");
    		cPlayers[pCount].pScore+=1;
    		system("pause");
             for (i = randNum; i < *Number - 1; i++) {
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
		} else {
			nNum = 1;
			printf("Incorrect Answer\n");
			system("pause");
			printf("\n");
		}
	} else {
		Return = 0;
		printf("YOUR FINAL SCORE: %d\n", cPlayers[pCount].pScore);
		system("pause");
	}
	} while (Return);
}

void Exit(struct players cPlayers[], int *pNumber){
    FILE *Data;
    int i;
    Data = fopen("score.txt", "w");
	for (i = 0; i< *pNumber; i++){
		fprintf(Data, "%s\n", cPlayers[i].pName);
    	fprintf(Data, "%d\n\n", cPlayers[i].pScore); 
	}
    fclose(Data);
    *pNumber--;
}

void ViewScores(struct players cPlayers[], int *pNumber) {
    system("cls");
    int i, j, tempScore;
    char tempName[30];
    for (i = 0; i < *pNumber - 1; i++) {
        for (j = 0; j < *pNumber - i - 1; j++) {
            if (cPlayers[j].pScore < cPlayers[j + 1].pScore) {
                tempScore = cPlayers[j].pScore;
                cPlayers[j].pScore = cPlayers[j + 1].pScore;
                cPlayers[j + 1].pScore = tempScore;
                strcpy(tempName, cPlayers[j].pName);
                strcpy(cPlayers[j].pName, cPlayers[j + 1].pName);
                strcpy(cPlayers[j + 1].pName, tempName);
            }
        }
    }
    for (i = 0; i < *pNumber; i++) {
        printf("Player Name: %s\nScore: %d\n\n", cPlayers[i].pName, cPlayers[i].pScore);
    }
    system("pause");
}


void importScores(struct players cPlayers[]) {
    FILE *Data;
    char name[30];
    int score, i = 0;
    Data = fopen("score.txt", "r");
    
    while (fscanf(Data, "%s%d", name, &score) == 2) {
        strcpy(cPlayers[i].pName, name);
        cPlayers[i].pScore = score;
        i++;
    }
    fclose(Data);
}

void pPlay(struct records cRecords[], int *Number){
	int nDirection, pNumber;
	importScores(cPlayers);
	while (nDirection != 3){
	playerCount(cPlayers, &pNumber);
	system("cls");
	printf("[1] Play\n[2] View Scores\n[3] Exit\n\nInput Direction of Activity: ");	
	scanf("%d", &nDirection);
	if (nDirection == 1 ){
		Play(cRecords, Number);
	} else if (nDirection == 2){
		ViewScores(cPlayers, &pNumber);
	} else if (nDirection ==3){
		Exit (cPlayers, &pNumber);
	}		
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
