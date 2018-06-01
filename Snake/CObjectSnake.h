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
	int m_dcoordinate[4]; //���������� ������
	eMoveto m_ddirection;
	double m_dspeed; //�������� ������ 
	double m_dlength; //����� ������ 	
};


/////////////////////////////////
class CTail : public CObjectSnake
{
public:
	CTail(CRect rc);
	CTail(CRect rc, eMoveto dir);
	virtual ~CTail();
	int index; //����� ��������
	int get_count();
	
	static CTail* pFirst; //��������� �� ������ �������
	CTail* pNext;  //��������� �� ��������� �������
	
	virtual void move_top();
	virtual void move_bottom();
	virtual void move_right();
	virtual void move_left();

	
	CTail* getData(CRect rect, eMoveto dir);
	void addToList(CTail* pTAIL);
	void removeFromList();  //������� �� ������
	void clearlist();

	void increase(eMoveto edist); //���������� ����� �� 1 
	void decrease(eMoveto edist); //�������� ����� �� 1

private:
	static int count; //����� �������
	
};

////////////////////////////////////////////





