#include "stdafx.h"
#include "CObjectSnake.h"
#include "DrawTail.h"

CObjectSnake::CObjectSnake()
	:m_ddirection(right),
	m_dspeed(0),
	m_dlength(0),
	m_dcoordinate{ 200, 400, 220, 420 }
{
	rect.SetRect(m_dcoordinate[0],
		m_dcoordinate[1],
		m_dcoordinate[2],
		m_dcoordinate[3]);
}

CObjectSnake::~CObjectSnake()
{
}

eMoveto CObjectSnake::get_direction()
{
	return m_ddirection;
}

void CObjectSnake::set_direction(eMoveto edist)
{
	if (edist != m_ddirection)
	{
		Draw.AddElem(this, m_ddirection, edist);
	}
	switch (edist)
	{
	case top:
		m_ddirection = top;
		break;

	case bottom:
		m_ddirection = bottom;
		break;

	case left:
		m_ddirection = left;
		break;

	case right:
		m_ddirection = right;
		break;
	}
}


LONG CObjectSnake::get_coordinate_a()
{
	return rect.left;
}

LONG CObjectSnake::get_coordinate_b()
{
	return rect.top;
}

LONG CObjectSnake::get_coordinate_c()
{
	return rect.right;
}


LONG CObjectSnake::get_coordinate_d()
{
	return rect.bottom;
}

double CObjectSnake::get_speed()
{
	
	return m_dspeed;
}


double CObjectSnake::get_length()
{
	return m_dlength;
}


void CObjectSnake::move_top()
{
	rect.OffsetRect(0, -20);
} 

void CObjectSnake::move_bottom()
{
	rect.OffsetRect(0, 20);
}

void CObjectSnake::move_right()
{
	rect.OffsetRect(20, 0);
}

void CObjectSnake::move_left()
{
	rect.OffsetRect(-20, 0);
}




///////////////////////////////////Tail//////////////////////////////////////////
CTail* CTail::pFirst = 0;


CTail::CTail()
	:pNext(0)
{
	pFirst = this;
}

CTail::CTail(CRect rc)
	: pNext(0)
{
	rect.SetRect(rc.right, rc.top, rc.left, rc.bottom);
}


CTail::~CTail()
{
}


void CTail::move_top()
{
	rect.SetRect(get_coordinate_a(), get_coordinate_b() - 20, get_coordinate_c(), get_coordinate_d() - 20);
}

void CTail::move_bottom()
{
	rect.SetRect(get_coordinate_a(), get_coordinate_b() + 20, get_coordinate_c(), get_coordinate_d() + 20);
}

void CTail::move_right()
{
	rect.SetRect(get_coordinate_a() + 20, get_coordinate_b(), get_coordinate_c() + 20, get_coordinate_d());
}

void CTail::move_left()
{
	rect.SetRect(get_coordinate_a() - 20, get_coordinate_b(), get_coordinate_c() - 20, get_coordinate_d());
}




int CTail::get_count()
{
	return count;
}


void CTail::increase(eMoveto edist)
{
	switch (edist)
	{
	case left:
		rect.SetRect(get_coordinate_a() - 1, get_coordinate_b(), get_coordinate_c(), get_coordinate_d());
		break;

	case right:
		rect.SetRect(get_coordinate_a(), get_coordinate_b(), get_coordinate_c() + 1, get_coordinate_d());
		break;

	case bottom:
		rect.SetRect(get_coordinate_a(), get_coordinate_b(), get_coordinate_c(), get_coordinate_d() + 1);
		break;

	case top:
		rect.SetRect(get_coordinate_a(), get_coordinate_b() - 1, get_coordinate_c(), get_coordinate_d());
		break;
		
	default:
		break;
	}
}




void CTail::decrease(eMoveto edist)
{
	switch (edist)
	{
	case left:
		rect.SetRect(get_coordinate_a() + 1, get_coordinate_b(), get_coordinate_c(), get_coordinate_d());
		break;

	case right:
		rect.SetRect(get_coordinate_a(), get_coordinate_b(), get_coordinate_c() - 1, get_coordinate_d());
		break;

	case bottom:
		rect.SetRect(get_coordinate_a(), get_coordinate_b(), get_coordinate_c(), get_coordinate_d() - 1);
		break;

	case top:
		rect.SetRect(get_coordinate_a(), get_coordinate_b() + 1, get_coordinate_c(), get_coordinate_d());
		break;

	default:
		break;
	}
}


void CTail::removeFromList() //удаляем первый элемент
{

}

int CTail::count = 0;


void CTail::addToList(CTail* pnt)
{
	if (pFirst == 0)
	{
		pFirst = this;
	}
	CTail* pCurrent = pFirst;
	while (pCurrent->pNext)
	{
		pCurrent = pCurrent->pNext;
	}
	// добавим текущий элемент к концу списка
	pCurrent->pNext = pnt;
	count++;
}


CTail* CTail::getData(CRect rect)
{
	// создаем новый объект для заполнения
	CTail* pnt = new CTail(rect);
	// обнулим указатель на следующий элемент
	pnt->pNext = 0;
	// Еернем адрес созданного объекта
	return pnt;
}

void CTail::clearlist()
{
	CTail* temp_pnt[1024];
	temp_pnt[0] = this;

	while (temp_pnt[count]->pNext)
	{
		count++;
		temp_pnt[count] = temp_pnt[count - 1]->pNext;
	}

	for (size_t i = 1; i <= count; ++i)
	{
		delete temp_pnt[i];
	}
}