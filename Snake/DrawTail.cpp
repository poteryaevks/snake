#include "stdafx.h"
#include "CObjectSnake.h"
#include "LinkList.h"
#include "DrawTail.h"


CDrawTail::CDrawTail(CObjectSnake* hd)
{
	CTail* pnt = m_Tsnake_tail.getData(hd->get_rect(), hd->get_direction());
	m_ePrev_dir = right;
}


CDrawTail::~CDrawTail()
{
}


bool CDrawTail::direction_changed(eMoveto to)
{
	if (to != m_ePrev_dir)
		return TRUE;
	else
		return FALSE;
}


void CDrawTail::add_elem(CObjectSnake* hd, eMoveto from, eMoveto to)//если было изменение направления 
{
	CTail* newtail;
	eMoveto etemp = m_eMovementCard[from][to];

	switch (etemp)
	{
	case top:

		if (check_tail())
			m_Tsnake_tail.deletefromlist();
				
		m_Tsnake_tail.first->decrease(m_Tsnake_tail.first->get_direction());
		hd->set_direction(top);
		hd->move_top();
		newtail = m_Tsnake_tail.getData(hd->get_rect(), hd->get_direction());
		m_Tsnake_tail.addToList(newtail);
		
		break;

	case bottom:

		if (check_tail())
			m_Tsnake_tail.deletefromlist();
		
		m_Tsnake_tail.first->decrease(m_Tsnake_tail.first->get_direction());
		hd->set_direction(bottom);
		hd->move_bottom();
		newtail = m_Tsnake_tail.getData(hd->get_rect(), hd->get_direction());
		m_Tsnake_tail.addToList(newtail);
		break;

	case left:

		if (check_tail())
			m_Tsnake_tail.deletefromlist();
		
		m_Tsnake_tail.first->decrease(m_Tsnake_tail.first->get_direction());
		hd->set_direction(left);
		hd->move_left();
		newtail = m_Tsnake_tail.getData(hd->get_rect(), hd->get_direction());
		m_Tsnake_tail.addToList(newtail);
		break;

	case right:

		if (check_tail())
			m_Tsnake_tail.deletefromlist();
		
		m_Tsnake_tail.first->decrease(m_Tsnake_tail.first->get_direction());
		hd->set_direction(right);
		hd->move_right();
		newtail = m_Tsnake_tail.getData(hd->get_rect(), hd->get_direction());
		m_Tsnake_tail.addToList(newtail);
		break;
	}

	m_bmoved = TRUE;
}


void CDrawTail::change_rect()
{
	//движение головы змейки 
	if (m_pTsnake_head->get_direction() == top)
	{
		m_pTsnake_head->move_top();
	}

	if (m_pTsnake_head->get_direction() == bottom)
	{
		m_pTsnake_head->move_bottom();
	}

	if (m_pTsnake_head->get_direction() == right)
	{
		m_pTsnake_head->move_right();
	}

	if (m_pTsnake_head->get_direction() == left)
	{
		m_pTsnake_head->move_left();
	}

	//движение  хвоста змейки
	CTail* temp = m_Tsnake_tail.first;
    
	if (check_tail())
	{
		m_Tsnake_tail.deletefromlist();
		temp = m_Tsnake_tail.first;
		temp->decrease(temp->get_direction());
	}
	else
		m_Tsnake_tail.first->decrease(m_Tsnake_tail.first->get_direction());

	while (temp->pNext)
		temp = temp->pNext;

	if (temp->pNext == 0)
		temp->increase(m_pTsnake_head->get_direction());
}


void CDrawTail::on_idle(CObjectSnake* phd, CTailList** plist, bool* gameover)
{
	eMoveto newdir = phd->get_direction();
	m_bmoved = FALSE;
	
	if (direction_changed(newdir))
	{
		add_elem(m_pTsnake_head, newdir, newdir);
		m_ePrev_dir = newdir;
	}
	*plist = &m_Tsnake_tail;
	m_pTsnake_head = phd;  //присвоили новую голову
	if(!m_bmoved)
	change_rect(); //изменили положения элементов
	
	if (phd->get_rect().bottom == 440 //вышли за рамки, прекратить игру
		|| phd->get_rect().top == 0
		|| phd->get_rect().right == 480
		|| phd->get_rect().left == 0)
	{
		*gameover = TRUE;
		return;
	}
}


bool CDrawTail::check_tail() //if true -> delete tail
{
	if ((m_Tsnake_tail.first->get_rect().left == m_Tsnake_tail.first->get_rect().right)
		|| (m_Tsnake_tail.first->get_rect().bottom == m_Tsnake_tail.first->get_rect().top))
		return TRUE;
	else
		return FALSE;
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
	return right;
}