#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NearestPoints.h"

class NearestPoints : public QMainWindow
{
	Q_OBJECT

public:
	NearestPoints(QWidget *parent = Q_NULLPTR);

private:
	Ui::NearestPointsClass ui;
};
