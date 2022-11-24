#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
using namespace std;
#define MAX_ROWS 16
#define MAX_CLOS 16
#define MAX_LEVEL 5
#define FILE_NAME_LEN 100
#define ROAD 0
#define WALL 1
#define BOX 2
#define TERM 3
#define MOUS 4
#define IGN 224
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define MINT MOUS+TERM
#define BINT BOX+TERM
#define QUIT 'q'
#define RESET 'r'
#define BACK 'b'
#define NM 0
#define MM 1
#define BM 2
#define MAX_BACK_STEP 100

struct Act {
	int dir;
	int sta;
};
struct Act acts[MAX_BACK_STEP] = {};
int stepsize = 0;
int newindex = -1;
int board[MAX_ROWS][MAX_CLOS] = {};
int row, col;
int mx = 0, my = 0;
int bcnt = 0;
int step[MAX_LEVEL + 1] = { 0 };

void load(int level)
{
	char fileName[FILE_NAME_LEN] = "";
	sprintf_s(fileName, "C:\\Users\\86139\\c2022-challenge\\level1\\p10_pushBoxes\\%d.txt", level);
	FILE *fp = NULL;
	fopen_s(&fp,fileName, "r");
	if (fp == NULL)
	{
		printf("%s文件打开失败\n", fileName);
		exit(-1);
	}
	fscanf_s(fp, "%d %d", &row, &col);
	int i, j;
	bcnt = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			fscanf_s(fp, "%d", &board[i][j]);
			if (board[i][j] == MOUS || board[i][j] == MINT)
			{
				mx = i;
				my = j;
			}
			else
			{
				if (board[i][j] == BOX || board[i][j] == BINT)
				{
					bcnt++;
				}
			}
		}
	}
	fclose(fp);
	stepsize = 0;
	newindex = -1;
}

int show(void)
{
	int i, j;
	int bs = 0;
	//Sleep(100);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			switch (board[i][j])
			{
			case ROAD:
				printf(" ");
				break;
			case WALL:
				printf("#");
				break;
			case BINT:
				bs++;
			case BOX:
				printf("@");
				break;
			case TERM:
				printf("O");
				break;
			case MOUS:
			case MINT:
				printf("&");
				break;
			}
		}
		printf("\n");
	}
	return bs;
}
int move(int stepx, int stepy)
{
	int nx = mx + stepx;
	int ny = my + stepy;
	if (board[nx][ny] == ROAD || board[nx][ny] == TERM)
	{
		board[mx][my] = board[mx][my] - MOUS;
		board[nx][ny] = board[nx][ny] + MOUS;
		mx = nx;
		my = ny;
		return MM;
	}
	else
	{
		if (board[nx][ny] == BOX || board[nx][ny] == BINT)
		{
			int nnx = nx + stepx;
			int nny = ny + stepy;
			if (board[nnx][nny] == ROAD || board[nnx][nny] == TERM)
			{
				board[nnx][nny] += BOX;
				board[nx][ny] -= BOX;
				board[mx][my] -= MOUS;
				board[nx][ny] += MOUS;
				mx = nx;
				my = ny;
				return BM;
			}
		}
		return NM;
	}
}

void moveback(int stepx, int stepy)
{
	int nx = mx + stepx;
	int ny = my + stepy;
	board[mx][my] -= MOUS;
	board[nx][ny] += MOUS;
	if (acts[newindex].sta == BM)
	{
		int bx = mx - stepx;
		int by = my - stepy;
		board[bx][by] -= BOX;
		board[mx][my] += BOX;
	}
	mx = nx;
	my = ny;
}

void back(int level)
{
	if (stepsize > 0)
	{
		switch (acts[newindex].dir)
		{
		case UP:
			moveback(+1, 0);
			break;
		case DOWN:
			moveback(-1, 0);
			break;
		case LEFT:
			moveback(0, +1);
			break;
		case RIGHT:
			moveback(0, -1);
			break;
		}
		step[level]--;
		stepsize--;
		newindex--;
		if (newindex == -1)
		{
			newindex = MAX_BACK_STEP - 1;
		}
	}
}

void play(int level)
{
	while (1)
	{
		system("cls");
		int ret = show();
		if (ret == bcnt)
		{
			if (level < MAX_LEVEL) printf("恭喜过关，按任意键进入下一关\n");
			//printf("分数：%d", step[level]);
			_getch();
			return;
		}
		int key = _getch();
		if (key == IGN)
		{
			key = _getch();
		}
		if (key == QUIT)
		{
			printf("GAME OVER\n");
			exit(0);
		}
		else
		{
			if (key == RESET)
			{
				load(level);
			}
			else
			{
				if (key == BACK)
				{
					back(level);
				}
			}
		}
		ret = NM;
		switch (key) {
		case UP:
			ret = move(-1, 0);
			break;
		case DOWN:
			ret = move(+1, 0);
			break;
		case LEFT:
			ret = move(0, -1);
			break;
		case RIGHT:
			ret = move(0, +1);
			break;
		}
		if (ret == MM || ret == BM)
		{
			struct Act act = { key,ret };
			newindex++;
			if (newindex >= MAX_BACK_STEP)
			{
				newindex = 0;
			}
			acts[newindex] = act;
			if (stepsize < MAX_BACK_STEP)
			{
				stepsize++;
				step[level]++;
			}
		}
	}
}

void run(void)
{
	int level;
	for (level = 1; level <= MAX_LEVEL; level++)
	{
		load(level);
		play(level);
	}
	printf("恭喜过关，游戏结束！");
	FILE* fp1 = NULL;
	fopen_s(&fp1, "C:\\Users\\86139\\c2022-challenge\\level1\\p10_pushBoxes\\pushBoxScore.txt", "w");
	if (fp1 == NULL)
	{
		printf("文件打开失败\n");
		exit(-1);
	}
	for (int i=1; i <= MAX_LEVEL; i++)
	{
		//printf("Score of Level%d:%d\n", i, step[i]);
		char stepch[50] = "";
		sprintf_s(stepch, "Score of Level%d:%d\n", i, step[i]);
		fwrite(stepch, sizeof(stepch), 1, fp1);
	}
	fclose(fp1);
}

int main(int argc,char *argv[])
{
	run();
	return 0;
}
