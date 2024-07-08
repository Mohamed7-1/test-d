#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

char T1[6]; int B, M, jokerUsed = 0, NUMBROFTRY = 0;
    char player1[10], player2[10];
char T2[6];
    // Function to set text and background color in the console
      void color(int couleur_DuTexte, int couleur_DeFond)
 {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleur_DeFond * 16 + couleur_DuTexte);
 }

 // Function to sort scores and corresponding names in ascending order
void sortScores(char names[][50], int scores[], int count)
{
    int i, j, minIndex;
    char tempName[50];
    int tempScore;
    for (i = 0; i < count - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < count; j++) {
            if (scores[j] < scores[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Swap scores and names
            tempScore = scores[i];
            scores[i] = scores[minIndex];
            scores[minIndex] = tempScore;

            strcpy(tempName, names[i]);
            strcpy(names[i], names[minIndex]);
            strcpy(names[minIndex], tempName);
        }
    }
}
// Function to check for repeated digits in the entered string
int deja(char T[]) {
    int i;
    for (i = 0; i < 6 - 1; i++) {
        for (int j = i + 1; j < 6 - 1; j++) {
            if (T[i] == T[j]) {
                printf("Error: The entered digits are repeated.\n");
                return 0;
            }
        }
    }
    return 1;
}
// Function to input elements and validate them
void enterElements(char *T) {
    scanf("%s", T);
    while (strlen(T) != 6 - 1 || !isdigit(T[0]) || !isdigit(T[1]) || !isdigit(T[2]) || !isdigit(T[3]) || !isdigit(T[4]) || !deja(T)) {
    	system("cls");
        printf("\n\n\n\t\t\t");color(0,4);printf(" Error: Please enter a valid string of 5 distinct numerical characters ");
        color(15,0);
		printf("\n\n");
		color(3,0);
		 printf("\n\n\n\t\t\t");printf("==>Code: ");
		color(15,0);
        scanf("%s", T);
    }
}

// Function to display the best score
void displayBestScore() {
    FILE *file = fopen("score.txt", "r");
    int count = 0;
    char names[100][50];
    int scores[100];

    if (file != NULL) {
        while (fscanf(file, "%s Your score is: %d\n", names[count], &scores[count]) == 2) {
            count++;
        }
        fclose(file);

        // Sorting the scores
        sortScores(names, scores, count);

        FILE *outputFile = fopen("best_score.txt", "w");
        if (outputFile != NULL) {
            for (int i = 0; i < count; i++) {
                fprintf(outputFile, "%s Your score is: %d\n", names[i], scores[i]);
            }
            fclose(outputFile);
          printf("\n\n\t\t\t\t\t\t");  printf("The sorted scores have been saved in the file 'best_score.txt'.\n");
        } else {
         printf("\n\n\t\t\t\t\t\t");   printf("Error opening the file best_score.txt for writing.\n");
        }
    } else {
        printf("\n\n\t\t\t\t\t\t");printf("Error opening the file score.txt.\n");
    }
}


// Function to use a joker for additional attempts
void joker(int *Ntry, int *jokerUsed, char *T)
 {
    int pos;
    system("cls");
    color(14, 0);
     getchar(); 
    printf("Enter the position to display (1 to 5): ");
     
    scanf("%d", &pos);

    if (pos < 1 || pos > 5) {
        printf("Invalid position. Please enter a position between 1 and 5.\n");
        return; // Exit the joker function
    }
    color(13, 0);
    if (*jokerUsed) {
        printf("You have already used the joker.\n");
        return; // Exit the joker function
    }
    color(1, 0);
    printf("Number at position %d: %c\n", pos, T[pos - 1]);
    system("pause");

    *jokerUsed = 1;
}


int alreadyExists(const char *T) {
    // Function to check for repeated digits in the entered string
    for (int i = 0; i < strlen(T); i++) {
        for (int j = i + 1; j < strlen(T); j++) {
            if (T[i] == T[j]) {
                return 1; // Repeated digits found
            }
        }
    }
    return 1; // No repeated digits found
}
// Function to input elements and validate them in a certain format
void enterElements2(char *T) {
    scanf("%s", T);
     // Loop runs until the input does not meet the required criteria
    while (strlen(T) != 6 - 1 || !isdigit(T[0]) || !isdigit(T[1]) || !isdigit(T[2]) || !isdigit(T[3]) || !isdigit(T[4]) || !alreadyExists(T)) {
        printf("\n\n\n\t\t\t");color(0,4); printf("Error: Please enter a valid string of 5 numeric characters\n");
        color(15,0);
		printf("\n\n");
		color(3,0);
		 printf("\n\n\n\t\t\t");printf("==>Code: ");
		color(15,0);
        scanf("%s", T);
    }
}

int main(){
  
	int decision_game;
   the_start: // Label to start the game loop
	printf("saisir le niveau (1  ou  2)\n ");
	decision_game=getch();// Get a single character input for the level

   
	switch(decision_game)
	{
        case '1':

      system("cls");printf("\n\t\t\t\t\t");
	  color(5,0)  ;
    printf("Enter the name of player 1: ");
   color(15,0); scanf("%9s", &player1);
    system("cls");printf("\n\t\t\t\t\t");color(5,0);
    printf("Enter the name of player 2: ");
    color(15,0);scanf("%9s", &player2);
    system("cls");

    while (1) {
    	printf("\n\t\t\t\t\t");
       color(1,0); printf("Enter elements for player 1: ");
        color(15,0);
        enterElements(T1);

        if (deja(T1)) {
            break;
        } else {
		  	system("cls");
        printf("\n\t\t\t\t");color(0,4);
            printf("Error, please try again.\n");
        }
    }

    while (NUMBROFTRY <= 20) {
        while (1) {
                if (NUMBROFTRY >= 5 && NUMBROFTRY <= 17 && !jokerUsed)
{
            char usejoker;

            color(15,0);
            printf("\n\n\t\t\t\t");
            color(14,0);printf("%c Do you want to use the joker ? ",191);
			color(15,0);printf("\n\n\t\t\t\t\t\t");
			color(0,15);printf(" YES (1) ");
			color(15,0);printf("\t");
			color(0,15);printf(" NO (0) ");
			color(15,0);printf("\n\n\t\t\t\t\t\t");

            usejoker=getch();
           while (1) {
           usejoker = getch();
          if (usejoker == '1' || usejoker == '0') {
            break;
                     }
                      }

    if (usejoker == '1') {
        joker(&NUMBROFTRY, &jokerUsed, T1);
        NUMBROFTRY+=3;
                         }
 }


        system("cls");
		     printf("\n\t\t\t\t\t");
			 color(1,0);
            printf("Enter elements for player 2: ");
            color(15,0);
			enterElements(T2);
            if (deja(T2)) {
                break;
            } else {
                printf("Error, please try again.\n");
            }
        }
        B = 0;
        M = 0;
        for (int i = 0; i < 6 - 1; i++) {
            if (T1[i] == T2[i]) {
                B = B + 1;
            } else {
                for (int j = 0; j < 6 - 1; j++) {
                    if (T1[i] == T2[j]) {
                        M = M + 1;
                    }
                }
            }
        }


        NUMBROFTRY++;
        if (B == 5) {
            system("cls");
            printf("\n\n\t\t\t\t\t\t");color(2,0);printf("\nAll elements are correctly placed. Congratulations, you won!\n");

            FILE *file = fopen("score.txt", "a");
            if (file != NULL) {
              printf("\n\n\t\t\t\t\t\t"); color(2,0);fprintf(file, "%s Your score is: %d\n", player2, NUMBROFTRY);
                fclose(file);
               printf("\n\n\t\t\t\t\t\t"); color(2,0);printf("The score has been saved in the file 'score.txt'.\n");
            } else {
              printf("\n\n\t\t\t\t\t\t"); color(4,0);printf("Error opening the file.\n");
            }

            break;
        }
		else {
		system("cls");color(15,0);
			printf("\n\n\n\n\n\t\t\t\t\t\t\t");
		color(14,0);
		printf("TRY N':");color(0,8);printf(" %2d ",NUMBROFTRY);color(15,0);
		printf("\n\n\t\t\t\t");color(14,0);
        printf("! The correctly placed numbers are B =  ");color(2,0);printf(" %d",B);color(14,0);printf(" !");color(15,0);
        printf("\n\n\t\t\t\t");color(14,0);
	    printf("! The incorrectly placed numbers are M = ");color(4,0);printf("%d",M);color(14,0);printf(" !");color(15,0);
	    sleep(2);
        system("cls");

		}
		if (NUMBROFTRY >= 20) {
            system("cls");
          printf("\n\n\t\t\t\t\t\t"); color(4,0); printf("\nMaximum number of attempts reached.\n");
                  FILE *file = fopen("score.txt", "a");
                 if (file != NULL) {
               printf("\n\n\t\t\t\t\t\t");  color(12,0);  fprintf(file, "%s Your score is: %d\n", player2, NUMBROFTRY +1);
                
                fclose(file);
              printf("\n\n\t\t\t\t\t\t");  color(12,0);   printf("The score has been saved in the 'score.txt' file.\n");
            } else {
                printf("\n\n\t\t\t\t\t\t"); color(12,0);  printf("Error opening the file.\n");
            }

            break;
            
          color(17,0);  printf("%s is the winner, and the elements are: ", player1);

            for (int i = 0; i < 6 - 1; i++) {
                printf("%c", T1[i]);
            }
            printf("\n");
            break;
        }
    }

    displayBestScore();
	        // After finishing Level 1, show the results
            // and ask if the player wants to play Level 2
            printf("\n\n\t\t\t\t\t\t");printf("Level 1 finished!\n");
           printf("\n\n\t\t\t\t\t\t"); printf("Do you want to play Level 2? (Y/N): ");
            char choice = getch();

            if (choice == 'Y' || choice == 'y') {
                // Go to Level 2
              goto level_2;
                break;
            } else {
                // Go back to the menu
                goto the_start;
            }

		case '2':
        level_2:
         NUMBROFTRY=0;
      system("cls");printf("\n\t\t\t\t\t");
	  color(5,0)  ;

    printf("Enter the name of player 1: ");
    color(15,0); scanf("%9s", &player1);

    system("cls");printf("\n\t\t\t\t\t");color(5,0);
    printf("Enter the name of player 2: ");
    color(15,0);scanf("%9s", &player2);
    system("cls");

   	printf("\n\t\t\t\t\t");

    color(1,0); printf("Enter elements for player 1: ");
    color(15,0);
    enterElements2(T1);

    system("cls");

    while (NUMBROFTRY <= 20) {
                if (NUMBROFTRY >= 5 && NUMBROFTRY <= 17 && !jokerUsed)
{
            char usejoker;

            color(15,0);
            printf("\n\n\t\t\t\t");
            color(14,0);printf("%c Do you want to use the joker ? ",191);
			color(15,0);printf("\n\n\t\t\t\t\t\t");
			color(0,15);printf(" YES (1) ");
			color(15,0);printf("\t");
			color(0,15);printf(" NO (0) ");
			color(15,0);printf("\n\n\t\t\t\t\t\t");

            usejoker=getch();
           while (1) {
           usejoker = getch();
          if (usejoker == '1' || usejoker == '0') {
            break;
                     }
                      }

    if (usejoker == '1') {
        joker(&NUMBROFTRY, &jokerUsed, T1);
        NUMBROFTRY+=3;
                         }
 }
       system("cls");
		     printf("\n\t\t\t\t\t");
			 color(1,0);
            printf("Enter elements for player 2: ");
            color(15,0);
        enterElements2(T2);

        B = 0;
        M = 0;

        char seen[6] = {0};
        for (int i = 0; i < 6 - 1; i++) {
            if (T1[i] == T2[i]) {
                B++;
                seen[i] = 1;
            } else {
                for (int j = 0; j < 6 - 1; j++) {
                    if (T1[i] == T2[j] && i != j && !seen[j] && !seen[i]) {
                        M++;
                        seen[j] = 1;
                        break;
                    }
                }
            }
        }

        NUMBROFTRY++;

        if (B == 5) {
            system("cls");
            printf("\n\n\t\t\t\t");
            printf("\n\n\t\t\t\t\t\t");color(2,0);printf("All elements are correctly placed. Congratulations, you win!\n");

            FILE *file = fopen("score.txt", "a");
            if (file != NULL) {
             printf("\n\n\t\t\t\t\t\t");   fprintf(file, "%s Your score is: %d\n", player2, NUMBROFTRY);
                fclose(file);
             printf("\n\n\t\t\t\t\t\t");   printf("The score has been saved in the 'score.txt' file.\n");
            } else {
             printf("\n\n\t\t\t\t\t\t");   printf("Error opening the file.\n");
            }

            break;
        }

         else{

		system("cls");color(15,0);
			printf("\n\n\n\n\n\t\t\t\t\t\t\t");
		color(14,0);
		printf("TRY N':");color(0,8);printf(" %2d ",NUMBROFTRY);color(15,0);
		printf("\n\n\t\t\t\t");color(14,0);
        printf("! The correctly placed numbers are B =  ");color(2,0);printf(" %d",B);color(14,0);printf(" !");color(15,0);
        printf("\n\n\t\t\t\t");color(14,0);
	    printf("! The incorrectly placed numbers are M = ");color(4,0);printf("%d",M);color(14,0);printf(" !");color(15,0);
	    sleep(2);
        system("cls");


         }



            if (NUMBROFTRY >= 20) {
            system("cls");
            printf("\n\n\t\t\t\t");
            printf("\n\n\t\t\t\t\t\t");color(4,0);printf("Maximum number of tries reached.\n");

            FILE *file = fopen("score.txt", "a");
            if (file != NULL) {
            printf("\n\n\t\t\t\t\t\t");    fprintf(file, "%s Your score is: %d\n", player2, NUMBROFTRY +1);
                fclose(file);
              printf("\n\n\t\t\t\t\t\t");  printf("The score has been saved in the 'score.txt' file.\n");
            } else {
              printf("\n\n\t\t\t\t\t\t");  printf("Error opening the file.\n");
            }

            break;
            
            printf("\n\n\t\t\t\t\t\t");color(20,0);printf("%s is the winner, and the elements are: ", player1);

            for (int i = 0; i < 6 - 1; i++) {
                printf("%c", T1[i]);
            }
            printf("\n");
            break;
        }

        }
    displayBestScore();

    break;



    default:// If an invalid level is selected, return to the start of the game loop
    goto the_start;
    }
    

	return 0;

    }