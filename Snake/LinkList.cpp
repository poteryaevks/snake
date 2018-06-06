#include "stdafx.h"
#include "CObjectSnake.h"
#include "DrawTail.h"
#include "LinkList.h"


/////////////////////////////////////////////////////
CTailList::CTailList()
	: first(0),
	 count(1)
{
}

CTailList::~CTailList()
{
}


void CTailList::addToList(CTail* pnt)
{
	CTail* pCurrent = first;
	while (pCurrent->pNext)
	{
		pCurrent = pCurrent->pNext;
	}
	// добавим текущий элемент к концу списка
	pCurrent->pNext = pnt;
	count++;
	TRACE(_T("Count: %d\n"), count);
}



CTail* CTailList::getData(CRect rect, eMoveto dir)
{
	// создаем новый объект для заполнения

	CTail* pnt = new CTail(rect, dir);
	// обнулим указатель на следующий элемент
	if (first == 0)
	{
		pnt->pFirst = pnt;
		first = pnt->pFirst;
	}
	else
		pnt->pFirst = first;
	
	pnt->pNext = 0;
	// Еернем адрес созданного объекта
	return pnt;
}


void CTailList::clearlist()
{
	CTail* temp_pnt[1024];

	temp_pnt[0] = first;

	while (temp_pnt[count - 1]->pNext)
	{
		temp_pnt[count] = temp_pnt[count - 1]->pNext;
		count++;
	}

	for (size_t i = 0; i <= count - 1; ++i)
	{
		delete temp_pnt[i];
	}
}

void CTailList::deletefromlist()
{
	CTail* temp;
	temp = first;
	first = first->pNext;
	first->pFirst = first;
	count--;
	TRACE(_T("Count: %d\n"), count);
	delete temp;
}


void CTailList::removeFromList()  //удалить из списка
{
}



