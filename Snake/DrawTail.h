#pragma once
#include "LinkList.h"

class TailList;


//класс прорисовки хвоста

#define MAX_TERNS 1024 
#define MAX_TAILS MAX_TERNS+1

class CDrawTail
{
public:
	CDrawTail(CObjectSnake* hd);
	~CDrawTail();

	void on_idle(CObjectSnake* phd, CTailList** plist, bool* gameover);
	
	
private:
	void change_rect();
	void add_elem(CObjectSnake* hd, eMoveto from, eMoveto to);
	eMoveto reverse(eMoveto in);
	bool check_tail();
	bool direction_changed(eMoveto to);

	CObjectSnake* m_pTsnake_head;
	CTailList m_Tsnake_tail; //первый элемент списка
	eMoveto m_ePrev_dir;
	bool m_bmoved;
	const eMoveto m_eMovementCard[4][4] =
	{
		/*      | r |   | l |    | t |    | b | */
		/* r */{ right,  right,  top,     bottom },
		/* l */{ left,   left,   top,     bottom },
		/* t */{ right,  left,   top,     top    },
		/* b */{ right,  left,   bottom,  bottom }
	};
};



