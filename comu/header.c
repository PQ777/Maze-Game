#include "header.h"

void LoadMaze(char num)
{
	char path[20] = "./Maze";
	strcat(path, &num);
	strcat(path, ".txt");

	char str_tmp[50] = { 0, };
	FILE* f = fopen(path, "r");

	for (int i = 0; i < SIZE; i++)
	{
		fgets(str_tmp, 50, f);
		char* ptr = strtok(str_tmp, "\t");
		for (int j = 0; j < SIZE; j++)
		{
			maze[i][j] = *ptr;
			ptr = strtok(NULL, "\t");
		}
	}
	fclose(f);
}

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void PrintMazeGame()
{
	for (int i = 0; i < SIZE; i++)
	{
		GotoXY(XP, YP + i);
		for (int j = 0; j < SIZE; j++)
		{
			if (maze[i][j] == '1')
				printf("■");
			else if (maze[i][j] == 'y')
				printf("★");
			else if (maze[i][j] == '0')
				printf("□");
			else
				printf("●");
		}
		puts("");
	}
}

void CursorView(char show)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void MoveMaze(int* row, int* col)
{
	int nkey;

	if (_kbhit())
	{
		nkey = _getch();

		if (nkey == ARROW)
		{
			nkey = _getch();
			switch (nkey)
			{
				case UP:
					if (!(IsBlock(*row - 1, *col)))
					{
						maze[*row][*col] = '0';
						maze[*row - 1][*col] = 'x';
						*row -= 1;
					}
					else if (IsFinish(*row - 1, *col))
					{
						maze[*row][*col] = '0';
						maze[*row - 1][*col] = 'x';
						PrintMazeGame();
						Complete();
					}
					break;

				case DOWN:
					if (!(IsBlock(*row + 1, *col)))
					{
						maze[*row][*col] = '0';
						maze[*row + 1][*col] = 'x';
						*row += 1;
					}
					else if (IsFinish(*row + 1, *col))
					{
						maze[*row][*col] = '0';
						maze[*row + 1][*col] = 'x';
						PrintMazeGame();
						Complete();
					}
					break;

				case LEFT:
					if (!(IsBlock(*row, *col - 1)))
					{
						maze[*row][*col] = '0';
						maze[*row][*col -1] = 'x';
						*col -= 1;
					}
					else if (IsFinish(*row, *col - 1))
					{
						maze[*row][*col] = '0';
						maze[*row][*col - 1] = 'x';
						PrintMazeGame();
						Complete();
					}
					break;

				case RIGHT:
					if (!(IsBlock(*row, *col + 1)))
					{
						maze[*row][*col] = '0';
						maze[*row][*col + 1] = 'x';
						*col += 1;
					}
					else if (IsFinish(*row, *col + 1))
					{
						maze[*row][*col] = '0';
						maze[*row][*col + 1] = 'x';
						PrintMazeGame();
						Complete();
						exit(0);
					}
					break;
			}
		}
	}
}

int IsBlock(int i, int j)
{
	if (maze[i][j] == '1' || maze[i][j] == 'y')
		return 1;
	else
		return 0;
}

int IsFinish(int i, int j)
{
	if (maze[i][j] == 'y')
		return 1;
	else
		return 0;
}

void Complete()
{
	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;

	GotoXY(XP, YP + SIZE);
	printf("Complete!\n");
	GotoXY(XP, YP + SIZE + 1);
	printf("경과시간 : %.2f초", res);
	exit(0);
}