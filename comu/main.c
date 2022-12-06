#include "header.h"

int main() 
{
	int row = 2, col = 1;
	char level;
	CursorView(0);
	
	GotoXY(XP, YP - 3);
	printf("미로 찾기 게임\n");
	GotoXY(XP, YP - 2);
	printf("난이도를 선택하시오. (1,2,3)");
	scanf_s("%c", &level);
	start = clock();

	LoadMaze(level);

	while (1)
	{
		PrintMazeGame();
		MoveMaze(&row, &col);
	}

	return 0;
}

