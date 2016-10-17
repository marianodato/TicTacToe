/*!
*	Copyright (c) 2010, 2016 Mariano Dato <marianodato@gmail.com>
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
*	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
*	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
*	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
*	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
*	IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*	THE SOFTWARE.
*/

#include <stdio.h>

void draw_board(char [][3]);
int analize_board(char [][3]);
int calculate_winner(int, int, int);

int main()
{
	char board [3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	int num_moves = 1;
	int player = 0;
	int i = 0;
	int j = 0;

	printf("\n Player 1 plays as X\n");
	printf(" Player 2 plays as O\n\n");

	draw_board(board);
	
	while(num_moves != 10)
	{
		switch(analize_board(board))
		{
			case 0:
				if((num_moves % 2) != 0)
					player = 1;	
				else
					player = 2;

				while(1)
				{
					printf(" Player %d insert number of row: ", player);
					scanf("%d", &i);
					i--;

					printf(" Player %d insert number of column: ", player);
					scanf("%d", &j);
					j--;
						
					if((i >= 0 && i <= 2)  && (j >= 0 && j <= 2) && board[i][j] == ' ')
						break;

					printf("\n Please insert correct values\n");
				}

				num_moves++;

				if (player == 1)
					board[i][j] = 'X';
				else
					board[i][j] = 'O';

				draw_board(board);
				break;
			case 1:
				printf(" Player 1 wins!\n\n");
				return 0;
			case 2:
				printf(" Player 2 wins!\n\n");
				return 0;
		}
	}
	
	printf(" A draw!\n\n");
	
	return 0;
}

void draw_board(char board[][3])
{
	int i = 0;
	int j = 0;

	printf("      1   2   3\n\n");

	for(i = 0; i < 3; i++)
	{
		printf(" %d    ", i+1);
		for(j = 0; j < 3; j++){
			printf("%c ", board[i][j]);
			if(j != 2)
				printf("| ");
		}
		printf("\n");

		if(i != 2)
			printf("    ----+---+----\n");
	}

	printf("\n");

	return;
}

int analize_board(char board[][3])
{
	int winner = 0;

	winner = calculate_winner(board[0][0], board[0][1], board[0][2]);
	if(winner != 0)
		return winner;
	
	winner = calculate_winner(board[1][0], board[1][1], board[1][2]);
	if(winner != 0)
		return winner;
	
	winner = calculate_winner(board[2][0], board[2][1], board[2][2]);
	if(winner != 0)
		return winner;
	
	winner = calculate_winner(board[0][0], board[1][0], board[2][0]);
	if(winner != 0)
		return winner;
	
	winner = calculate_winner(board[0][1], board[1][1], board[2][1]);
	if(winner != 0)
		return winner;
	
	winner = calculate_winner(board[0][2], board[1][2], board[2][2]);
	if(winner != 0)
		return winner;
	
	winner = calculate_winner(board[0][0], board[1][1], board[2][2]);
	if(winner != 0)
		return winner;
	
	winner = calculate_winner(board[0][2], board[1][1], board[2][0]);
	if(winner != 0)
		return winner;

	return 0;
}

int calculate_winner(int pos1, int pos2, int pos3)
{
	if(pos1 == 'X' && pos2 == 'X' && pos3 == 'X')
		return 1;
	else if(pos1 == 'O' && pos2 == 'O' && pos3 == 'O')
		return 2;
	else
		return 0;
}
