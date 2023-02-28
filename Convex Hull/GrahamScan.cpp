#include <iostream>
#include <stack>
using namespace std;

class Point {
public:
	int x, y;

    Point() {
        x = 0; 
        y = 0;
    } 

    Point(int x, int y) : x(x), y(y) {} 

    Point nextToTop(stack<Point> &stk) {
        Point p = stk.top();
        stk.pop();
        Point res = stk.top();
        stk.push(p);
        return res;
    }


    void swap(Point &point1, Point &point2) {
	    Point temp = point1;
	    point1 = point2;
	    point2 = temp;
    }

    int cartesianDist(Point point1, Point point2) {
        return (point1.x - point2.x)*(point1.x - point2.x) +
            (point1.y - point2.y)*(point1.y - point2.y);
    }

    int orientation(Point p, Point q, Point r) {
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        if (val == 0) return 0; 
        return (val > 0)? 1: 2; 
}	 	  	 	 		      	  		      	     	 	

};

Point point0;
Point temp;

int compare(const void *vp1, const void *vp2) {
Point *point1 = (Point *)vp1;
Point *point2 = (Point *)vp2;

int o = temp.orientation(point0, *point1, *point2);
if (o == 0)
	return (temp.cartesianDist(point0, *point2) >= temp.cartesianDist(point0, *point1))? -1 : 1;

return (o == 2)? -1: 1;
}

void convexHull(Point points[], int n) {
int ymin = points[0].y, min = 0;
for (int i = 1; i < n; i++) {
	int y = points[i].y;

	if ((y < ymin) || (ymin == y &&
		points[i].x < points[min].x))
		ymin = points[i].y, min = i;
}

temp.swap(points[0], points[min]);

point0 = points[0];
qsort(&points[1], n-1, sizeof(Point), compare);

int m = 1; 
for (int i=1; i<n; i++) {
	while (i < n-1 && temp.orientation(point0, points[i], points[i+1]) == 0)
	i++;
	points[m] = points[i];
	m++; 
}	 	  	 	 		      	  		      	     	 	

if (m < 3) return;
stack<Point> stk;
stk.push(points[0]);
stk.push(points[1]);
stk.push(points[2]);

for (int i = 3; i < m; i++) {
	while (stk.size()>1 && temp.orientation(temp.nextToTop(stk), stk.top(), points[i]) != 2)
		stk.pop();
	stk.push(points[i]);
}

while (!stk.empty()) {
	Point p = stk.top();
	cout << "(" << p.x << ", " << p.y <<")" << endl;
	stk.pop();  
    }
}

int main() {
    int numberOfPoints;
    cin >> numberOfPoints;
    Point points[numberOfPoints];
    for (auto i = 0; i < numberOfPoints;i++) {
        cin >> points[i].x >> points[i].y; 
    }
	convexHull(points, numberOfPoints);
	return 0;
}
	 	  	 	 		      	  		      	     	 	
