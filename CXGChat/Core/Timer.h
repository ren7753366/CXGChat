#ifndef __TIMER_H_
#define __TIMER_H_

#define TARGET_RESOLUTION 1

class CTimer
{
public:
	CTimer();
	~CTimer();

public:

	unsigned int StartTimer(bool bCustom, int nPeriod, int nResolution = 0);
	void StopTimer(unsigned int &nTimerID);

private:

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	virtual bool OnTimer(int nTimeID) = 0;
	static void __stdcall TimerProc(unsigned int uID, unsigned int msg, unsigned long dwUser, unsigned long dw1, unsigned long dw2);
#endif

private:

	unsigned int m_nTimerID;
	unsigned int m_nTimerResolution;

#if(CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	struct itimerval m_tTick;
#endif
};

#endif
