#include<stdio.h>
#include<string.h>
#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;


typedef struct CargoInfo
{
	char name[20];
	char size[10];
	int num;
}Car;

typedef struct Cargo
{
	Car cargo[100];
	int n;
}cargo;

void menu();
void InitCar(cargo* pc);
void AddCar(cargo* pc);
void PrintCar(const cargo* pc);
int FindCar(const cargo* pc, char* name, char* size);
void SearchCar(const cargo* pc);
void DelCar(cargo* pc);
void SortCar(cargo* pc);




void menu()
{
	printf("1.显示库存\n");
	printf("2.入库\n");
	printf("3.出库\n");
	printf("4.查找货物\n");
	printf("5.排序货物\n");
	printf("6.退出\n");
}

void InitCar(cargo* pc)
{
	assert(pc);
	pc->n = 0;
	memset(pc->cargo, 0, sizeof(pc->cargo));
	FILE* fp;
	fopen_s(&fp,"C:\\Users\\86139\\c2022-challenge\\level1\\p12_warehouse\\warehouse.in", "rb");
	if (fp == NULL)
	{
		printf("error\n");
		return;
	}
	CargoInfo buf = { 0 };
	while (fread(&buf, sizeof(CargoInfo), 1, fp))
	{
		pc->cargo[pc->n] = buf;
		pc->n++;
	}
	fclose(fp);
	fp = NULL;
}

void AddCar(cargo* pc)
{
	assert(pc);
	printf("Enter the name:\n");
	cin >> pc->cargo[pc->n].name;
	printf("Enter the size:\n");
	cin >> pc->cargo[pc->n].size;
	printf("Enter the num:\n");
	cin >> pc->cargo[pc->n].num;
	int pos = FindCar(pc, pc->cargo[pc->n].name, pc->cargo[pc->n].size);
	if (pos == -1)
	{
		pc->n++;
	}
	else
	{
		pc->cargo[pos].num += pc->cargo[pc->n].num;
	}
}

void PrintCar(const cargo* pc)
{
	assert(pc);
	printf("%-15s %-10s %-10s\n", "名称", "型号", "数量");
	for (int i = 0;i<pc->n; i++)
	{
		printf("%-15s %-10s %-10d\n", pc->cargo[i].name, pc->cargo[i].size, pc->cargo[i].num);
	}
	system("pause");
}

int FindCar(const cargo* pc, char* name, char* size)
{
	assert(pc && name && size);
	for (int i = 0; i < pc->n; i++)
	{
		if (0 == strcmp(pc->cargo[i].name, name) && 0 == strcmp(pc->cargo[i].size, size))
		{
			return i;
		}
	}
	return -1;
}

void SearchCar(const cargo* pc)
{
	assert(pc);
	char name[20], size[20];
	printf("Enter Name:\n");
	cin>>name;
	cout << "Enter Size:" << endl;
	cin >> size;
	int pos = FindCar(pc, name, size);
	if (pos == -1)
	{
		printf("None\n");
	}
	else
	{
		printf("%-15s %-10s %-10s\n", "名称", "型号", "数量");
		printf("%-15s %-10s %-10d\n", pc->cargo[pos].name, pc->cargo[pos].size, pc->cargo[pos].num);
	}
	system("pause");
}

void OutCar(cargo* pc)
{
	assert(pc);
	char name[20], size[20];
	int outnum = 0;
	printf("Enter Name:\n");
	cin >> name;
	cout << "Enter Size" << endl;
	cin >> size;
	printf("Enter Num:\n");
	scanf_s("%d", &outnum);
	int pos = FindCar(pc, name, size);
	if (pos == -1)
	{
		printf("None\n");
	}
	else
	{
		pc->cargo[pos].num-=outnum;
	}
}

void DelCar(cargo* pc)
{
	assert(pc);
	char name[20], size[20];
	printf("Enter delete name:\n");
	cin >> name;
	cout << "Enter delete size:" << endl;
	cin >> size;
	int pos = FindCar(pc, name, size);
	if (pos == -1)
	{
		printf("None\n");
	}
	else
	{
		for (int i = pos; i < pc->n - 1; i++)
		{
			pc->cargo[i] = pc->cargo[i + 1];
		}
		pc->n--;
	}
}

void SortCar(cargo* pc)
{
	if (pc->n == 0)
	{
		printf("None\n");
	}
	else
	{
		for (int i = 0; i < pc->n - 1; i++)
		{
			for (int j = 0; j < pc->n - 1 - i; j++)
			{
				if ((strcmp(pc->cargo[j].name, pc->cargo[j + 1].name)) > 0)
				{
					Car t = pc->cargo[j];
					pc->cargo[j] = pc->cargo[j + 1];
					pc->cargo[j + 1] = t;
				}
			}
		}
	}
}

void Save(cargo* pc)
{
	FILE* fp;
	fopen_s(&fp, "C:\\Users\\86139\\c2022-challenge\\level1\\p12_warehouse\\warehouse.in", "wb");
	if (fp == NULL)
	{
		perror("Save");
		printf("保存失败\n");
		return;
	}
	for (int i = 0; i < pc->n; i++)
	{
		fwrite(&pc->cargo[i], sizeof(CargoInfo), 1, fp);
	}
	fclose(fp);
	fp = NULL;
}

int main()
{
	int input = 0;
	Cargo car;
	InitCar(&car);
	do
	{
		system("cls");
		menu();
		printf("Enter Your Choice:\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:PrintCar(&car); break;
		case 2:AddCar(&car); break;
		case 3:OutCar(&car); break;
		case 4:SearchCar(&car); break;
		case 5:SortCar(&car); break;
		case 6:Save(&car); exit(0); break;
		default:printf("非法输入\n"); break;
		}
	} while (input);
	return 0;
}