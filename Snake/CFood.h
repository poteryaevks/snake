#pragma once
class CFood
{
public:
	CFood();
	virtual ~CFood();

	int* get_coordinate();
	int get_coordinate_a();
	int get_coordinate_b();
	int get_coordinate_c();
	int get_coordinate_d();

protected:
	int m_dcoordinate[4]; //координата еды 
};

