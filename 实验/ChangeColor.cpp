#include<graphics.h>
#include<stdio.h>
#include"gobang.h"

void ChangeColor()
{
	switch (getfillcolor())
	{
	case BLACK:settextcolor(BLACK); setfillcolor(WHITE); break;
	case WHITE:settextcolor(WHITE); setfillcolor(BLACK); break;
	default:settextcolor(WHITE); setfillcolor(BLACK); break;
	}
}