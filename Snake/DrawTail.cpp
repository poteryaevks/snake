#include "stdafx.h"
#include "CObjectSnake.h"
#include "DrawTail.h"




CDrawTail::CDrawTail(CObjectSnake* hd)
	:count(0),
	Snake_tail(hd->rect)
{
	pSnake_head = hd; //первый элемент списка
}


CDrawTail::~CDrawTail()
{

}


void CDrawTail::AddElem(CObjectSnake* hd, eMoveto from, eMoveto to)//если было изменение направления 
{
	CTail* newtail;

	pSnake_head = hd;
	eMoveto etemp = MovementCard[from][to];
	switch (etemp)
	{
	case top:
		pSnake_head->set_direction(top);
		newtail = Snake_tail.getData(pSnake_head->rect, pSnake_head->get_direction());
		Snake_tail.addToList(newtail);
		break;
	case bottom:
		pSnake_head->set_direction(bottom);
		newtail = Snake_tail.getData(pSnake_head->rect, pSnake_head->get_direction());
		Snake_tail.addToList(newtail);
		break;
	case left:
		pSnake_head->set_direction(left);
		newtail = Snake_tail.getData(pSnake_head->rect, pSnake_head->get_direction());
		Snake_tail.addToList(newtail);
		break;
	case right:
		pSnake_head->set_direction(right);
		newtail = Snake_tail.getData(pSnake_head->rect, pSnake_head->get_direction());
		Snake_tail.addToList(newtail);
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

		CTail* temp = Snake_tail.pFirst;
		//движение  хвоста змейки
		if (temp == Snake_tail.pFirst)
	
			temp->decrease(reverse(temp->get_direction()));
		
	    if (checktail())
		{
			taildelete(); //удаление первого элеменыта присвоение второму номер один 
		}
	

		while (temp->pNext)		
		{
			temp = temp->pNext;
		} 

		if(temp->pNext == 0)
			temp->increase(hd->get_direction());
		

		
	
}


bool CDrawTail::checktail() //if true -> delete
{
	if (Snake_tail.pFirst->rect.left == Snake_tail.pFirst->rect.right
				|| Snake_tail.pFirst->rect.bottom == Snake_tail.pFirst->rect.top)
			{
				return TRUE;
			}
	return FALSE;
}

void CDrawTail::taildelete()
{
	CTail* temp;
	temp = Snake_tail.pFirst;
	temp->pFirst = temp->pNext;
		
	//delete Snake_tail.pFirst;
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