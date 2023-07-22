//* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10


void InitialiseStory(char* paragraph)
{
	char temp[2000] = "A long long time ago in South-Eastern Ethiopia a beggarly\nadventurer named Max Heather triggered by the pathetic\nstate of his current life, has followed the winds East to\na cave promising great riches. Although Max's financial\nsituation is poor, his love for his wife Joanna Nacario is\nrich. The same could not be said for her as his lack of\nmoola was a great challenge in their marriage. Determined\nnot to lose her to another man, Max enters the cave but\nsuddenly a boulder moves on its own accord and blocks the\nexit. He is stuck. The legends were all true, the cave is\nlittered with treasure. Max is filled with new found hope\nfor his marriage, finding treasure was the first step\nbut now he needs to find nway out... As it turns out\nthe cave used to be the stronghold of a mighty group of\nshapeshifting boulders named the Sugmas. During the 10,000\nyears of their existence they amassed great treasure but\nthey all died at the hands of their rivals the RockTrolls\nin an act of mass genocide. On the walls of the cave Max\nHeather who is fluent in Sugmanese reads that the\nonly way to escape is to help the Sugmas who are dead\nand stuck in their boulder form to return to their\nresting holes so that they can find peace. Max Heather\nwho is overflowing with purpose marches deeper into\nthe cave. Help him get his treasure, find an escape and\nreturn to his wife, OR ELSE...";
	strcpy(paragraph, temp);
}

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

int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i;

	for (i = 0; i < CAVE_SIZE; i++) {
		if ((cave[0][i] == 0) || (cave[CAVE_SIZE-1][i] == 0) || (cave[i][0] == 0) || (cave[i][CAVE_SIZE - 1] == 0)){
		    return 0;
		}
	}
	return 1;
}

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

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;

    for (i = 0; i < CAVE_SIZE; i = i + 9) {
		for ( j = 1; j < (CAVE_SIZE - 1); j++) {
			if (cave[i][j] == 21) {
			    return 1;
			}
		}
	}

	for (i = 1; i < (CAVE_SIZE - 1); i++) {
		for (j = 0; j < CAVE_SIZE; j = j + 9) {
			if (cave[i][j] == 21)  {
				return 1;
			}
		}
	}
	return 0;
	
}

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

	int counter = 2;
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


/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

/* You should add your own tests in here */
int main(void)
{
	char story[2000];
	char layout[200] = "1111111111100000000110000000011000000001100000000E10000000011000000001100000000110000000011111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};

	InitialiseStory(story);
	printf("%s\n", story);

	InitialiseCave(cave, layout);

	printf("Complete? %d\n", IsBorderComplete(cave));

	printf("Unique? %d\n", IsExitUnique(cave));

	printf("Accessible? %d\n", IsExitAccessible(cave));
	
	AddItem(cave, 7, 3, "player");
	AddItem(cave, 7, 4, "player");

 	AddItem(cave, 7, 3, "boulder");
    AddItem(cave, 2, 3, "boulder");
    AddItem(cave, 4, 6, "boulder");
    AddItem(cave, 5, 7, "boulder");
    AddItem(cave, 0, 0, "boulder");

    AddItem(cave, 7, 1, "hole");
    AddItem(cave, 9, 4, "hole");

    AddItem(cave, 6, 4, "treasure");
    AddItem(cave, 3, 5, "treasure");
    AddItem(cave, 1, 1, "treasure");

    RotateCave(cave);
	PrintCave(cave);

	return 0;

}