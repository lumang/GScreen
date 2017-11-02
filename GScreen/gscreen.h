#ifndef GSCREEN_H
#define GSCREEN_H

#include <QtWidgets/QWidget>
#include "ui_gscreen.h"

class GScreen : public QWidget
{
	Q_OBJECT

public:
	GScreen(QWidget *parent = 0);
	~GScreen();

	void timerEvent(QTimerEvent *e);

public slots:
    void record();
private:
	Ui::GScreenClass ui;
};

#endif // GSCREEN_H
