#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NearestPoints.h"
#include <QPainter>
#include <QMouseEvent>
#include <QVector>
#include <QMenuBar>

#define PEN_SIZE 3
#define MAX_POINTS 10000

class NearestPoints : public QMainWindow{
	Q_OBJECT
public:
	NearestPoints(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent *);
private slots:
	void mousePressEvent(QMouseEvent *event);
	void execute();
	void clear();
private:
	Ui::NearestPointsClass ui;
	QVector<QPoint> points;
	QPen pen;
	QLine* line;
};