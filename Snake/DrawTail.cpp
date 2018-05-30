#include "stdafx.h"
#include "SnakeView.h"
#include "CObjectSnake.h"
#include "DrawTail.h"

CDrawTail Draw;


CDrawTail::CDrawTail()
	:count(0)
{
	
}


CDrawTail::~CDrawTail()
{

}


void CDrawTail::AddElem(CObjectSnake* hd, eMoveto from, eMoveto to)//если было изменение направления 
{
	CTail* newtail;
	snake_head = hd;
	eMoveto etemp = MovementCard[from][to];
	switch (etemp)
	{
	case top:
		newtail = pSnake_tail.getData(snake_head->rect);
		pSnake_tail.addToList(newtail);
		break;
	case bottom:
		newtail = pSnake_tail.getData(snake_head->rect);
		pSnake_tail.addToList(newtail);
		break;
	case left:
		newtail = pSnake_tail.getData(snake_head->rect);
		pSnake_tail.addToList(newtail);
		break;
	case right:
		newtail = pSnake_tail.getData(snake_head->rect);
		pSnake_tail.addToList(newtail);
		break;

	default:
		break;
	}
}



void CDrawTail::RightToTop()
{		
	/*rect[count - 1].SetRect(get_coordinate_c() - 10,
		                    get_coordinate_b(),
		                    get_coordinate_c(),
		                    get_coordinate_b() - 1);*/
}



void RightToBottom()
{}


void LeftToTop()
{}


void LeftToBottom()
{}


void TopToRight()
{}


void TopToLeft()
{}


void BottomToRight()
{}


void BottomToLeft()
{}