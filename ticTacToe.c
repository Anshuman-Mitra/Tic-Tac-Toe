/*TIC TAC TOE GAME  o | x*/
/*START PROGRAM*/

//Import specifc libraries
//for standard input output
#include <stdio.h>
//for system and other functions
#include <stdlib.h>
//for bool
#include <stdbool.h>

//INT Variables
int
	finalWinner = 1,
	player1Score = 0,
	player2Score = 0,
	gameRound = 1,
	isFirstCol = 1,
	flags = 0,
	playerEntry,
	column,
	row,
	playerNumber = 1,
	playerCurrent = 1,
	resultBoard[3][3],
	userCol,
	shouldPrintFinalWinner = 1,
	userRow;	

//CHAR array Variables
char
	player1Name[20],
	player2Name[20];

//BOOL Variables
bool
	shouldCheck = false;

//Defining functions
int checkPlayer1();
int checkPlayer2();
int checkPlayer();
void printGameRound();

//checking win of the respective player and prinitng final winner after round 3
int checkWin()
{	
	//Check if checkPlayer returns 1
	if(checkPlayer() == 1)
	{
		//check current playre number and increase score of that player by 1
		if(playerNumber == 1)
			player1Score++;
		else
			player2Score++;

		//printing message: You Win! with color
		printf("\033[0;36m");
		printf("\n\n!!!!!!!!!!!!𝗬𝗢𝗨 𝗪𝗜𝗡 𝗠𝗔𝗧𝗖𝗛 %d!!!!!!!!!!!!\n", gameRound);
		//waiting for users input to continue
		getchar();
		getchar();
		printf("\033[0;37m");

		//increasing gameround by 1
		gameRound++;	
		//Checking if gameround is greater than 3
		if(gameRound > 3)
		{
			//Check if player1Score > player2Score
			if(player1Score > player2Score)
			{
				//Finalwinner to 1
				finalWinner = 1;
			}
			else if(player1Score < player2Score)
			{
				//Finalwinner to 2
				finalWinner = 2;
			}
			else if(player1Score == player2Score && player1Score == 0 && player2Score == 0)	
			{
				//No one i winner in this case
				printf("No one is winner\n\n\n\n");
			}
			
			//printing final winner with their name
			if(finalWinner == 1)
				printf("𝗧𝗛𝗘 𝗙𝗜𝗡𝗔𝗟 𝗪𝗜𝗡𝗡𝗘𝗥 𝗜𝗦: %s!!!!\n\n\n\n", player1Name);
			else
				printf("𝗧𝗛𝗘 𝗙𝗜𝗡𝗔𝗟 𝗪𝗜𝗡𝗡𝗘𝗥 𝗜𝗦: %s!!!!\n\n\n\n", player2Name);
		
			//exiting the whole program
			exit(0);
		}
	}
	//returning check player response
	return checkPlayer();
}

//checking players input
int checkPlayer()
{
	//Create variables INT
	int
		i = 0,       
		jMax = 2,
        iMax = 2,
		j = 0;

	//Check Horizontally, Vertically and Diagonally
	if(resultBoard[i][j] == resultBoard[i+1][j+1] && resultBoard[i+1][j+1] == resultBoard[i+2][j+2])
		return 1;	
	else if(resultBoard[iMax][jMax] == resultBoard[iMax-1][jMax-1] && resultBoard[iMax-1][jMax-1] == resultBoard[iMax-2][jMax-2])
		return 1;
	else if(resultBoard[i][j] == resultBoard[i+1][j] && resultBoard[i+1][j] == resultBoard[i+2][j])
		return 1;
	else if(resultBoard[i][j+1] == resultBoard[i+1][j+1] && resultBoard[i+1][j+1] == resultBoard[i+2][j+1])
		return 1;
	else if(resultBoard[i+2][j] == resultBoard[i+1][j+2] && resultBoard[i+1][j+2] == resultBoard[i+2][j+2])
		return 1;   	
	else if(resultBoard[i][j] == resultBoard[i][j+1] && resultBoard[i][j+1] == resultBoard[i][j+2])
		return 1;   
	else if(resultBoard[i+1][j] == resultBoard[i+1][j+1] && resultBoard[i+1][j+1] == resultBoard[i+1][j+2])
	    return 1;   	
	else if(resultBoard[i+2][j] == resultBoard[i+2][j+1] && resultBoard[i+2][j+1] == resultBoard[i+2][j+2])
		return 1;
	else
		return 0;
}

//asking the players name
void askPlayersName()
{
	//asking player 1's name
	printf("👤 𝗣𝗟𝗔𝗬𝗘𝗥 𝟭 𝗡𝗔𝗠𝗘: ");
	scanf("%s", player1Name);

	//asking player 2's name
	printf("👤 𝗣𝗟𝗔𝗬𝗘𝗥 𝟮 𝗡𝗔𝗠𝗘: ");
	scanf("%s", player2Name);
}

//printing current game round out of 3
void printGameRound()
{
	//printing current round out of 3
	printf("  𝗥𝗢𝗨𝗡𝗗: %d/𝟯\n\n\n", gameRound);
}

//printing tic tac toe logo on the first page
void printLogo()
{
	//Printing Logo
	printf("\n");
	printf(" ⭕️ | ❌ | ⭕️\n");
	printf("----|----|----\n");
	printf(" ❌ | ❌ | ⭕️\n");
	printf("----|----|----\n");
	printf(" ⭕️ | ❌ | ❌\n");

	printf("\n\n");
}

void printWindowTop()
{
	printf("                                                                                                      □ - ✕  |\n");
	printf("--------------------------------------------------------------------------------------------------------------\n\n");
}

//printing the result board on the screen
void printBoard()
{
	//Printing HeadingsWith colors
	printWindowTop();
	printf("\033[0;34m");
	printf("  𝗧𝗜𝗖 𝗧𝗔𝗖 𝗧𝗢𝗘  \n");
	printGameRound();
	printf("\033[0;37m");

	//Print columns
	printf("\033[0;31m");
	printf("    A | B | C    \n");
	printf("\n");
	printf("\033[0;37m");

	//printing the result board
	for(int i = 0;i < 3;i++)
	{
		for(int j = 0;j < 3;j++)
		{
			//Print row number
			printf("\033[0;32m");
			if(isFirstCol == 1)
			{
				printf("%d  ", i+1);
				isFirstCol = 0;
			}
		
			//Check entry 1 or 0
			if(resultBoard[i][j] == 1  )
				printf(" ✕ ");
			else if(resultBoard[i][j] == 0)
				printf(" 𝗢 ");
			else
				printf("   ");
                
			printf("\033[0;37m");
			
			//check if j != 2 then print |
			if(j!=2)
				printf("|");

			//check if j is 2 then print new line
			if( j == 2)
			{
				//Change is first col
				isFirstCol = 1;

				//check if i != 2 then print ---|---|---
				if(i != 2)
					printf("\n   ---|---|---\n");
				else
					printf("\n\n");

			}
		}
	}
}

//setting the board entry for the players
void setBoardEntry()
{
	//Going into while
	while(1)
	{
		fflush(stdin);
		if(playerNumber == 1)
			printf("%s's Entry [Player 1 - X    Player 2 - O]: \n\n", player1Name);
		else
			printf("%s's Entry [Player 1 - X    Player 2 - O]: \n\n", player2Name);

		//asking player's entry on column and row basis on who is entering
		printf("Enter Column and Row: ");
		fflush(stdin);
		scanf("%c %c", &userCol, &userRow);

		//converting them into rows and columns
		//Converting small to captial Letters
		if(userCol > 67 && userCol < 100)
		{
			userCol -= 32;
			userCol = userCol - 65;
		}
		else
			userCol = userCol - 65;

		userRow = userRow - 49;

		//Chaning player entry type basis on player number
		if(playerNumber == 1)
		{
			playerEntry = 1;
		}
		else
		{
			playerEntry = 0;
		}

		//Check if any value is already stored at the poition goven by the player [1 and O]
		if(resultBoard[userRow][userCol] == 1 || resultBoard[userRow][userCol] == 0)
		{
			printf("❌: Value is already stored at row: %d, col: %d.\n Press any key to cont.....", userRow, userCol);
			getchar();
			getchar();
			fflush(stdin);
		}
		else
		{
			//add player enrty to the result board array
			resultBoard[userRow][userCol] = playerEntry;
		}
		
		//Checking if player entry is vaild
		if(playerEntry == 1 || playerEntry == 0)
			break;
	}

}

//reinitializing all the variables that is needed
void reInitialize()
{
	isFirstCol = 1;
	flags = 0;
	playerEntry = 1;
	playerNumber = 1;
	playerCurrent = 1;
}

//start the main code
void initialize()
{
	//creating variables INT
	int
		flag = 0,
		intializemnt = 2;

	//printing game logo and rules
	printWindowTop();
	printLogo();
	printf("\033[0;34m");
	printf("𝗧𝗜𝗖 𝗧𝗔𝗖 𝗧𝗢𝗘 - ⭕️|❌  \n\n");
	printf("\033[0;37m");
	printf("\033[0;32m");
	printf("There will be 3 matches conducted. the player who gets the most points in all the matches is the winner!\nFirst Enter the Column And Then The row for Example: A1: A - Column, 1 - Row\n");
	printf("Player 1 is - X    Player 2 is - O\n");
	printf("Get started by entering you names!\n\n");
	printf("\033[0;37m");

	//ask players name
	askPlayersName();

	//3 Round using for loop
	for(int i =0;i<3;i++)
	{
		//Clearing the screen
		system("clear");
		//reintialize
		reInitialize();
		//intializing this variable with 2
		intializemnt = 2;

		//Intializing diffrent numbers in the 3x3 array
		for(int i = 0;i < 3;i++)
			for(int j = 0;j < 3;j++)
			{
				resultBoard[i][j] = intializemnt+100;
				intializemnt++;
			}

		//Printing board before entering while
		printBoard();

		while(1)
		{
			//Asking Player to enter the column and row to put one of the X or O
			setBoardEntry();

			//Clearing the screen
			system("clear");
			
			//printing the board
			printBoard();

			//Calling checkWin function to check the winner player. if true then break the while loop
			if(checkWin() == 1)
				break;

			//Change Current Player Number
			if(playerNumber == 1)
				playerNumber = 2;
			else
				playerNumber = 1;	
		}
	}
}

//main function only calls the initialize function to start the main code
int main()
{
	//calling initialize function
	initialize();
	return 0;
}

//END PROGRAM