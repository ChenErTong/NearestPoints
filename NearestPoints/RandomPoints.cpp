#include"RandomPoints.h"
#include<random>
using namespace std;

void randomWithoutRepeat(Point* points, int size, int lowBound, int highBound) {
	default_random_engine e(0);
	uniform_int_distribution<int> u(lowBound, highBound);

	for (int i = 0; i < size; ++i){
		points[i] = Point{ u(e), u(e) };
	}
}