#include"RandomPoints.h"
#include<random>
using namespace std;

void randomWithoutRepeat(Point* points, int size) {
	default_random_engine e(0);
	uniform_int_distribution<int> u(0, MAX_NUM);

	for (int i = 0; i < size; ++i){
		points[i] = Point{ u(e), u(e) };
	}
}