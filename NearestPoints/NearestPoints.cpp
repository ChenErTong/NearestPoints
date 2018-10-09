#include <QInputDialog>
#include <QMessageBox>
#include <QStatusBar>
#include <string>
#include <sstream>
#include<time.h>
#include "NearestPoints.h"
#include "NearestPointsAlgorithm.h"
#include "RandomPoints.h"

using namespace std;

Point allPoints[MAX_POINTS];
int number = 0;
NearestPoints::NearestPoints(QWidget *parent)	: QMainWindow(parent){
	ui.setupUi(this);
	this->setFixedSize(800, 800);

	QMenuBar *menuBar = new QMenuBar();
	QMenu *algorithmMenu = new QMenu("Execute");
	QAction *algorithmNLogN = algorithmMenu->addAction("Merge Sort");
	QAction *algorithmN2 = algorithmMenu->addAction("Normal");
	menuBar->addMenu(algorithmMenu);
	QAction *clear = menuBar->addAction("Clear");
	QAction *generate = menuBar->addAction("Generate");

	QStatusBar *statusBar = new QStatusBar();
	statusBar->setSizeGripEnabled(false);
	this->setMenuBar(menuBar);
	this->setStatusBar(statusBar);
	this->connect(algorithmNLogN, &QAction::triggered, this, &NearestPoints::execute);
	this->connect(algorithmN2, &QAction::triggered, this, &NearestPoints::execute);
	this->connect(clear, &QAction::triggered, this, &NearestPoints::clear);
	this->connect(generate, &QAction::triggered, this, &NearestPoints::generate);

	pointPen = QPen(Qt::black);
	linePen = QPen(Qt::red);
	pointPen.setWidth(PEN_SIZE);
	linePen.setWidth(PEN_SIZE);
}

void NearestPoints::paintEvent(QPaintEvent *){
	if (points.size() > MAX_VISIBLE_POINTS) {
		return;
	}
	QPainter painter(this);

	painter.setPen(pointPen);
	painter.drawPoints(points);
	if (line != NULL) {
		painter.setPen(linePen);
		painter.drawLine(*line);
		line = NULL;
	}
}

void NearestPoints::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		number = 0;
		points.append(QPoint(event->x(), event->y()));
		update();
	}
}

void NearestPoints::execute() {
	QAction* action = qobject_cast<QAction*>(QObject::sender());
	QString text = action->text();
	int size = points.size();
	if (size < 2 && number == 0) return;
	if (number == 0) {
		for (size_t i = 0; i < size; ++i) {
			allPoints[i] = { points[i].x(), points[i].y() };
		}
		number = size;
	}
	Point vertex[2];

	clock_t t1, t2;
	double distance;
	if (text == "Merge Sort") {
		t1 = clock();
		distance = findNearestPointsInNLgN(allPoints, number, vertex);
		t2 = clock();
	} else {
		t1 = clock();
		distance = findNearestPointsInN2(allPoints, number, vertex);
		t2 = clock();
	}

	if (vertex != NULL) {
		line = new QLine(vertex[0].x, vertex[0].y, vertex[1].x, vertex[1].y);
	}

	stringstream ss;
	ss << number << " points; (" << vertex[0].x << "," << vertex[0].y << ") (" << vertex[1].x << "," << vertex[1].y << "); ";
	ss << "Distance " << distance;
	ss << "; Running time " << (double)(t2 - t1) / CLOCKS_PER_SEC << " sec.";
	this->statusBar()->showMessage(ss.str().c_str());

	update();
}

void NearestPoints::clear() {
	points.clear();
	update();
}

void NearestPoints::generate() {
	bool ok;
	number = QInputDialog::getInt(this, tr("Generation"), tr("Input the number of points"), 0, 2, MAX_POINTS, 1, &ok, Qt::MSWindowsFixedSizeDialogHint);
	if (ok) {
		if (number > MAX_VISIBLE_POINTS) {
			randomWithoutRepeat(allPoints, number, 0, MAX_POINTS);
			points.clear();
			update();
			stringstream ss;
			ss << number << " points have been generated. Bacuse the number is too large for the panel to display, please choose the algorithm on the panel directly.";
			QMessageBox::information(NULL, "Notice", ss.str().c_str());
		} else {
			randomWithoutRepeat(allPoints, number, 0, WINDOW_SIZE);
			points.clear();
			for (int i = 0; i < number; ++i) {
				points.append(QPoint(allPoints[i].x, allPoints[i].y));
			}
			update();
		}
	}
}