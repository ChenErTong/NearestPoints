#include "NearestPoints.h"
#include "NearestPointsAlgorithm.h"

NearestPoints::NearestPoints(QWidget *parent)	: QMainWindow(parent){
	ui.setupUi(this);
	QMenuBar *menuBar = new QMenuBar();
	QAction *execute = menuBar->addAction("Execute");
	QAction *clear = menuBar->addAction("Clear");
	this->setMenuBar(menuBar);
	this->connect(execute, &QAction::triggered, this, &NearestPoints::execute);
	this->connect(clear, &QAction::triggered, this, &NearestPoints::clear);

	pen = QPen(Qt::black);
	pen.setWidth(PEN_SIZE);
}

void NearestPoints::paintEvent(QPaintEvent *){
	QPainter painter(this);

	painter.setPen(pen);
	painter.drawPoints(points);
	if (line != NULL) {
		painter.drawLine(*line);
		line = NULL;
	}
}

void NearestPoints::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		points.append(QPoint(event->x(), event->y()));
		update();
	}
}

void NearestPoints::execute() {
	int size = points.size();
	if (size < 2) return;
	Point p[MAX_POINTS], vertex[2];

	for (size_t i = 0; i < size; ++i)	{
		p[i] = { points[i].x(), points[i].y()};
	}
	double distance = findNearestPointsInN2(p, size, vertex);
	if (vertex != NULL) {
		line = new QLine(vertex[0].x, vertex[0].y, vertex[1].x, vertex[1].y);
	}
	update();
}

void NearestPoints::clear() {
	points.clear();
	update();
}