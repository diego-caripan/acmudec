/*************************************************************************************************************************
 * UVa 11100 - The trip
 http://uva.onlinejudge.org/external/111/11100.html
 *
 * Classification: Greedy
 *
 * Author: Roberto Asin & Diego Seco
 *
 * Date: 12-09-2014
 *
 * Description: 
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int main() {
	int n;
	int max = 0;
	int max_val = 0;
	bool first = true;
	map<int,int> elements;
	while(true) {
		max = 0;
		max_val = 0;
		cin >> n;
		if(n == 0)
			break;
		if(first) first = false;
		else cout << endl;
		elements.clear();
		for(int i=0; i<n; i++) {
			int curr;
			cin >> curr;
			if(elements.find(curr)!=elements.end()) {
				elements[curr]++;
			} else {
				elements[curr] = 1;
			}
			if(elements[curr]>max_val) {
				max_val = elements[curr];
				max = curr;
			}
		}
		vector<vector<int> > sets(max_val,vector<int>());

		int i = 0;
		for(map<int,int>::iterator miIt = elements.begin(); miIt!=elements.end();++miIt) {
			for(int j=0; j<miIt->second; j++) {
				sets[i].push_back(miIt->first); 
				i = (i+1)%max_val;
			}
		}

		cout << max_val << endl;
		for(int j=0; j<sets.size(); j++) {
			for(int k=0; k<sets[j].size();k++) {
				if(k != 0)
					cout << " ";
				cout << sets[j][k];
			}
			cout << endl;
		}
	}
	return 0;
}
