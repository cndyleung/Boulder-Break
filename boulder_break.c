/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

/***********************************************************/
/***********************************************************/
/******* ADD THE REQUIRED FUNCTIONS BELOW THIS POINT *******/
/***********************************************************/
/***********************************************************/

// Your function definitions should go here...
//* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

// Task One: InitialiseStory
void InitialiseStory(char* paragraph)
{
	char temp[2000] = "A long long time ago in South-Eastern Ethiopia a beggarly\nadventurer named Max Heather triggered by the pathetic\nstate of his current life, has followed the winds East to\na cave promising great riches. Although Max's financial\nsituation is poor, his love for his wife Joanna Nacario is\nrich. The same could not be said for her as his lack of\nmoola was a great challenge in their marriage. Determined\nnot to lose her to another man, Max enters the cave but\nsuddenly a boulder moves on its own accord and blocks the\nexit. He is stuck. The legends were all true, the cave is\nlittered with treasure. Max is filled with new found hope\nfor his marriage, finding treasure was the first step\nbut now he needs to find nway out... As it turns out\nthe cave used to be the stronghold of a mighty group of\nshapeshifting boulders named the Sugmas. During the 10,000\nyears of their existence they amassed great treasure but\nthey all died at the hands of their rivals the RockTrolls\nin an act of mass genocide. On the walls of the cave Max\nHeather who is fluent in Sugmanese reads that the\nonly way to escape is to help the Sugmas who are dead\nand stuck in their boulder form to return to their\nresting holes so that they can find peace. Max Heather\nwho is overflowing with purpose marches deeper into\nthe cave. Help him get his treasure, find an escape and\nreturn to his wife, OR ELSE...";
	strcpy(paragraph, temp);
}


// Task Two: PrintCave
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE]) 
{
		int i, j;
	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			if (cave[i][j] == 1) {
				printf("#");
			} else if (cave[i][j] == 88) {
				printf("X");
			} else if (cave[i][j] == 79) {
				printf("O");
			} else if (cave[i][j] == 42) {
				printf("*");
			} else if (cave[i][j] == 43) {
				printf("+");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// Task Three: InitialiseCave
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout)
{
	int i, j;
	int k = 0;
	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			cave[i][j] = (layout[k] - 48);
			k++;
		}
	}
}

// Task Four: IsBorderComplete
int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;

	for (i = 0; i < CAVE_SIZE; i = i + CAVE_SIZE - 1) {
		for ( j = 0; j < CAVE_SIZE; j++) {
			if ((cave[i][j] != 1) && (cave[i][j] != 21)) {
				return 0;
			}
		}
	}
	for (i = 1; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j = j + CAVE_SIZE - 1) {
			if ((cave[i][j] != 1) && (cave[i][j] != 21)) {
				return 0;
			}
		}
	}
	return 1;
}

// Task Five: IsExitUnique
int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;
	int count = 0;
	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			if (cave[i][j] == 21 ) {
				count++;
			}
		}
	}
	if (count == 1) {
		return 1;
	}
	return 0;
}

// Task Six: IsExitAccessible
int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;

    for (i = 0; i < CAVE_SIZE; i = i + CAVE_SIZE - 1) {
		for ( j = 1; j < (CAVE_SIZE - 1); j++) {
			if (cave[i][j] == 21) {
			    return 1;
			}
		}
	}

	for (i = 1; i < (CAVE_SIZE - 1); i++) {
		for (j = 0; j < CAVE_SIZE; j = j + CAVE_SIZE - 1) {
			if (cave[i][j] == 21)  {
				return 1;
			}
		}
	}
	return 0;	
}

// Task Seven: AddItem
void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element)
{
	int i, j;
	int count = 0;

	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			if (cave[i][j] == 88)  {
				count++;
			}
		}
	}

	if((strcmp(element, "player") == 0) && (row < CAVE_SIZE) && (col < CAVE_SIZE) && (cave[row][col] != 1) && (cave[row][col] != 21) && (cave[row][col] != 79) && (cave[row][col] != 42) && (cave[row][col] != 43) && (count == 0)) {
		cave[row][col] = 88;
	}
	
	if((strcmp(element, "boulder") == 0) && (row < CAVE_SIZE) && (col < CAVE_SIZE) && (cave[row][col] != 1) && (cave[row][col] != 21) && (cave[row][col] != 88) && (cave[row][col] != 42) && (cave[row][col] != 43)) {
		cave[row][col] = 79;
	}
	
	if((strcmp(element, "hole") == 0) && (row < CAVE_SIZE) && (col < CAVE_SIZE) && (cave[row][col] != 1) && (cave[row][col] != 21) && (cave[row][col] != 88) && (cave[row][col] != 79) && (cave[row][col] != 43)) {
		cave[row][col] = 42;
	}
	
	if((strcmp(element, "treasure") == 0) && (row < CAVE_SIZE) && (col < CAVE_SIZE) && (cave[row][col] != 1) && (cave[row][col] != 21) && (cave[row][col] != 88) && (cave[row][col] != 42) && (cave[row][col] != 79)) {
		cave[row][col] = 43;
	}
}

// Task Eight: RotateCave
void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;
	int temp[CAVE_SIZE][CAVE_SIZE];

	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			temp[i][j] = cave[i][j];
		}
	}

	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			cave[j][CAVE_SIZE - i - 1] = temp[i][j];
		}
    }
}

// Task Nine: MakeMove
int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
	int i, j;
	int playerRow, playerCol;

	if(move == 'a') {
		RotateCave(cave);
	}

	if(move == 's') {
		RotateCave(cave);
		RotateCave(cave);
	}

	if (move=='d') {
        RotateCave(cave);
        RotateCave(cave);
        RotateCave(cave);
    }


	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			if (cave[i][j] == 88) {
				playerRow = i;
				playerCol = j;
			}
		}
	}

	if (cave[playerRow - 1][playerCol] == 0) {
		cave[playerRow - 1][playerCol] = 88;
		cave[playerRow][playerCol] = 0;

		if(move == 'a') {
			RotateCave(cave);
			RotateCave(cave);
			RotateCave(cave);
		}
		
		if(move == 's') {
			RotateCave(cave);
			RotateCave(cave);
		}
		
		if(move == 'd') {
            RotateCave(cave);
        }
		return 0;
    }

	int counter=2;
	if (cave[playerRow - 1][playerCol] == 79) {
		while (cave[playerRow - counter][playerCol] == 0) {
            cave[playerRow - counter][playerCol] = 79;
            cave[playerRow - counter + 1][playerCol] = 0;	
            counter++;
		}
		if (cave[playerRow - counter][playerCol] == 42) {
			cave[playerRow - counter][playerCol] = 0;
			cave[playerRow - counter + 1][playerCol] = 0;
		}
		if(move == 'a') {
			RotateCave(cave);
			RotateCave(cave);
			RotateCave(cave);
		}
		
		if(move == 's') {
			RotateCave(cave);
			RotateCave(cave);
		}
        if(move=='d') {
            RotateCave(cave);
        }
		return 0;
	
    }

	if (cave[playerRow - 1][playerCol] == 42) {
		cave[playerRow][playerCol] = 0;

		if(move == 'a') {
			RotateCave(cave);
			RotateCave(cave);
			RotateCave(cave);
		}
		
		if(move == 's') {
			RotateCave(cave);
			RotateCave(cave);
		}
		
		if (move=='d') {
            RotateCave(cave);
        }
		return 1;
	}

	if (cave[playerRow - 1][playerCol] == 21) {
		cave[playerRow - 1][playerCol] = 88;
		cave[playerRow][playerCol] = 0;

		if(move == 'a') {
			RotateCave(cave);
			RotateCave(cave);
			RotateCave(cave);
		}
		
		if(move == 's') {
			RotateCave(cave);
			RotateCave(cave);
		}
		 
		if (move=='d') {
            RotateCave(cave);
        }
		return 2;
	}

    if (cave[playerRow - 1][playerCol] == 43) {
        cave[playerRow - 1][playerCol] = 88;
        cave[playerRow][playerCol] = 0;

        if(move == 'a') {
            RotateCave(cave);
            RotateCave(cave);
            RotateCave(cave);
        }
        
        if(move == 's') {
            RotateCave(cave);
            RotateCave(cave);
        }
         
        if (move=='d') {
            RotateCave(cave);
        }
        return 0;
	}

	if(move == 'a') {
        RotateCave(cave);
        RotateCave(cave);
        RotateCave(cave);
    }
    
    if(move == 's') {
        RotateCave(cave);
        RotateCave(cave);
    }
     
    if (move=='d') {
        RotateCave(cave);
    }

    return 0;
}

char GetMove(void) {
	char move;
	printf("\nEnter Move: ");
	scanf("%c",&move);
	while((move!='w')&&(move!='a')&&(move!='s')&&(move!='d')) {
		scanf("%c", &move);
	}
	return move;
}

/* The Boulder Break simulation */
int main(void)
{
	char story[2000];
	char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};
	int gameOver = 0;

	InitialiseStory(story);
	InitialiseCave(cave, layout);
	AddItem(cave, 2, 4, "boulder");
	AddItem(cave, 5, 6, "boulder");
	AddItem(cave, 4, 8, "hole");
	AddItem(cave, 1, 4, "treasure");
	AddItem(cave, 4, 5, "player");

	printf("ENGGEN131 - C Project 2022\n");
	printf("                  ... presents ...\n");
	printf("______   _____  _     _        ______  _______  ______\n");
	printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
	printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
	printf("______   ______ _______ _______ _     _\n");
	printf("|_____] |_____/ |______ |_____| |____/ \n");
	printf("|_____] |    \\_ |______ |     | |    \\_\n");
	printf("\n");
	printf("%s\n", story);
	printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
	printf("Good luck!\n\n\n");

	/* Main game loop */
	PrintCave(cave);
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
		}
	}

	return 0;
}