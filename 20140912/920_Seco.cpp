/*************************************************************************************************************************
 * UVa 920
 http://uva.onlinejudge.org/external/9/p920.pdf
 *
 * Classification: CG
 *
 * Author: Diego Seco
 *
 * Date: 20-09-2014
 *
 * Description: Triangles, line equation
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool comparator(pair<int,int> p1, pair<int,int> p2) {
	return p1.first < p2.first;
} 

float computeSide(float p1x, float p1y, float p2x, float p2y) {
	return hypot(p2x-p1x,p1y-p2y);
}

struct line{float a,b,c;};

void pointsToLine(float p1x, float p1y, float p2x, float p2y, line *l) {
	l->a = -(float)(p1y - p2y) / (p1x - p2x);
	l->b = 1.0;
	l->c = -(float)(l->a * p1x) - (l->b * p1y);
}

float getX(line l, float y) {
	return (-1*y*l.b-l.c)/l.a;
}

int main() {
	int testCases,n;
	vector<pair<int,int> > points;
	cin >> testCases;
	while(testCases--) {
		points.clear();
		pair<int,int> cPoint;
		cin >> n;
		while(n--) {
			cin >> cPoint.first >> cPoint.second;
			points.push_back(cPoint);
		}
		sort(points.begin(),points.end(),comparator);

		float sides = 0;
		float maxY = 0;
		pair<int,int> prevPoint = points[points.size()-1];
		for(int i=points.size()-2; i>=0; i--) {
			pair<int,int> cPoint = points[i];
			if(cPoint.second <= maxY) {
				prevPoint = cPoint;
				continue;
			}
			line l;
			pointsToLine(cPoint.first, cPoint.second, prevPoint.first, prevPoint.second, &l);
			sides += computeSide(cPoint.first, cPoint.second, getX(l,maxY), maxY);
			maxY = cPoint.second;
			prevPoint = cPoint;
		}
		printf("%.2f\n", sides);
	}
	return 0;
}
