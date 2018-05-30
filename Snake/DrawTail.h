#pragma once

#include "stdafx.h"
#include "CObjectSnake.h"

//класс прорисовки хвоста

#define MAX_TERNS 1024 
#define MAX_TAILS MAX_TERNS+1

class CDrawTail
{
public:
	CDrawTail();
	~CDrawTail();

	void AddElem(CObjectSnake* hd, eMoveto from, eMoveto to);
	void RightToTop();

	CObjectSnake* snake_head;
	CTail pSnake_tail; //первый элемент списка

private:
	int count;
};



const eMoveto MovementCard[8][3] =
{
/*    |  |   |    | |   | |    | */
/*   */{ right, bottom,  bottom },
/*   */{ right, top,     top },
/*   */{ left,  top,     top },
/*   */{ left,  bottom,  bottom },
/*   */{ bottom, right,  right },
/*   */{ bottom, left,   left },
/*   */{ top, left,      left },
/*   */{ top, right,     right },
};




extern CDrawTail Draw;
