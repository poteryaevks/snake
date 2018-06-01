#include "stdafx.h"
#include "CObjectSnake.h"
#include "DrawTail.h"




CDrawTail::CDrawTail(CObjectSnake* hd)
	:count(0),
	pSnake_tail()
{
	pSnake_tail.rect.SetRect(hd->rect.right, hd->rect.top, hd->rect.left, hd->rect.bottom);
	snake_head = hd; //первый элемент списка
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
		snake_head->set_direction(top);
		newtail = pSnake_tail.getData(snake_head->rect, snake_head->get_direction());
		pSnake_tail.addToList(newtail);
		break;
	case bottom:
		snake_head->set_direction(bottom);
		newtail = pSnake_tail.getData(snake_head->rect, snake_head->get_direction());
		pSnake_tail.addToList(newtail);
		break;
	case left:
		snake_head->set_direction(left);
		newtail = pSnake_tail.getData(snake_head->rect, snake_head->get_direction());
		pSnake_tail.addToList(newtail);
		break;
	case right:
		snake_head->set_direction(right);
		newtail = pSnake_tail.getData(snake_head->rect, snake_head->get_direction());
		pSnake_tail.addToList(newtail);
		break;

	default:
		break;
	}
}



void CDrawTail::ChangeRect(CObjectSnake* hd)
{

	// процесс обработки в новом топоке
	
		//движение головы змейки 
		if (hd->get_direction() == top)
		{
			hd->move_top();
		}

		if (hd->get_direction() == bottom)
		{
			hd->move_bottom();
		}

		if (hd->get_direction() == right)
		{
			hd->move_right();
		}

		if (hd->get_direction() == left)
		{
			hd->move_left();
		}

		CTail* temp = pSnake_tail.pFirst;
		//движение  хвоста змейки
		while (temp->pNext)
		{
			if (temp == pSnake_tail.pFirst)
			{
		//		temp->decrease(reverse(hd->get_direction()));
			}

			temp = temp->pNext;
		}

		if(temp->pNext == 0)
		{
			temp->increase(hd->get_direction());
		}


		
	
}


eMoveto CDrawTail::reverse(eMoveto in)
{
	switch (in)
	{
	case right:
		return left;
	case left:
		return right;
	case top:
		return bottom;
	case bottom:
		return top;
	}
}