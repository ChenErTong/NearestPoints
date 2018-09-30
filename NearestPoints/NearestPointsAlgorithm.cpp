#include<algorithm>
#include<vector>
#include<float.h>
#include "NearestPointsAlgorithm.h"

using namespace std;

int compareX(Point p1, Point p2) {
	if(p1.x < p2.x) return 1;
	return 0;
}

int compareY(Point p1, Point p2) {
	if (p1.y < p2.y) return 1;
	return 0;
}

double getDistance(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double findNearestPointsInN2(Point* points, int size, Point* vertex) {
	double minDistance = DBL_MAX, distance;
	for (int i = 0; i < size - 1; ++i)	{
		for (int j = i + 1; j < size; ++j)	{
			if ((distance = getDistance(points[i], points[j])) < minDistance) {
				minDistance = distance;
				vertex[0] = Point(points[i]);
				vertex[1] = Point(points[j]);
			}
		}
	}
	return minDistance;
}

double findNearestPointsInNLgN(Point* points, int size, Point* vertex) {
	sort(points, points + size, compareX);
	return findNearestPoints(points, 0, size - 1, vertex);
}

double findNearestPoints(Point* points, int low, int high, Point* vertex) {
	if (high == low) return DBL_MAX;
	if (high == low + 1) {
		vertex[0] = Point(points[low]);
		vertex[1] = Point(points[high]);
		return getDistance(vertex[0], vertex[1]);
	}
	Point leftPair[2], rightPair[2];
	int middle = (high - low) / 2 + low;
	double leftDistance = findNearestPoints(points, low, middle, leftPair);
	double rightDistance = findNearestPoints(points, middle + 1, high, rightPair);

	double distance, minDistance, middleLine = (points[middle].x + points[middle + 1].x) / 2.0;
	if (leftDistance < rightDistance) {
		minDistance = leftDistance;
		vertex[0] = Point(leftPair[0]);
		vertex[1] = Point(leftPair[1]);
	} else {
		minDistance = rightDistance;
		vertex[0] = Point(rightPair[0]);
		vertex[1] = Point(rightPair[1]);
	}
	
	vector<Point> pointsWithinBound;
	int i1 = middle, i2 = middle + 1;
	double leftBound = middleLine - minDistance, rightBound = middleLine + minDistance;
	while (i1 >= low && points[i1].x > leftBound) {
		pointsWithinBound.push_back(Point{ points[i1].x, points[i1].y }); --i1;
	}
	while (i2 <= high && points[i1].x < rightBound) {
		pointsWithinBound.push_back(Point{ points[i2].x, points[i2].y }); ++i2;
	}
	sort(pointsWithinBound.begin(), pointsWithinBound.end(), compareY);
	int size = pointsWithinBound.size();

	for (int i = 0; i < size - 1; i++)	{
		int j = i + 1;
		double topBound = pointsWithinBound[i].y + minDistance;
		while (j < size && pointsWithinBound[j].y < topBound && i + 8 > j) {
			if ((distance = getDistance(pointsWithinBound[i], pointsWithinBound[j])) < minDistance) {
				minDistance = distance;
				vertex[0] = Point(pointsWithinBound[i]);
				vertex[1] = Point(pointsWithinBound[j]);
			}
			++j;
		}
	}

	return minDistance;
}