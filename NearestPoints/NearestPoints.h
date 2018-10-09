#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NearestPoints.h"
#include <QPainter>
#include <QMouseEvent>
#include <QVector>
#include <QMenuBar>

#define WINDOW_SIZE 800
#define PEN_SIZE 3
#define MAX_VISIBLE_POINTS 1000
#define MAX_POINTS 1000000

class NearestPoints : public QMainWindow{
	Q_OBJECT
public:
	NearestPoints(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent *);
private slots:
	void mousePressEvent(QMouseEvent *event);
	void execute();
	void clear();
	void generate();
private:
	Ui::NearestPointsClass ui;
	QVector<QPoint> points;
	QPen pointPen;
	QPen linePen;
	QLine* line = NULL;
};