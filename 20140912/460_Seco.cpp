/*************************************************************************************************************************
 * UVa 460 - Overlapping Rectangles 
 http://uva.onlinejudge.org/external/111/11100.html
 *
 * Classification: CG
 *
 * Author: Diego Seco
 *
 * Date: 13-09-2014
 *
 * Description: Rectangles, overlap
*/

#include <iostream>

using namespace std;
int main() {
	int testCases;
	bool first = true;
	cin >> testCases;
	while(testCases--) {
		if(first) first = false;
		else cout << endl;
		
		int xll1,yll1,xur1,yur1,xll2,yll2,xur2,yur2;
		cin >> xll1 >> yll1 >> xur1 >> yur1 >> xll2 >> yll2 >> xur2 >> yur2;
		if(xll1>=xur2 || xur1 <= xll2 || yll1>=yur2 || yur1<=yll2) {
			cout << "No Overlap" << endl;
			continue;
		}
		cout << max(xll1,xll2) << " " << max(yll1,yll2) << " " << min(xur1,xur2) << " " << min(yur1,yur2) << endl;

	}
	return 0;
}
