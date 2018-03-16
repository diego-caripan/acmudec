#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; /*n: dragones, m: los que matan*/
	while(cin >> n >> m){
		priority_queue<int> dragon,knight;
		if(n == 0 && m == 0) break;
		int min = 0;
		for(int i=0 ; i<n ; i++){
			int x;
			cin >> x;
			if(i == 0 || x < min) min = x;
			dragon.push(-x);
		}
		for(int i=0 ; i<m ; i++){
			int x;
			cin >> x;
			if(x >= min)
				knight.push(-x);
		}
		if(dragon.size() > knight.size())
			cout << "Loowater is doomed!\n";
		else{
			int total =  0;
			while(!dragon.empty()){
				int d,k;
				d = -dragon.top();
				k = -knight.top();
				if(k >= d){
					dragon.pop();
					knight.pop();
					total += k;
				}
				else{
					knight.pop();
				}
				if(knight.empty())
					break;
			}
			if(!dragon.empty())
				cout << "Loowater is doomed!\n";
			else{
				cout << total << "\n";
			}
		}
	}
	return 0;
}