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

	virtual CRect get_rect();
	
	eMoveto get_direction();
	virtual void set_direction(eMoveto edist);
	double get_speed();
	double get_length();
		

protected:
	CRect rect;
	int m_dcoordinate[4]; //���������� ������
	eMoveto m_ddirection;
	double m_dspeed; //�������� ������ 
	double m_dlength; //����� ������ 	
};


/////////////////////////////////
class CTail : public CObjectSnake
{
public:
	friend class CTailList;

	CTail(CRect rc);
	CTail(CRect rc, eMoveto dir);
	virtual ~CTail();
				
	virtual void move_top();
	virtual void move_bottom();
	virtual void move_right();
	virtual void move_left();

	void increase(eMoveto edist); //���������� ����� �� 1 
	void decrease(eMoveto edist); //���������� ����� �� 1

	CTail * pFirst;
	CTail* pNext;

private:
	static int count; //����� �������
	static bool flag;
	
protected:
	
};







