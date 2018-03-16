/*************************************************************************************************************************
 * UVa 11516 - WiFi
 * http://uva.onlinejudge.org/external/115/11516.html 
 *
 * Classification: Binary Search
 *
 * Author: Javier González N.
 *
 * Date: 18-08-2014
 *
 * Description:
 * You can know if you can place n access points with a maximum distance of d.
 * If you can place de n points with distance d, then you can place them for all distance > d
 * The pattern is as follows (For example): 
 * Distance: 
 * 1 2 3 4 5 6 7
 * T T T T F F F
 * where T = True (you can place them with max dist = 3, for example) and F = false (you can't place them if dist is 5 or higher)
 * 
 * The problem is to find the point where T changes to F, binary search can do it.
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 100005

int n, m;
int houses[MAX];

bool isValid(double x) {
  int cnt = 1;
  double distance = houses[0] + x;
  
  for(int i = 1; i < m; i++) {
    if(houses[i] - distance > x) {
      distance = houses[i] + x;
      cnt++;
    }
  }

  return cnt <= n;
}

int main()
{
  int t;
  scanf("%d", &t);

  while(t--) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
      scanf("%d", &houses[i]);   
    }

    sort(houses, houses + m);

    double low, high, mid;
    low = 0;
    high = houses[m - 1];
    mid = 0.0f;

    while(high - low > 1e-9) {
      mid = (low + high) * 0.5f;
      if(isValid(mid)) {
	high = mid;
      } else {
	low = mid;
      }
    }

    printf("%.1f\n", mid);
  }
  
  return 0;
}
