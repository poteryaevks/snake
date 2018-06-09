#include "stdafx.h"
#include "TimeControll.h"
#include <timelib.h>

timecontroll::timecontroll()
	: time(0)
{
	StartCounter();
}

timecontroll::~timecontroll()
{
}




bool timecontroll::timer( double setting)
{
	TRACE("TIME_GET: %d\n", TIME_GET);
	if ( TIME_GET - time >= setting) 
	{
		time = TIME_GET;
		return TRUE;
	}
	else
		return FALSE;
}




void timecontroll::StartCounter()
{
	if (!QueryPerformanceFrequency(&li))

	{
		return;
	}

	PCFreq = double(li.QuadPart);  //частота импульсов
	QueryPerformanceCounter(&li);   //число импульсов 
	CounterStart = li.QuadPart;
}


void timecontroll::reset()
{
	StartCounter();
}



double timecontroll::time_get()
{
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}
