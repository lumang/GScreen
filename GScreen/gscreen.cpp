#include "gscreen.h"
#include<iostream>
using namespace std;
#include<QTime>
static bool isRecord = false;

#define RECORDQSS "\
QPushButton:!hover \
{background-image: url(:/GScreen/record_normal.png);}\
QPushButton:hover{background-image: url(:/GScreen/record_hot.png);}\
QPushButton:pressed{background-image: url(:/GScreen/record_pressed.png);background - color: rgba(255, 255, 255, 0);}"

static QTime rtime;

GScreen::GScreen(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	startTimer(100);

	
}

void GScreen::timerEvent(QTimerEvent *e)
{
	int es= rtime.elapsed()/1000;
	char buf[1024] = { 0 };

	sprintf(buf, "%03d:%02d", es / 60, es % 60);
	ui.timelabel->setText(buf);


}

GScreen::~GScreen()
{

}

void GScreen::record()
{
	isRecord = !isRecord;
	if (isRecord)
	{
		rtime.restart();
		ui.recordButton->setStyleSheet("background-image: url(:/GScreen/stop.png);background-color:rgba(255,255,255,0); ");
		//ui.recordButton->setStyleSheet(":/GScreen/record_hot.png");

	}
	else
	{
		//ui.recordButton->setStyleSheet("background-image: url(:/GScreen/record_hot.png);");
		ui.recordButton->setStyleSheet(RECORDQSS);

	}
	cout << "record";// test bind slot

}
