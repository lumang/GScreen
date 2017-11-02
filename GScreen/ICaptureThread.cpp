#include "ICaptureThread.h"

#include<iostream>

using namespace std;
ICaptureThread::ICaptureThread()
{
}


ICaptureThread::~ICaptureThread()
{

}

void ICaptureThread::run()
{
	while (!isExit)
	{
		mutex.lock();
		//qDebug() << ".";
		cout << ".";
		msleep(500);
		mutex.unlock();
	}
}

void  ICaptureThread::Start()
{
	Stop();
	mutex.lock();
	//CaptureScreen(0);
	//width = GetSystemMetrics(SM_CXSCREEN);
	//hight = GetSystemMetrics(SM_CXSCREEN);

	isExit = false;
	mutex.unlock();
	start();
}

void ICaptureThread::Stop()
{
	mutex.lock();
	isExit = true;
	mutex.unlock();
	wait();// µÈ´ýÍË³ö

}