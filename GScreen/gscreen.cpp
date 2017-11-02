#include "gscreen.h"

GScreen::GScreen(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//setWindowFlags(Qt::FramelessWindowHint);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	//QBitmap bmp(this->size());


	

}

GScreen::~GScreen()
{

}
