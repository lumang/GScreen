#pragma once
//#include<qthread.h>
#include<QThread>
class ICaptureThread:protected QThread
{
public:
	//out
	int width = 1280;
	int height = 720;

	//in
	int fps = 10;
	int cacheSize = 3;
	void run();
	void Start();
	void Stop();
	
	static ICaptureThread *Get()
	{
		static ICaptureThread ct;// 静态 函数中 静态变量
		return &ct;
	}
	virtual ~ICaptureThread();
protected:
	bool isExit = false;
	std::list<char *> rgbs;
	QMutex mutex;
	ICaptureThread();

};

