#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	double tot;
	string st;
	map <string, double> map;
	map <string, double>::iterator it;
	cin >> n;
	cin.ignore();
	cin.ignore();
	for(int i=0,i<n;i++){
		if (i!=0) cout << endl;
		tot = 0;
		while (true){
			if(getline(cin, st)){
				if (st.compare("") != 0){
					map[st] += 1;
					tot += 1;
				}
				else{
					break;
				}
			}
			else{
				break;
			}
		}
		for (it = map.begin(); it != map.end(); it++){
			cout << it->first;
			printf(" %.4lf\n", it->first, (it->second / tot)*100);
		}
		map.clear();
	}
	return 0;
}