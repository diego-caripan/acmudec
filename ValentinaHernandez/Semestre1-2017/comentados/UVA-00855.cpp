// http://uva.onlinejudge.org/external/8/855.html
// Runtime : 0.044s
// Tag : median

// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;

int main ()
{
	int testCase;
	scanf ("%d", &testCase);

	while ( testCase-- ) {
		int s, a, f;//s: street; a:avenue; f:friends;
		scanf ("%d %d %d", &s, &a, &f);

		int p [50000 + 5]; //srteets
		int q [50000 + 5]; //avenues

		for ( int i = 0; i < f; i++ )
			scanf ("%d %d", &p [i], &q [i]);
		//se ordenan las calles y las avenidas
		sort (p, p + f); 
		sort (q, q + f);
		/*Si los amigos son pares, su media es f/2
		Si no es par, la media es (f-1)/2, entonces se devuelve 
		la mitad, en donde debería ser la junta.*/
		if ( f % 2 ) printf ("(Street: %d, Avenue: %d)\n", p [f / 2], q [f / 2]);
		else printf ("(Street: %d, Avenue: %d)\n", p [(f - 1) / 2], q [(f - 1) / 2]);
	}

	return 0;
}

// @END_OF_SOURCE_CODE	