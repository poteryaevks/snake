#pragma once
class timecontroll
{
public:
	timecontroll();
	~timecontroll();

	bool timer(double setting);
	double time_get();
	void reset();
	
private:

	void StartCounter();
	double time;

	double PCFreq;
	__int64 CounterStart;
	LARGE_INTEGER li;
};

