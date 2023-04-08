/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
Edric Jensen See, DLSU ID# 12210161
*********************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>

typedef char cTopic[40]; //The max amount of characters per topic
typedef char cChoice[30]; //The max amount of characters per Choice and the answer
typedef char cQuestion[150]; //The max amount of characters per question
typedef char cPlayer[100]; //The max amount of characters per player

struct records {
  cTopic cTopic1, cNumber; //Providing the maximum amount of characters for the topic for both the topic and the scanned question number
  cQuestion cQuestion1; //Providing the maximum amount of characters for the question 
  cChoice cChoice1, cChoice2, cChoice3, cAnswer; //Proving the maximum amount of characters for the choices and answer
  int nNumber; //Declaring the assigned question number
};

struct players {
  cPlayer pName; //Providing the maximum amount of characters for the player name
  int pScore; //Declaring the player score
};

struct records cRecords[100];
struct players cPlayers[100];

//This function counts for the total number of records in cRecords and stores them in nNumber
int numCount(struct records cRecords[], int * nNumber) {
  int i; //Declaring variable i for the for loop
  int nNum = 0; //Declaring nNum as the new amount of records
  for (i = 0; i < 100; i++) {
    if (strlen(cRecords[i].cQuestion1) > 0) {
      nNum++;
    }
  }
  * nNumber = nNum; //Stores the new amount of records in pointer nNumber
}

//This function counts for the total number of players in cPlayers and stores them in pNumber
int playerCount(struct players cPlayers[], int * pNumber) {
  int i; //Declaring variable i for the for loop
  int nNum = 0; //Declaring nNum as the new amount of players
  for (i = 0; i < 100; i++) {
    if (strlen(cPlayers[i].pName) > 0) {
      nNum++;
    }
  }
  * pNumber = nNum; //Stores the new amount of players in pointer pNumber
}

//This function appends records stored in a given text file into cRecords and puts them into their respective cRecords fields
void importRecords(struct records cRecords[], int * nNumber) {
  int i, j; //Declaring variable for the for loop
  int nNum = * nNumber; //Setting nNum as the previous total number of records so that it appends the imported records
  int nChoice; //Whether to return or not
  char chars[150], fileName[50]; //Declaring the file name and the characters that are to be scanned from the file
  FILE * Data;
  printf("Input filename: "); //Input filename

  //This do while loop checks if the inputted filename is valid, and if not, it will ask the user to input a new filename
  do {
    scanf("%s", fileName);
    Data = fopen(fileName, "r");
    if (Data == NULL) {
      system("cls");
      printf("Invalid file name. Please try again\nImport File(Input 1 to return): ");
      if (strcmp(fileName, "1") == 0) //Adds an option for the player to return if the first filename input is invalid
        return;
    }
  } while (Data == NULL);
  for (i = 0; fgets(chars, 150, Data); i++) { //This scans each line of Data for as long as it is not FEOF
    /*To put each scanned line into their respective fields, my code assumes that they follow this way of numbering
	Topic           -  0
	Number			-  1
	Question		-  2
	First Choice	-  3
	Second Choice 	-  4
	Third Choice	-  5
	Answer 			-  6
	___(Newline)	-  7
	Topic           -  8
	Number			-  9
	Question		-  10
	First Choice	-  11
	Second Choice 	-  12
	Third Choice	-  13
	Answer 			-  14
	___(Newline)	-  15
	Topic			-  16
	*/
    if (i < 8) { //Assuming the given file content format,the first record starts with 0, so the first record is also 7 lines long including the newline after the record
      if (i % 7 == 0) { //If i%7 == 0, meaning if 0/7 = 0, then it's the first line, and it's the first topic
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cTopic1, chars);
      } else if (i % 7 == 1) { //If i%7 == 1, meaning if 1/7 = 1, then it's the second line, and it will be stored in cNumber
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cNumber, chars);
      } else if (i % 7 == 2) { //If i%7 == 2, meaning if 2/7 = 2, then it's the third line and will be stored in cQuestion
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cQuestion1, chars);
      } else if (i % 7 == 3) { //If i%7 == 3, meaning if 3/7 = 3, then it's the fourth line and will be stored in cChoice1 or the first choice
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cChoice1, chars);
      } else if (i % 7 == 4) { //If i%7 == 4, meaning if 4/7 = 4, then it's the fifth line and will be stored in cChoice2 or the second choice
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cChoice2, chars);
      } else if (i % 7 == 5) { //If i%7 == 5, meaning if 5/7 = 5, then it's the sixth line and will be stored in cChoice3 or the third choice
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cChoice3, chars);
      } else if (i % 7 == 6) { //If i%7 == 6, meaning if 6/7 = 6, then it's the seventh line and will be stored in cAnswer
        if (chars[0] != '\n') {
          for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
            if (chars[j] == '\n') {
              chars[j] = '\0';
            }
          }
          strcpy(cRecords[nNum].cAnswer, chars);
          nNum++;
        } else
          i -= 6; //If Answer is empty, it will skip the record and return to the previous one
      }
    } else {
      if (i % 8 == 0) { //This part of import records is works the same way as the one before but assumes i = 8 is the i = 0 of earlier
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cTopic1, chars);
      } else if (i % 8 == 1) {
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cNumber, chars);
      } else if (i % 8 == 2) {
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cQuestion1, chars);
      } else if (i % 8 == 3) {
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cChoice1, chars);
      } else if (i % 8 == 4) {
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cChoice2, chars);
      } else if (i % 8 == 5) {
        for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
          if (chars[j] == '\n') {
            chars[j] = '\0';
          }
        }
        strcpy(cRecords[nNum].cChoice3, chars);
      } else if (i % 8 == 6) {
        if (chars[0] != '\n') {
          for (j = 0; chars[j] != '\0'; j++) { //This for loop removes the newline scanned from fgets
            if (chars[j] == '\n') {
              chars[j] = '\0';
            }
          }
          strcpy(cRecords[nNum].cAnswer, chars);
          nNum++;
        } else
          i -= 7; //If Answer is empty, it will skip the record and return to the previous one
      }
    }
  }
  if (nNum == * nNumber) { //If nNum never changed, then nothing was added to cRecords
    printf("Nothing was imported...\n");
  } else
    printf("DATA SUCCESSFULLY IMPORTED!\n"); //If it changed, then there were records added to cRecords
  system("pause");
  * nNumber = nNum; //Returning nNum to the pointer nNumber to return the new total number of records
  fclose(Data);
}

//This function assigns the question numbers for each question in sequential order for each unique topic
void assignTopicNumbers(struct records cRecords[], int * nNumber) {
  int i, j; //Declaring looping variables
  int isUnique, counter; //If its unique
  int matchingTopics[100], matchingRecords[100]; //The arrays that will store the index of the corresponding unique topics and the index of the questions that are under them
  int numMatches1 = 0, numMatches2 = 0; //Declares the amount of matchingTopics and matchingRecords
  for (i = 0; i < * nNumber; i++) { //While i hasnt reached the total number of records
    isUnique = 0; //Resets the value of isUnique to 0
    for (j = 0; j < * nNumber; j++) { //It will check all the topics with i
      if (strcmp(cRecords[i].cTopic1, cRecords[j].cTopic1) == 0) {
        isUnique = 1; //If same topic, isUnique is equal to 1
      }
    }
    if (isUnique) {
      matchingTopics[numMatches1++] = i; //If it's unique, numMatches1++, and its index will be placed in matchingTopics
    }
  }

  for (i = 0; i < numMatches1; i++) { //While i is less than the total number of matching topics
    numMatches2 = 0; //Reset numMatches2 or matchingrecords
    counter = 0; // Moved declaration outside of loop
    for (j = 0; j < * nNumber; j++) {
      if (strcmp(cRecords[j].cTopic1, cRecords[matchingTopics[i]].cTopic1) == 0) { //If the records of the topics are the same
        matchingRecords[numMatches2++] = j; //Then numMatches2 is incremented, and the index of the matching record is stored in matchingRecords
      }
    }
    for (j = 0; j < numMatches2; j++) { //While j is less than the total number of records
      cRecords[matchingRecords[j]].nNumber = counter + 1; //The question number of that record is equal to the counter
      counter++; //Counter increments for each iteration for each question in each topic
    }
  }
}

//This function will export all records in cRecords into a file and clear all its contents
void exportRecords(struct records cRecords[], int * nNumber) {
  assignTopicNumbers(cRecords, nNumber); //Assigns topic numbers as soon as exportRecords is called
  FILE * Data;
  char fileName[50]; //Declaring filename
  int i; //Declaring looping variable
  int nChoice; //Whether the player wants to return or not
  if ( * nNumber == 0) { //If there are no available records
    printf("There are currently no records.\n");
    system("pause");
    return;
  }
  printf("Export filename: ");
  scanf("%s", fileName);
  Data = fopen(fileName, "w");

  for (i = 0; i < * nNumber; i++) { //For each record in cRecords
    fprintf(Data, "%s\n", cRecords[i].cTopic1); //We print each field according to the formatting of the sample text file
    fprintf(Data, "%d\n", cRecords[i].nNumber);
    fprintf(Data, "%s\n", cRecords[i].cQuestion1);
    fprintf(Data, "%s\n%s\n%s\n", cRecords[i].cChoice1, cRecords[i].cChoice2, cRecords[i].cChoice3);
    fprintf(Data, "%s\n\n", cRecords[i].cAnswer);

    //Then, we clear the record
    strcpy(cRecords[i].cTopic1, "");
    strcpy(cRecords[i].cQuestion1, "");
    strcpy(cRecords[i].cChoice1, "");
    strcpy(cRecords[i].cChoice2, "");
    strcpy(cRecords[i].cChoice3, "");
    strcpy(cRecords[i].cAnswer, "");
  }
  fclose(Data);
}

int mainMenu() {
  int nChoice, nInvalid; //Declares the variable for the user's choice and whether it's a valid ijnput or not
  printf("[1] Manage Data as an admin\n[2] Play as a player\n[3] Exit Program\n\nInput your choice: "); //Prints the menu
  scanf("%d", & nChoice); //scans for the value if
  if (nChoice == 1 || nChoice == 2 || nChoice == 3) { //If the input is valid
    system("cls");
    return nChoice; //Return the user's choice
  }
  while (nChoice != 1 || nChoice != 2 || nChoice != 3) { //Otherwise, continuously loop until the input is valid
    printf("Input valid input: ");
    scanf("%d", & nChoice);

    if (nChoice == 1 || nChoice == 2 || nChoice == 3) { //If it is valid
      system("cls");
      return nChoice; //It will return nChoice
    }
  }
}

//This function will have the user input the password and check if it is correct and ask the user if he/she wants to exit for each time they input the incorrect password
int playerPassValid() {
  char cPass[11] = "", cKey[10] = "AdminPass"; //Declaring the password and the assigned password
  char ch; //Declaring the variable in which the inputs are to be first placed;
  int i, j; //Declaring looping variables
  int nChoice = 0; //Declaring the option for the user if the user wants to return or not
  do { //A do while loop that will never end until the password is gotten correctly or if the user inputs 2 for nChoice
    printf("*****Manage Data*****\n");
    printf("Input Password (9): ");
    i = 0; //Resets the value of i for each iteration;
    while ((ch = _getch()) != '\r') { //Using conio.h getch to print the password as asterisks as charaters are inputted
      if (ch == '\b') { //If a backspace is inputted, then it will also remove it
        if (i > 0) {
          i--;
          printf("\b \b");
        }
      } else if (i < 9) { //Else
        cPass[i] = ch; //Each character inputted is placed into cPass
        i++;
        printf("*"); //And what is printed is an asterisk
      }
    }
    cPass[i] = '\0'; //Sets the last index of cPass as a null character

    if (strcmp(cPass, cKey) == 0) { //If the password is correct
      printf("\nAccess Granted.\n"); //Access granted
      return 1; //And return 1
    } else { //otherwise
      system("cls");
      printf("INCORRECT PASSWORD\n\n[1]Retry\n[2]Return to main menu\n\nInput Choice: "); //It will print this
      scanf("%d", & nChoice); //The user has to input their choice
      while (nChoice != 1 && nChoice != 2) { //So while their inpiut is invalid
        system("cls");
        printf("INCORRECT PASSWORD\n\n[1]Retry\n[2]Return to main menu\n\nInput Valid Input: "); //Keep printing that
        scanf("%d", & nChoice);
      }
      switch (nChoice) {
      case 1: //If nChoice is 1
        system("cls");
        break; //It will break and continue the entire do-while loop
      case 2: //If nChoice is 2
        system("cls");
        return; //It will return
        break;
      }
    }
  } while (1);
}

//This function will check whether the inputted question and answer are already existing in cRecords
int checkRecord(struct records cRecords[], char strInput[], char Answer[], int * nNumber) {
  int i; //Declaring looping variables
  for (i = 0; i < * nNumber; i++) { //While i is less than the total number of records
    if (strcmp(strInput, cRecords[i].cQuestion1) == 0 && strcmp(Answer, cRecords[i].cAnswer) == 0) //If it is already in records
      return 1; //It will return 1
  }
  return 0; //Otherwise, return 0
}

//This function is where the unser will input a new record
void inputRecord(struct records cRecords[], int nNumber, char strInput[], char Answer[]) {
  int i; //Declaration of input variables
  if (cRecords[nNumber].cTopic1[0] == '\0') { //If the topic is empty
    printf("Input the topic of the problem: ");
    fgets(cRecords[nNumber].cTopic1, 150, stdin); //Input the topic
    for (i = 0; cRecords[nNumber].cTopic1[i] != '\0'; i++) { //Then delete the extra newline
      if (cRecords[nNumber].cTopic1[i] == '\n') {
        cRecords[nNumber].cTopic1[i] = '\0';
      }
    }
  }
  system("cls");
  printf("Input a question: %s\n", strInput); //Prints the previously inputted question
  printf("Input the answer to the question: %s\n", Answer); //prints the previously inputted answer
  printf("Input the topic of the problem: %s\n", cRecords[nNumber].cTopic1); //prints the inputted topic

  do { //For as long as the questions aren't unique
    system("cls");
    printf("Input a question: %s\n", strInput); //Prints the previously inputted question
    printf("Input the answer to the question: %s\n", Answer); //Prints the previously inputted answer
    printf("Input the topic of the problem: %s\n", cRecords[nNumber].cTopic1); //Prints the previously inputted topic
    printf("Enter the first choice: ");
    fgets(cRecords[nNumber].cChoice1, 150, stdin); //Enter the first choice
    for (i = 0; cRecords[nNumber].cChoice1[i] != '\0'; i++) { //removes the newline character of the first choice
      if (cRecords[nNumber].cChoice1[i] == '\n') {
        cRecords[nNumber].cChoice1[i] = '\0';
      }
    }
    printf("Enter the second choice: ");
    fgets(cRecords[nNumber].cChoice2, 150, stdin); //Enter the second choice
    for (i = 0; cRecords[nNumber].cChoice2[i] != '\0'; i++) { //removes the newline character of the second choice
      if (cRecords[nNumber].cChoice2[i] == '\n') {
        cRecords[nNumber].cChoice2[i] = '\0';
      }
    }
    printf("Enter the third choice: ");
    fgets(cRecords[nNumber].cChoice3, 150, stdin); //Enter the third choice
    for (i = 0; cRecords[nNumber].cChoice3[i] != '\0'; i++) { //removes the newline character of the third choice
      if (cRecords[nNumber].cChoice3[i] == '\n') {
        cRecords[nNumber].cChoice3[i] = '\0';
      }
    }

    if (strcmp(cRecords[nNumber].cChoice1, cRecords[nNumber].cChoice2) == 0 || //If the choices inputted aren't unique
      strcmp(cRecords[nNumber].cChoice1, cRecords[nNumber].cChoice3) == 0 ||
      strcmp(cRecords[nNumber].cChoice2, cRecords[nNumber].cChoice3) == 0) {
      printf("Choices must be unique. Please enter valid choices.\n"); //Prints this then restarts the loop to input the choices
      system("pause");
      system("cls");
    }
  } while (strcmp(cRecords[nNumber].cChoice1, cRecords[nNumber].cChoice2) == 0 ||
    strcmp(cRecords[nNumber].cChoice1, cRecords[nNumber].cChoice3) == 0 ||
    strcmp(cRecords[nNumber].cChoice2, cRecords[nNumber].cChoice3) == 0);

  if (strcmp(cRecords[nNumber].cChoice1, Answer) != 0 && //If the answer is not within the choices
    strcmp(cRecords[nNumber].cChoice2, Answer) != 0 &&
    strcmp(cRecords[nNumber].cChoice3, Answer) != 0) {
    printf("The answer is not in the choices. Please input valid choices.\n"); //It will print this
    system("pause");
    system("cls");
    inputRecord(cRecords, nNumber, strInput, Answer); //Then it will recursively call the function again to scan for the choices
    return;
  }
  strcpy(cRecords[nNumber].cQuestion1, strInput); //If all are valid, it will then copy the question inputted to cRecords
  strcpy(cRecords[nNumber].cAnswer, Answer); //and the answer inputted to cRecords
  nNumber++;
}

//This function edits the records in cRecords
void editRecord(struct records cRecords[], int * nNumber) {
  int i, j; //Declaring looping variables
  int nChoice = '\0', fieldNum, nDecision = 0; //Declaring choice variables
  int topicNum, recordNum; //Declaring the index of the topics and records
  int matchingTopics[100], matchingRecords[100]; //Declaring the arrays in which the indexes of the unique topics and records are to be stores
  int nContinue = 1; //Declares the variables that will continue or end editRecord
  int numMatches = 0, topicCount = 0, currNum = 1; //Increments of the current numbers
  char newValue[150]; //Input of the new value
  if ( * nNumber == 0) { //If There are no records 
    printf("There are currently no records.\n");
    system("pause");
    return; //Return after input from pause
  }
  system("cls");
  printf("Available Topics:\n"); //Prints available topics
  for (i = 0; i < * nNumber; i++) { //while i is less than the total number of records
    int isUnique = 1; //It is unique
    for (j = i - 1; j >= 0; j--) { // While j is still greater than 0
      if (strcmp(cRecords[i].cTopic1, cRecords[j].cTopic1) == 0) { //If the topic is the same as some other topic
        isUnique = 0; //It is not unique
      }
    }
    if (isUnique) { //If it is unique
      matchingTopics[numMatches++] = i; //matchingTopics[i] = the current index
      printf("[%d] %s\n", currNum, cRecords[i].cTopic1); //prints the unique topic's index's topic
      currNum++; //increments the current number
    }
  }

  while (topicNum < 1 || topicNum > currNum - 1) { //While topicNum is not a valid input
    printf("Choose a topic to delete: ");
    scanf("%d", & topicNum); //Input topicNum
    if (topicNum < 1 || topicNum > currNum - 1) {
      printf("Invalid input. Please choose a valid topic number.\n");
    }
  }

  topicNum = matchingTopics[topicNum - 1]; //topicNum is equal to the matchingTopics indedx

  numMatches = 0;
  for (i = 0; i < * nNumber; i++) { //while i is less than the total number of records
    if (strcmp(cRecords[i].cTopic1, cRecords[topicNum].cTopic1) == 0) { //If the topic of the unique topics is the same as for i
      matchingRecords[numMatches++] = i; //We save the index to matchingRecords
    }
  }
  system("cls");
  printf("Records in %s\n", cRecords[topicNum].cTopic1);
  for (i = 0; i < numMatches; i++) { //While i is less than the amount of same topics
    printf("[%d] %s\n", i + 1, cRecords[matchingRecords[i]].cQuestion1); //print the contents of cRecords according to the matchingRecords indexes
  }

  while (nChoice < 1 || nChoice > numMatches) { //While input is invalid
    printf("Choose a record to edit: ");
    scanf("%d", & nChoice); //Enter the record to edit
    if (nChoice < 1 || nChoice > numMatches) {
      printf("Invalid input. Please choose a valid record number.\n");
    }
  }
  recordNum = matchingRecords[nChoice - 1]; //Sets recordNum to the index of matchingRecords according to the choice

  //Asks the user which field he/she wants to edit
  while (fieldNum != 1 && fieldNum != 2 && fieldNum != 3 && fieldNum != 4 && fieldNum != 5 && fieldNum != 6) { //While field is not a valid input
    system("cls");
    //Prints the current record
    printf("Current Record:\n");
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
    printf("Enter field number: "); //Input field
    scanf("%d", & fieldNum);
    if (fieldNum != 1 && fieldNum != 2 && fieldNum != 3 && fieldNum != 4 && fieldNum != 5 && fieldNum != 6) {
      printf("Invalid Field, input a valid field.\n");
      system("pause");
    }
  }

  getchar();
  printf("Enter new value: ");
  fgets(newValue, 150, stdin); //Enter the new value for the chosen field
  for (i = 0; newValue[i] != '\0'; i++) { //Removes the newline from the input
    if (newValue[i] == '\n') {
      newValue[i] = '\0';
      break;
    }
  }

  switch (fieldNum) {
  case 1:
    strcpy(cRecords[recordNum].cTopic1, newValue); //Copies the newValue to cRecords topic if topic is the chosen field
    break;
  case 2:
    while (checkRecord(cRecords, newValue, cRecords[recordNum].cAnswer, nNumber) == 1) { //Then it will call checkRecord to see if it is existing
      printf("It is already listed\n"); //If it is, print that it is already listed
      system("pause");
      printf("Enter new value: ");
      fgets(newValue, 150, stdin); //Enter the new value for the chosen field
      for (i = 0; newValue[i] != '\0'; i++) { //Removes the newline from the input
        if (newValue[i] == '\n') {
          newValue[i] = '\0';
        }
      }
    }
    strcpy(cRecords[recordNum].cQuestion1, newValue); //Copies the newValue to cRecords question if question is the chosen field
    break;
  case 3: //If the choice inputted removes the answer
    if (strcmp(cRecords[recordNum].cAnswer, cRecords[recordNum].cChoice1) == 0) {
      printf("You can not change this choice as it is the answer, please choose another field\n");
      system("pause");
      break;
    }
    while (strcmp(cRecords[recordNum].cAnswer, newValue) != 0 && strcmp(cRecords[recordNum].cAnswer, cRecords[recordNum].cChoice2) != 0 && strcmp(cRecords[recordNum].cAnswer, cRecords[recordNum].cChoice3) != 0) {
      printf("None of the Choices correspond to the answer. Please input a valid answer\n");
      system("pause");
      system("cls");
      printf("Current Record:\n");
      printf("Topic: %s\n", cRecords[recordNum].cTopic1);
      printf("Question: %s\n", cRecords[recordNum].cQuestion1);
      printf("Choice 1: %s\n", cRecords[recordNum].cChoice1);
      printf("Choice 2: %s\n", cRecords[recordNum].cChoice2);
      printf("Choice 3: %s\n", cRecords[recordNum].cChoice3);
      printf("Answer: %s\n\n", cRecords[recordNum].cAnswer);
      printf("Input valid first choice: ");
      fgets(newValue, 150, stdin); //Get a new input
      for (i = 0; newValue[i] != '\0'; i++) { //remove newline
        if (newValue[i] == '\n') {
          newValue[i] = '\0';
        }
      }
    }
    strcpy(cRecords[recordNum].cChoice1, newValue); //Copy the new input to the first choice
    break;
  case 4: //If the choice inputted removes the answer
    if (strcmp(cRecords[recordNum].cAnswer, cRecords[recordNum].cChoice2) == 0) {
      printf("You can not change this choice as it is the answer, please choose another field\n");
      system("pause");
      break;
    }
    while (strcmp(cRecords[recordNum].cAnswer, cRecords[recordNum].cChoice1) != 0 && strcmp(cRecords[recordNum].cAnswer, newValue) != 0 && strcmp(cRecords[recordNum].cAnswer, cRecords[recordNum].cChoice3) != 0) {
      printf("None of the Choices correspond to the answer. Please input a valid answer\n");
      system("pause");
      system("cls");
      printf("Current Record:\n");
      printf("Topic: %s\n", cRecords[recordNum].cTopic1);
      printf("Question: %s\n", cRecords[recordNum].cQuestion1);
      printf("Choice 1: %s\n", cRecords[recordNum].cChoice1);
      printf("Choice 2: %s\n", cRecords[recordNum].cChoice2);
      printf("Choice 3: %s\n", cRecords[recordNum].cChoice3);
      printf("Answer: %s\n\n", cRecords[recordNum].cAnswer);
      printf("Input valid second choice: ");
      fgets(newValue, 150, stdin); //New input
      for (i = 0; newValue[i] != '\0'; i++) { //Remove newline
        if (newValue[i] == '\n') {
          newValue[i] = '\0';
        }
      }
    }
    strcpy(cRecords[recordNum].cChoice2, newValue); //Copies the new input to the second choice
    break;
  case 5: //If the choice inputted removes the answer
    if (strcmp(cRecords[recordNum].cAnswer, cRecords[recordNum].cChoice3) == 0) {
      printf("You can not change this choice as it is the answer, please choose another field\n");
      system("pause");
      break;
    }
    while (strcmp(cRecords[recordNum].cAnswer, cRecords[recordNum].cChoice1) != 0 && strcmp(cRecords[recordNum].cAnswer, cRecords[recordNum].cChoice2) != 0 && strcmp(cRecords[recordNum].cAnswer, newValue) != 0) {
      printf("None of the Choices correspond to the answer. Please input a valid answer\n");
      system("pause");
      system("cls");
      printf("Current Record:\n");
      printf("Topic: %s\n", cRecords[recordNum].cTopic1);
      printf("Question: %s\n", cRecords[recordNum].cQuestion1);
      printf("Choice 1: %s\n", cRecords[recordNum].cChoice1);
      printf("Choice 2: %s\n", cRecords[recordNum].cChoice2);
      printf("Choice 3: %s\n", cRecords[recordNum].cChoice3);
      printf("Answer: %s\n\n", cRecords[recordNum].cAnswer);
      printf("Input valid third choice: ");
      fgets(newValue, 150, stdin); //Input new third choice
      for (i = 0; newValue[i] != '\0'; i++) { //Removes the newline character
        if (newValue[i] == '\n') {
          newValue[i] = '\0';
        }
      }
    }
    strcpy(cRecords[recordNum].cChoice3, newValue); //Copies the new value to the third choice
    break;
  case 6: //If answer is not among the choices
    while (strcmp(newValue, cRecords[recordNum].cChoice1) != 0 && strcmp(newValue, cRecords[recordNum].cChoice2) != 0 && strcmp(newValue, cRecords[recordNum].cChoice3) != 0) {
      printf("Answer is not within the choices. Please input a valid answer\n");
      system("pause");
      system("cls");
      printf("Current Record:\n");
      printf("Topic: %s\n", cRecords[recordNum].cTopic1);
      printf("Question: %s\n", cRecords[recordNum].cQuestion1);
      printf("Choice 1: %s\n", cRecords[recordNum].cChoice1);
      printf("Choice 2: %s\n", cRecords[recordNum].cChoice2);
      printf("Choice 3: %s\n", cRecords[recordNum].cChoice3);
      printf("Answer: %s\n\n", cRecords[recordNum].cAnswer);
      printf("Input valid answer: ");
      fgets(newValue, 150, stdin); //Input a new value
      for (i = 0; newValue[i] != '\0'; i++) { //remove the newline of the input
        if (newValue[i] == '\n') {
          newValue[i] = '\0';
        }
      }
  }
      while (checkRecord(cRecords, cRecords[recordNum].cQuestion1, newValue, nNumber) == 1) { //Then it will call checkRecord to see if it is existing
        printf("It is already listed\n"); //If it is, print that it is already listed
        system("pause");
        printf("Enter new value: ");
        fgets(newValue, 150, stdin); //Enter the new value for the chosen field
        for (i = 0; newValue[i] != '\0'; i++) { //Removes the newline from the input
          if (newValue[i] == '\n') {
            newValue[i] = '\0';
          }
        }
      }
    strcpy(cRecords[recordNum].cAnswer, newValue); //Copy the new input to the answer
    break;
  }
  while (nContinue) { //While continue is 1
    system("cls");
    currNum = 1; //Resets currNum
    //Starts the code to show the unique topics
    printf("Available Topics: \n");
    for (i = 0; i < * nNumber; i++) { //
      int isUnique = 1;
      for (j = i - 1; j >= 0; j--) {
        if (strcmp(cRecords[i].cTopic1, cRecords[j].cTopic1) == 0) {
          isUnique = 0;
        }
      }
      if (isUnique) {
        matchingTopics[numMatches++] = i;
        printf("%d -- %s\n", currNum, cRecords[i].cTopic1);
        currNum++;
      }
    }
    do { //While nContinue = 1
      if (nDecision != 2) { //If nDecision is not = 2
        system("cls");
        printf("[1] Edit another record\n[2] Return\n\nInput Choice: ");
        scanf("%d", & nDecision); //Scan for nDecision
        switch (nDecision) {
        case 1:
          editRecord(cRecords, nNumber); //If nDecision is 1, recursively call editRecord again
          nContinue = 0; //sets this value to 0 to prevent exiting after returning from the recursive call
          break;
        case 2:
          nContinue = 0; //Sets to 0 to stop the function
          nDecision = 2; //set to 2 to ensure the function returns after returning from the recursive call
          break;
        }
      } else {
        nContinue = 0; //Worst case is that it just stops the function
      }
    } while (nContinue);
  }
}

//This function deletes a record from existing records
void deleteRecord(struct records cRecords[], int * nNumber) {
  int nConfirm = -1, nDel = -1; //Declaration of deletion confirmation
  int i, j; //Declaring looping variables
  int nChoice = '\0', fieldNum, nDecision = 0; //Declaring choice variables
  int topicNum, recordNum; //Declaring the index of the topics and records
  int matchingTopics[100], matchingRecords[100]; //Declaring the arrays in which the indexes of the unique topics and records are to be stores
  int nContinue = 1; //Declares the variables that will continue or end editRecord
  int numMatches = 0, topicCount = 0, currNum = 1; //Increments of the current numbers
  char newValue[150]; //Input of the new value
  if ( * nNumber == 0) { //If there are no records
    printf("There are currently no records.\n");
    system("pause");
    return; //Return
  }
  system("cls");

  //Same code as before to show unique topics
  printf("Available Topics:\n");
  for (i = 0; i < * nNumber; i++) {
    int isUnique = 1;
    for (j = i - 1; j >= 0; j--) {
      if (strcmp(cRecords[i].cTopic1, cRecords[j].cTopic1) == 0) {
        isUnique = 0;
      }
    }
    if (isUnique) {
      matchingTopics[numMatches++] = i;
      printf("[%d] %s\n", currNum, cRecords[i].cTopic1);
      currNum++;
    }
  }

  while (topicNum < 1 || topicNum > currNum - 1) { //While topicNum is invalid
    printf("Choose a topic to delete: ");
    scanf("%d", & topicNum); //input topicNum
    getchar();
    if (topicNum < 1 || topicNum > currNum - 1) {
      printf("Invalid input. Please choose a valid topic number.\n");
    }
  }
  system("cls");
  topicNum = matchingTopics[topicNum - 1]; //Sets topicNum to the matchingTopics topicNum index

  numMatches = 0; //resets numMatches

  //same code as before to show unique records under the unique topic
  for (i = 0; i < * nNumber; i++) {
    if (strcmp(cRecords[i].cTopic1, cRecords[topicNum].cTopic1) == 0) {
      matchingRecords[numMatches++] = i;
    }
  }

  printf("Records in %s\n", cRecords[topicNum].cTopic1);
  for (i = 0; i < numMatches; i++) {
    printf("[%d] %s\n", i + 1, cRecords[matchingRecords[i]].cQuestion1);
  }

  while (nChoice < 1 || nChoice > numMatches) { //While nChoice is invalid
    printf("Choose a record to delete: ");
    scanf("%d", & nChoice); //scan for nChoice
    getchar();
    if (nChoice < 1 || nChoice > numMatches) {
      printf("Invalid input. Please choose a valid record number.\n");
    }
  }
  recordNum = matchingRecords[nChoice - 1]; //sets recordNum as matchingRecords nChoice index

  for (i = 0; i < * nNumber; i++) { //Searching for the index of recordNum
    if (strcmp(cRecords[recordNum].cTopic1, cRecords[i].cTopic1) == 0) {
      nDel = recordNum; //setting nDel as the index of recordNum
    }
  }
  if (nDel >= 0) {
    printf("\nAre you sure you want to delete this question? (1 = yes, 0 = no): ");
    scanf("%d", & nConfirm); //Confirmation of deletion
    getchar();
    while (nConfirm != 1 && nConfirm != 0) { //While nConfirm is invalid
      printf("Input valid input: (1 = yes, 0 = no): ");
      scanf("%d", & nConfirm); //Confirmation of deletion
    }

    if (nConfirm == 1) { //If confirmation has been received
      for (i = nDel; i < * nNumber - 1; i++) {
        //Moves all contents from the next index of nDel to the selected record to delete
        strcpy(cRecords[i].cTopic1, cRecords[i + 1].cTopic1);
        strcpy(cRecords[i].cNumber, cRecords[i + 1].cNumber);
        strcpy(cRecords[i].cQuestion1, cRecords[i + 1].cQuestion1);
        strcpy(cRecords[i].cChoice1, cRecords[i + 1].cChoice1);
        strcpy(cRecords[i].cChoice2, cRecords[i + 1].cChoice2);
        strcpy(cRecords[i].cChoice3, cRecords[i + 1].cChoice3);
        strcpy(cRecords[i].cAnswer, cRecords[i + 1].cAnswer);
      }
      //Sets the latest record to empty
      strcpy(cRecords[ * nNumber - 1].cTopic1, "");
      strcpy(cRecords[ * nNumber - 1].cNumber, "");
      strcpy(cRecords[ * nNumber - 1].cQuestion1, "");
      strcpy(cRecords[ * nNumber - 1].cChoice1, "");
      strcpy(cRecords[ * nNumber - 1].cChoice2, "");
      strcpy(cRecords[ * nNumber - 1].cChoice3, "");
      strcpy(cRecords[ * nNumber - 1].cAnswer, "");
      ( * nNumber) --; //Decrement the total amount of records
      printf("\nRecord successfully deleted.\n");
    } else {
      printf("\nRecord not deleted.\n");
    }
  }
  do { //While nContinue is true
    if (nDecision != 2) { //While nDecision is not equal to 2
      system("cls");
      printf("[1] Edit another record\n[2] Return\n\nInput Choice: "); //Print this
      scanf("%d", & nDecision); //Scan for nDecision
      switch (nDecision) {
      case 1: //if nDecision = 1
        deleteRecord(cRecords, nNumber); //recursively calls deleteRecord again
        nContinue = 0; //sets nContinue to 0 to prevent exiting after returning from the recursive call
        break;
      case 2:
        nContinue = 0; //Ends the loop
        nDecision = 2; //sets nDecision to 2 to ensure the function returns after returning from the recursive call
        break;
      }
    } else {
      nContinue = 0; //Worst case end loop
    }
  } while (nContinue);
  return; //Returns after
}

//This function is basically the menu for manage data
int manageData(struct records cRecords[], int * nNumber) {
  int i = 0; //Declaring looping variable
  int nAct;
  cQuestion strInput; //Declaring question input 
  cChoice Answer; //Declaring answer input
  if (playerPassValid() == 1) //First asks for user password, and if valid, continue
    do { //Keep Scanning for nAct for as long as the user doesn't input a valid input
      numCount(cRecords, nNumber); //Counts the total number of records and stores them in nNumber
      system("cls");
      printf("[1] Add a record\n[2] Edit a record\n[3] Delete a record\n[4] Import data\n[5] Export data\n[6] Return to main menu\n\nInput direction of activity: ");
      scanf("%d", & nAct); //Scans for nAct
      system("cls");
      getchar(); //Flushes the extra char
      if (nAct == 1) { //If add a record
        printf("Input a question: ");
        fgets(strInput, 150, stdin); //Input a question 
        for (i = 0; strInput[i] != '\0'; i++) { //Remove the newline from the qeustion
          if (strInput[i] == '\n') {
            strInput[i] = '\0';
          }
        }
        printf("Input the answer to the question: ");
        fgets(Answer, 150, stdin); //Then input answer
        for (i = 0; Answer[i] != '\0'; i++) { //Remove newline from answer
          if (Answer[i] == '\n') {
            Answer[i] = '\0';
          }
        }
        if (checkRecord(cRecords, strInput, Answer, nNumber) == 1) { //Then it will call checkRecord to see if it is existing
          printf("It is already listed\n"); //If it is, print that it is already listed
          system("pause");
        } else {
          inputRecord(cRecords, * nNumber, strInput, Answer); //If it's unique, call inputRecord
        }
        numCount(cRecords, nNumber); //Recount nNumber
      } else if (nAct == 2) { //If nAct = 2
        editRecord(cRecords, nNumber); //Calls editRecord
      } else if (nAct == 3) { //If nAct = 3
        deleteRecord(cRecords, nNumber); //Calls deleteRecord
      } else if (nAct == 4) { //if nAct = 4
        importRecords(cRecords, nNumber); //Calls importRecords
      } else if (nAct == 5) { //If nAct = 5
        exportRecords(cRecords, nNumber); //Calls exportRecords
      }
    } while (nAct != 6);
}

//This function is where play takes place
void playGame(struct records cRecords[], int * nNumber) {
  int i, j; //Declaring looping variables
  int nChoice = '\0', fieldNum, nDecision = 0; //Declaring choice variables
  int topicNum, recordNum; //Declaring the index of the topics and records
  int matchingTopics[100], matchingRecords[100]; //Declaring the arrays in which the indexes of the unique topics and records are to be stores
  int nContinue = 1; //Declares the variables that will continue or end editRecord
  int numMatches = 0, topicCount = 0, currNum = 1; //Increments of the current numbers
  int randNum; //Declaring variable for randomizing questions
  int pCount; //Counts the current players 
  cChoice ans; //Declaration of player answer
  int Continue = 1, Return, nNum = 0; //Declaring variable that will determine whether the game will continue or not
  playerCount(cPlayers, & pCount); //Counts the number of players
  if ( * nNumber == 0) { //If there are no records
    system("cls");
    printf("There are currently no records.\n");
    system("pause");
    return; //Return
  }
  printf("Input Player Name: ");
  scanf("%s", cPlayers[pCount].pName); //Input player name
  system("cls");
  printf("[1] Start\n[2] End Game\n\nEnter Course of Action: ");
  scanf("%d", & Return); //Input player's choice
  getchar();
  do { //While return  
    if ( * nNumber == 0) { //Keep checking if there are any records
      system("cls");
      printf("There are no records left.\n");
      Return = 0; //If no records, end
      nNum = 0; //If no records, end
    }
    numMatches = 0; //Declares 0 for current uniques
    currNum = 0; //Declares 0 for the number of current uniques
    if (nNum == 1) { //If nNum is 1
      printf("Current Points: %d\n\n[1] Continue\n[2] End Game\n\nEnter Course of Action: ", cPlayers[pCount].pScore); //Keep printing this
      scanf("%d", & Return); //Scans for Return
      if (Return == 1)
        nNum = 0; //Resets value of nNum
      system("cls");
    }
    if (Return == 1) { //If Return is 1, play

      //Prints available topics
      printf("Available Topics:\n");
      for (i = 0; i < * nNumber; i++) {
        int isUnique = 1;
        for (j = i - 1; j >= 0; j--) {
          if (strcmp(cRecords[i].cTopic1, cRecords[j].cTopic1) == 0) {
            isUnique = 0;
          }
        }
        if (isUnique) {
          matchingTopics[numMatches++] = i;
          printf("[%d] %s\n", currNum + 1, cRecords[i].cTopic1);
          currNum++;
        }
      }

      do { //While topicNum is not a valid input
        printf("Choose a topic to play: ");
        scanf("%d", & topicNum); //Choose a topic to answer
        getchar();
        if (topicNum < 1 || topicNum > currNum) {
          printf("Invalid input. Please choose a valid topic number.\n");
        }
      } while (topicNum < 1 || topicNum > currNum);

      topicNum = matchingTopics[topicNum - 1];

      numMatches = 0; //Resets the number of matches

      //Looks for the records under the topic
      for (i = 0; i < * nNumber; i++) {
        if (strcmp(cRecords[i].cTopic1, cRecords[topicNum].cTopic1) == 0) {
          matchingRecords[numMatches++] = i;
        }
      }

      randNum = rand() % numMatches; //Sends randNum a random index of the chosen question under the topic
      system("cls");
      //Prints the points, topic, question, and choices
      printf("Points:%d\nTopic: %s\nAnswer the Question: %s\nChoices:\n%s\n%s\n%s\n\nAnswer: ", cPlayers[pCount].pScore, cRecords[matchingRecords[randNum]].cTopic1, cRecords[matchingRecords[randNum]].cQuestion1, cRecords[matchingRecords[randNum]].cChoice1, cRecords[matchingRecords[randNum]].cChoice2, cRecords[matchingRecords[randNum]].cChoice3);
      fgets(ans, 150, stdin); //Input the answer to the question
      for (i = 0; ans[i] != '\0'; i++) { //Removes the newline from the answer
        if (ans[i] == '\n') {
          ans[i] = '\0';
        }
      }

      if (strcmp(cRecords[matchingRecords[randNum]].cAnswer, ans) == 0) { //If answer is correct
        nNum = 1; //Sets nNum to 1
        printf("Correct!\n"); //Displays correct
        cPlayers[pCount].pScore += 1; //Increments the score
        system("pause");
        for (i = matchingRecords[randNum]; i < * nNumber - 1; i++) { //Deletes the question from the records
          strcpy(cRecords[i].cTopic1, cRecords[i + 1].cTopic1);
          strcpy(cRecords[i].cNumber, cRecords[i + 1].cNumber);
          strcpy(cRecords[i].cQuestion1, cRecords[i + 1].cQuestion1);
          strcpy(cRecords[i].cChoice1, cRecords[i + 1].cChoice1);
          strcpy(cRecords[i].cChoice2, cRecords[i + 1].cChoice2);
          strcpy(cRecords[i].cChoice3, cRecords[i + 1].cChoice3);
          strcpy(cRecords[i].cAnswer, cRecords[i + 1].cAnswer);
        }
        strcpy(cRecords[ * nNumber - 1].cTopic1, "");
        strcpy(cRecords[ * nNumber - 1].cNumber, "");
        strcpy(cRecords[ * nNumber - 1].cQuestion1, "");
        strcpy(cRecords[ * nNumber - 1].cChoice1, "");
        strcpy(cRecords[ * nNumber - 1].cChoice2, "");
        strcpy(cRecords[ * nNumber - 1].cChoice3, "");
        strcpy(cRecords[ * nNumber - 1].cAnswer, "");
        ( * nNumber) --; //Also decrements the total number of records
      } else { //If wrong
        nNum = 1; //Set nNum to 1
        printf("Incorrect Answer\n"); //Displays incorrect
        system("pause");
        printf("\n");
      }
    } else { //If Return is 2, ends the game
      Return = 0; //Sets return to 0
      printf("YOUR FINAL SCORE: %d\n", cPlayers[pCount].pScore); //Displays final score
      system("pause");
    }
  } while (Return);
}

//This function is where the player exits from the game
void exitGame(struct players cPlayers[], int * pNumber) {
  FILE * Data;
  int i, j; //Initiating looping variables
  int tempScore; //Initiating replacing variables
  char tempName[30]; //Initiating replacing variables
  Data = fopen("score.txt", "w"); //Opens the score.txt file

  //Starts bubble sorting the players in decreasing order
  for (i = 0; i < * pNumber - 1; i++) {
    for (j = 0; j < * pNumber - i - 1; j++) {
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

  //Prints the newly sorted contents of cPlayers into Data
  for (i = 0; i < * pNumber; i++) {
    fprintf(Data, "%s\n", cPlayers[i].pName);
    fprintf(Data, "%d\n\n", cPlayers[i].pScore);
  }
  fclose(Data);
}

//This function is where the player will view all the scores of all existing records
void viewScores(struct players cPlayers[], int * pNumber) {
  system("cls");
  int i, j; //Initiating looping variables
  int tempScore; //Initiating replacing variables
  char tempName[30]; //Initiating replacing variables
  if ( * pNumber == 0) { //If there are no players
    printf("There are no players to display.\n");
    system("pause");
    return; //Returns after display
  }

  //Bubble sorts the players in decreasing order
  for (i = 0; i < * pNumber - 1; i++) {
    for (j = 0; j < * pNumber - i - 1; j++) {
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

  //Prints the players out in descending order
  for (i = 0; i < * pNumber; i++) {
    printf("RANK: %d\nPlayer Name: %s\nScore: %d\n\n", i + 1, cPlayers[i].pName, cPlayers[i].pScore);
  }
  system("pause");
}

//Imports the scores from score.txt 
void importScores(struct players cPlayers[]) {
  FILE * Data;
  char name[30]; //Declaring variables to put into cPlayers
  int score; //Declaring variables to put into cPlayers
  int i = 0; //Declaring looping variables
  Data = fopen("score.txt", "r"); //Opens score.txt

  while (fscanf(Data, "%s%d", name, & score) == 2) {
    strcpy(cPlayers[i].pName, name); //Copies the name scanned into cPlayers.pName
    cPlayers[i].pScore = score; //Copies the score into cPlayers.pScore
    i++;
  }
  fclose(Data);
}

//Inputs the menu for play game
void playerPlay(struct records cRecords[], int * nNumber) {
  int nDirection; //Declares player choice variables
  int pNumber; //Declares the number of players
  importScores(cPlayers); //Imports the scores of previous players from score.txt
  while (nDirection != 3) { //While nDirection is invalid
    playerCount(cPlayers, & pNumber); //Counts the number of players
    system("cls");
    printf("[1] Play\n[2] View Scores\n[3] Exit\n\nInput Direction of Activity: ");
    scanf("%d", & nDirection); //Scans for the player's choice
    if (nDirection == 1) { //If play
      playGame(cRecords, nNumber); //Calls the function Play
    } else if (nDirection == 2) { //If view score
      viewScores(cPlayers, & pNumber); //Calls the function viewScores
    } else if (nDirection == 3) { //If exit
      exitGame(cPlayers, & pNumber); //Calls the function exitGame
    } else { //Else displays invalid
      printf("Invalid input. Please input a valid number\n");
      system("pause");
    }
  }
}

//This is the main function of the program
int main() {
  time_t t;
  srand((unsigned) time( & t));
  int nNumber = 0; //Declares the number of current records
  int menuVal = 0; //Declares the current menu variable
  while (menuVal != 3) { //While menuVal is not exit
    numCount(cRecords, & nNumber); //Counts the number of records
    menuVal = mainMenu(); //Calls the menu and takes the returns value to menuVal
    if (menuVal == 1) //If menuVal is 1
      manageData(cRecords, & nNumber); //Calls manageData
    else if (menuVal == 2) { //Else if menuVal is 2
      playerPlay(cRecords, & nNumber); //calls playerPlay
      system("cls");
    } else if (menuVal == 3) //Else if menuVal is 3
      printf("Have a nice day!"); //Displays then exits
  }
}
