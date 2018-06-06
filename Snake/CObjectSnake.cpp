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
	m_ddirection = edist;	
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

CRect CObjectSnake::get_rect()
{
	return rect;
}



///////////////////////////////////Tail//////////////////////////////////////////
//CTail* CTail::pFirst = 0;
CTail::CTail(CRect rc)
	:pNext(0)
{
	rect.SetRect(rc.right, rc.top, rc.left - 60, rc.bottom);
    pFirst = this;
}

bool CTail::flag = TRUE;

CTail::CTail(CRect rc, eMoveto dir)
	: pNext(0)
{
	if (flag)
	{
		rect.SetRect(rc.right, rc.top, rc.left - 60, rc.bottom);
		flag = FALSE;
	}
	else
	rect.SetRect(rc.right, rc.top, rc.left, rc.bottom);
	m_ddirection = dir;
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



void CTail::increase(eMoveto edist)
{
	switch (edist)
	{
	case left:
		rect.SetRect(get_coordinate_a() , get_coordinate_b(), get_coordinate_c() - 20, get_coordinate_d());
		break;

	case right:
		rect.SetRect(get_coordinate_a() + 20, get_coordinate_b(), get_coordinate_c(), get_coordinate_d());
		break;

	case bottom:
		rect.SetRect(get_coordinate_a(), get_coordinate_b(), get_coordinate_c(), get_coordinate_d() + 20);
		break;

	case top:
		rect.SetRect(get_coordinate_a(), get_coordinate_b() - 20, get_coordinate_c(), get_coordinate_d());
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
		rect.SetRect(get_coordinate_a() - 20, get_coordinate_b(), get_coordinate_c() , get_coordinate_d());
		break;

	case right:
		rect.SetRect(get_coordinate_a() , get_coordinate_b(), get_coordinate_c() + 20, get_coordinate_d());
		break;

	case bottom:
		rect.SetRect(get_coordinate_a(), get_coordinate_b() + 20, get_coordinate_c(), get_coordinate_d());
		break;

	case top:
		rect.SetRect(get_coordinate_a(), get_coordinate_b(), get_coordinate_c(), get_coordinate_d() - 20);
		break;

	default:
		break;
	}
}



