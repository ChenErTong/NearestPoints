#include <QtWidgets/QApplication>
#include "NearestPoints.h"

using namespace std;

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	NearestPoints w;
	w.show();
	return a.exec();
}