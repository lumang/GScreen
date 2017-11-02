#include "gscreen.h"
#include <QtWidgets/QApplication>
#include<qdebug.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
#if Debug
	qDebug()<<"no see"
#endif
	GScreen w;
	w.show();
	return a.exec();
}
