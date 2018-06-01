#pragma once

 ////////////////////////////////////
class CObjectSnake
{
public:
	CObjectSnake();
	virtual ~CObjectSnake();

	LONG get_coordinate_a();
	LONG get_coordinate_b();
	LONG get_coordinate_c();
	LONG get_coordinate_d();

	virtual void move_top();
	virtual void move_bottom();
	virtual void move_right();
	virtual void move_left();

	CRect rect;
	eMoveto get_direction();
	virtual void set_direction(eMoveto edist);
	double get_speed();
	double get_length();
		
	

protected:
	int m_dcoordinate[4]; //координаты головы
	eMoveto m_ddirection;
	double m_dspeed; //скорость змейки 
	double m_dlength; //длина змейки 	
};


/////////////////////////////////
class CTail : public CObjectSnake
{
public:
	CTail(CRect rc);
	CTail(CRect rc, eMoveto dir);
	virtual ~CTail();
	int index; //номер элемента
	int get_count();
	
	static CTail* pFirst; //указатель на первый элемент
	CTail* pNext;  //указатель на последний элемент
	
	virtual void move_top();
	virtual void move_bottom();
	virtual void move_right();
	virtual void move_left();

	
	CTail* getData(CRect rect, eMoveto dir);
	void addToList(CTail* pTAIL);
	void removeFromList();  //удалить из списка
	void clearlist();

	void increase(eMoveto edist); //увеличение длины на 1 
	void decrease(eMoveto edist); //снижение длины на 1

private:
	static int count; //число хвостов
	
};

////////////////////////////////////////////





