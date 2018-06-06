#pragma once
#include "CObjectSnake.h"

class CTail;

////////////////////////////////////////////
class CTailList
{
public:
	CTailList();
	virtual ~CTailList();

	CTail* first;

	void addToList(CTail* pnt);
	void removeFromList();  //удалить из списка
	void clearlist();
	CTail* getData(CRect rect, eMoveto dir);
	void deletefromlist();
private:
	int count;
};
