/*************************************************************************************************************************
 * UVa 11227 - The silver bullet
 http://uva.onlinejudge.org/external/112/11227.html
 *
 * Classification: CG
 *
 * Author: Roberto Asin & Diego Seco
 *
 * Date: 12-09-2014
 *
 * Description: Collinearity test
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

#define EPS 10E-6

using namespace std;

struct point {
	double x,y;
	
	void operator = (const point &other) {
		x=other.x;
		y=other.y;
	}
	bool operator == (const point &other) {
		return fabs(x-other.x)<EPS and fabs(y-other.y);
	}
	
};

ostream& operator<<(std::ostream& os, const point &p) {
	os << "(" << p.x << " " << p.y << ")";
	return os;
}	

bool operator < (const point &p1, const point &p2) {
		if(fabs(p1.x-p2.x)<EPS)
			return p1.y<p2.y;
		return p1.x < p2.x;
	}

double cross(point p, point q, point r) {
	return (r.x-q.x)*(p.y-q.y) - (r.y-q.y)*(p.x-q.x);
}

bool collinear(point p, point q, point r) {
	return fabs(cross(p,q,r)) < EPS;
}

int main() {
	int cases,n;
	int caseNum = 1;
	set<point> points;
	cin >> cases;
	while(cases--) {
		int maxCol = 2;
		points.clear();
		cin >> n;
		for(int i=0; i<n; i++) {
			point p;
			cin >> p.x >> p.y;
			points.insert(p);
		}
		for(set<point>::iterator it = points.begin();it!=prev(points.end(),2);it++) {
			for(set<point>::iterator it1 = next(it);it1!=prev(points.end(),1);it1++) {
				int localCol = 2;
				for(set<point>::iterator it2 = next(it1);it2!=points.end();it2++) {
					//cout << *it << " " << *it1 << " " << *it2 << " " << collinear(*it,*it1,*it2)<< endl;
					if(collinear(*it,*it1,*it2)) localCol++;
				}
				if(localCol>maxCol) maxCol=localCol;
			}
		}
		cout << "Data set #" << caseNum << " contains ";
		if(points.size()==1) {
			cout << "a single gnu." << endl;
		} else {
			cout << points.size() << " gnus, out of which a maximum of " << maxCol << " are aligned." << endl;
		}
		caseNum++;
	}

	return 0;
}
