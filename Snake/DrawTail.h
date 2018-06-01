#pragma once



//класс прорисовки хвоста

#define MAX_TERNS 1024 
#define MAX_TAILS MAX_TERNS+1

class CDrawTail
{
public:
	CDrawTail(CObjectSnake* hd);
	~CDrawTail();

	void AddElem(CObjectSnake* hd, eMoveto from, eMoveto to);
	eMoveto reverse(eMoveto in);
	void taildelete();
	bool checktail();
	CObjectSnake* pSnake_head;
	CTail Snake_tail; //первый элемент списка
	void ChangeRect(CObjectSnake* hd);
private:
	int count;
};




const eMoveto MovementCard[4][4] =
{
	/*      | r |   | l |    | t |    | b | */
	/* r */{ right,  right,    top,  bottom },
	/* l */{ left,  left,    top,   bottom },
	/* t */{ right, left,     top,    top },
	/* b */{ right, left,  bottom,    bottom }
};

