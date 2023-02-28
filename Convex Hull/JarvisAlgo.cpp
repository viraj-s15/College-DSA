#include <iostream>
#include <vector>
using namespace std;

class Point{
    public: 
    int x;
    int y;

    Point() : x(0),y(0) {}

    Point(int x, int y) : x(x),y(y) {}

    int orientation(Point a, Point b, Point c) {
    	int val = (b.y - a.y) * (c.x - b.x) -
    			(b.x - a.x) * (c.y - b.y);

    	if (val == 0) return 0; 
    	return (val > 0)? 1: 2; 
    }
};

void convexHullJarvis(vector<Point> points, int n) {
	if (n < 3) return;

	vector<Point> hull;
    Point temp;
	int l = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[l].x)
			l = i;
	int a = l, b;
	do {
		hull.push_back(points[a]);
		b = (a+1)%n;
		for (int i = 0; i < n; i++) {
		    if (temp.orientation(points[a], points[i], points[b]) == 2) b = i;
		}
		a = b;
	} while (a != l); 

	for (int i = 0; i < hull.size(); i++) {
		cout << "(" << hull[i].x << ", "
			<< hull[i].y << ")\n";
    } 
}

int main() {
    int numberOfPoints;
    cin >> numberOfPoints;
    vector<Point> points(numberOfPoints);

    for (auto i = 0; i < numberOfPoints; i++) {
        cin >> points[i].x >> points[i].y; 
    }

	convexHullJarvis(points, numberOfPoints);
	return 0;
}
