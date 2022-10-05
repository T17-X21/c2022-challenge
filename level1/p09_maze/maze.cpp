#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdbool>
#include<conio.h>
#include<cstring>
#include<windows.h>
using namespace std;
const int Maxnum = 2;
const int MaxStep = 20;
const int MaxLength = 150, MaxWidth = 150;

char maze[MaxLength][MaxWidth];
int Length,Width;
bool RoadCreate;

void CreateMaze();
void PrintMaze();
void StartGame();
void CreateRoad(int x,int y,int nun,int way);
int Random();
void PlayMaze(int xx,int yy);

int Random()
{
	int RandomNumber;
	RandomNumber = rand()%4;
	return RandomNumber;
}
void CreateRoad(int x,int y,int num,int way)
{
	if (RoadCreate)
	{
		return;
	}
	if (x == Width - 1 && y == Length - 1)
	{
		RoadCreate = true;
		return;
	}
	if (x <= 0 || x >= Width || y <= 0 || y >= Length)
	{
		return;
	}
	if (num < Maxnum)
	{
		maze[x][y] = ' ';
		switch (way) {
		case 1:if (maze[x - 1][y] == '#' && maze[x - 2][y] == '#') CreateRoad(x - 1, y, num + 1, way); break;
		case 2:if (maze[x][y + 1] == '#' && maze[x][y + 2] == '#') CreateRoad(x, y + 1, num + 1, way); break;
		case 3:if (maze[x + 1][y] == '#' && maze[x + 2][y] == '#') CreateRoad(x + 1, y, num + 1, way); break;
		case 4:if (maze[x][y - 1] == '#' && maze[x][y - 2] == '#') CreateRoad(x, y - 1, num + 1, way); break;
		default:return;
		}
	}
	if (num == Maxnum)
	{
		maze[x][y] = ' ';
		for (int i=1;i<=MaxStep;i++)
		{
			switch (Random()) {
			case 0:if (maze[x - 1][y] == '#' && maze[x - 2][y] == '#') CreateRoad(x - 1, y, 0, 1); break;
			case 1:if (maze[x][y + 1] == '#' && maze[x][y + 2] == '#') CreateRoad(x, y + 1, 0, 2); break;
			case 2:if (maze[x + 1][y] == '#' && maze[x + 2][y] == '#') CreateRoad(x + 1, y, 0, 3); break;
			case 3:if (maze[x][y - 1] == '#' && maze[x][y - 2] == '#') CreateRoad(x, y - 1, 0, 4); break;
			default:return;
			}
		}
	}
}
void CreateMaze()
{
	for (int i = -1; i <= Width+1; i++)
		for (int j = -1; j <= Length+1; j++)
		{
			maze[i][j] = '#';
		}
	RoadCreate = false;
	CreateRoad(1,1,0,2);
	maze[1][1] = '*';
	maze[Width - 1][Length - 1] = 'E';
	PrintMaze();
}
void PrintMaze()
{
	Sleep(100);
	system("Cls");
	for (int i = 0; i <= Width; i++)
	{
		for (int j = 0; j <= Length; j++)
		{
			cout<<maze[i][j];
		}
		cout << endl;
	}
}
void PlayMaze(int xx, int yy)
{
	int x=xx, y=yy;
	char way;
	while (true)
	{
		while (way = _getch())
		{
			if (way == 'w')
			{
				if (maze[x - 1][y] != '#')
				{
					if (maze[x - 1][y] == 'E')
					{
						maze[x][y] = ' ';
						maze[x - 1][y] = '*';
						PrintMaze();
						printf("WIN\n");
						return;
					}
					maze[x][y] = ' ';
					maze[x - 1][y] = '*';
					x--;
				}
			}
			if (way == 's')
			{
				if (maze[x + 1][y] != '#')
				{
					if (maze[x + 1][y] == 'E')
					{
						maze[x][y] = ' ';
						maze[x + 1][y] = '*';
						PrintMaze();
						printf("WIN\n");
						return;
					}
					maze[x][y] = ' ';
					maze[x + 1][y] = '*';
					x++;
				}
			}
			if (way == 'a')
			{
				if (maze[x][y - 1] != '#')
				{
					if (maze[x][y - 1] == 'E')
					{
						maze[x][y] = ' ';
						maze[x][y - 1] = '*';
						PrintMaze();
						printf("WIN\\n");
						return;
					}
					maze[x][y] = ' ';
					maze[x][y - 1] = '*';
					y--;
				}
			}
			if (way == 'd')
			{
				if (maze[x][y + 1] != '#')
				{
					if (maze[x][y + 1] == 'E')
					{
						maze[x][y] = ' ';
						maze[x][y + 1] = '*';
						PrintMaze();
						printf("WIN\n");
						return;
					}
					maze[x][y] = ' ';
					maze[x][y + 1] = '*';
					y++;
				}
			}
			if (way == 'e')
			{
				return;
			}
			PrintMaze();
		}
	}
}
void StartGame()
{
	char c;
	printf("Enter the length and width of the maze.\n");
	scanf_s("%d%d", &Length, &Width);
	if (Length < 1 || Width < 1 || Length>MaxLength-2 || Width>MaxWidth-2)
	{
		printf("Out of the Range.\n");
	}
	else
	{
		CreateMaze();
		PlayMaze(1,1);
	}
	printf("Try again?\n");
	cin >> c;
	if (c == 'Y')
	{
		StartGame();
	}
}
int main()
{
	char c;
	printf("Press Y to start the game.\n");
	cin >> c;
	if (c== 'Y')
	{
		StartGame();
	}
	return 0;
}