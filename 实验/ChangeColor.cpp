#include<graphics.h>
#include<stdio.h>
#include"gobang.h"

void ChangeColor()
{
	switch (gettextcolor())
	{
	case WHITE:settextcolor(BLACK); setfillcolor(WHITE); break;
	case BLACK:settextcolor(WHITE); setfillcolor(BLACK); break;
	default:break;
	}
}