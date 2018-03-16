#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;
#define EPS 0.0001
typedef pair<int, int> Point;

double dist(pair<int, int> p1, pair<int, int> p2) {
  return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

bool eq(double l1, double l2) {
  return fabs(l1 - l2) < 10e-6;
}


int cross( Point a, Point b )
{
  return a.first * b.second - a.second * b.first;
}


Point toVec( Point a, Point b)
{
  Point c;
  c.first = b.first-a.first;
  c.second = b.second - a.second;
  return c;
}

bool collinear( Point a, Point b, Point c)
{
  return  cross(toVec(a,b), toVec(b,c)) == 0;
}

int main() {
  int n;
  
  while(cin >> n) {
    vector< pair<int, int> > v;
    
    while(n--) {
      int p1, p2;
      cin >> p1 >> p2;

      v.push_back(make_pair(p1, p2));
    }

    int result = 0;

    for(int i = 0; i < v.size(); i++) {
      for(int j = i + 1; j < v.size(); j++) {
	for(int k = j + 1; k < v.size(); k++) {
	  if(i == j || j == k || i == k)
	    continue;
	  
	  pair<int, int> a, b, c;

	  a = v[i];
	  b = v[j];
	  c = v[k];

	  //cout << a.first << " " << a.second << endl; 
	  //cout << b.first << " " << b.second << endl;
	  //cout << c.first << " " << c.second << endl;
	  //cout << endl;

	  double l1, l2, l3;
	  l1 = dist(a, b);
	  l2 = dist(a, c);
	  l3 = dist(b, c);
	  
	  ///  cout << l1 << " " << l2 << " " << l3 << endl;

	  if( !collinear( a, b, c ) )
	    if(eq(l1, l2) || eq(l2, l3) || eq(l1, l3)) {
	      
	      
	      result++;
	    }
	  /*
	  if((eq(l1, l2) && !eq(l1, l3) && !eq(l2, l3))  ) {
	    printf("(%d %d), (%d %d) \n", a.first,a.second, b.first,b.second);
	    printf("(%d %d), (%d %d) \n", a.first,a.second, c.first,c.second);
	    printf("\n");
	    result++;
	  }
	  else if( (eq(l2, l3) && !eq(l2, l1) && !eq(l3, l1)) )
	    {
	      printf("(%d %d), (%d, %d) \n", a.first, a.second, b.first, b.second);
	      printf("(%d %d), (%d, %d) \n", b.first, b.second, c.first, c.second);
	      printf("\n");
	      result++;
	    }
	  else if( eq(l1, l3) && !eq(l1, l2) && !eq(l3, l2) )
	    {
	      printf("(%d %d) , (%d %d) \n", a.first, a.sd, b.first, b.second);
	      printf("(%d %d) , (%d %d) \n", b.first, b.second, c.first, c.second);
	      printf("\n");
	      result++;
	    }*/
	  //cout << l1 << " " << l2 << " " << l3 << endl;
	}
      }
    }
    
    cout << result << endl;
  }

  return 0;
}
