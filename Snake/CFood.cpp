#include "stdafx.h"
#include "CFood.h"


CFood::CFood()
	:m_dcoordinate()
{
}


CFood::~CFood()
{

}


int* CFood::get_coordinate()
{
	return &m_dcoordinate[0];
}


int CFood::get_coordinate_a()
{
	return m_dcoordinate[0];
}


int CFood::get_coordinate_b()
{
	return m_dcoordinate[1];
}


int CFood::get_coordinate_c()
{
	return m_dcoordinate[2];
}


int CFood::get_coordinate_d()
{
	return m_dcoordinate[3];
}