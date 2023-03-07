#include <stdio.h>
#include <string.h>

typedef char cTopic[20];
typedef char cChoice[30];
typedef char cQuestion[150];

struct records {
	cTopic fTopic1;
	cQuestion cQuestion1;
	cChoice cChoice1, cChoice2, cChoice3, cAnswer;
};

void providedRecords (struct records* cRecords){
	strcpy (cRecords[0].fTopic1, "Geography");
	strcpy (cRecords[0].cQuestion1, "The Sudd area of Southern Sudan is traversed by which of the following rivers?");
	strcpy (cRecords[0].cChoice1, "Niger");
	strcpy (cRecords[0].cChoice2, "Nile");
	strcpy (cRecords[0].cChoice3, "The Congo");
	
	strcpy (cRecords[1].fTopic1, "Entertainment");
	strcpy (cRecords[1].cQuestion1, "Which character owns an invisible robot plane?");
	strcpy (cRecords[1].cChoice1, "Wonder Woman");
	strcpy (cRecords[1].cChoice2, "Superman");
	strcpy (cRecords[1].cChoice3, "Thanos");	
	
	strcpy (cRecords[2].fTopic1, "Literature");
	strcpy (cRecords[2].cQuestion1, "In the movie named 1984, what is Winston's apartment called?");
	strcpy (cRecords[2].cChoice1, "Oceania View");
	strcpy (cRecords[2].cChoice2, "London House");
	strcpy (cRecords[2].cChoice3, "Victory Mansions");
	
}


int menu (){
int nChoice, nInvalid = 1;
printf("[1] Manage Data as an admin\[2] Play as a player\n[3) Exit Program\n\nInput your choice: ");
scanf("%d",&nChoice);
if (nChoice == 1 && nChoice == 2 && nChoice == 3)
	nInvalid = 0;
while (nInvalid=1){
	printf("Input valid input");
	scanf("%d", &nChoice);
	
if (nChoice == 1 && nChoice == 2 && nChoice == 3)
	nInvalid = 0;
}
system("cls");
return nChoice;
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
int mData(struct records* cRecords){
	int nAct;
	if (pPassValid() == 1)
	printf("[1] Add a record\n[2] Edit a record\n[3] Delete a record\n[4]Import data\n\nInput direction of activity: ");
	scanf("%d",&nAct);
	if(nAct == 1){
		
	} else if (nAct == 2){
		
	} else {
		
	}
	
}

void pPlay(){
	printf("Play");	
}

int main (){
struct records cRecords[20];
if (menu() == 1)
mData(&cRecords[20]);
else if (menu() == 2)
pPlay();
else if (menu() == 3)
return 0;
}
