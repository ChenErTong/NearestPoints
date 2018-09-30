#include<iostream>
#include <QtWidgets/QApplication>
#include "NearestPoints.h"
#include "NearestPointsAlgorithm.h"
#include "RandomPoints.h"

using namespace std;

#define POINT_NUM 1000000
Point points[POINT_NUM];

int main(int argc, char *argv[]){
	/*QApplication a(argc, argv);
	NearestPoints w;
	w.show();
	return a.exec();*/

	Point res[2];
	randomWithoutRepeat(points, POINT_NUM);

	double distance = findNearestPointsInNLgN(points, POINT_NUM, res);
	for (size_t i = 0; i < 2; i++) {
		cout << res[i].x << ";" << res[i].y << " ";
	}
	cout << endl << distance << endl;
}