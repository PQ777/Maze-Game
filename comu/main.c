#include "header.h"

int main() 
{
	int row = 2, col = 1;
	char level;
	CursorView(0);
	
	GotoXY(XP, YP - 3);
	printf("�̷� ã�� ����\n");
	GotoXY(XP, YP - 2);
	printf("���̵��� �����Ͻÿ�. (1,2,3)");
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

