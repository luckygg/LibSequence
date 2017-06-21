#pragma once

#include "stdafx.h"

class CStopWatch
{
public:
	CStopWatch(void) {}
	~CStopWatch(void) {}

private :
	LARGE_INTEGER m_Start;
	LARGE_INTEGER m_Stop;
	LARGE_INTEGER m_Freq;

public :
	void Start() { QueryPerformanceFrequency(&m_Freq); QueryPerformanceCounter(&m_Start); }
	void Stop()  { QueryPerformanceCounter(&m_Stop);}
	double GetTimeMs() { return (double)(m_Stop.QuadPart - m_Start.QuadPart)/m_Freq.QuadPart*1000; }
};

