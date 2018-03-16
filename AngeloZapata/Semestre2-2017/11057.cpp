#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,aux,res;
	while(cin >> n){
		vector <int> vec;	
		for(int i=0; i<n; i++){
			cin >> aux;
			vec.push_back(aux);
		}
		cin >> res;
		int i,j;
		sort(vec.begin(),vec.end());
		i=0;
		j=vec.size()-1;
		int res1,res2;
		while(j>i){
			if((vec[i] + vec[j]) == res){
				res1 = vec[i];
				res2 = vec[j];
				i++;
				j--;
			}
			else if((vec[i] + vec[j]) > res){
				j--;
			}
			else{
				i++;
			}
		}
		cout << "Peter should buy books whose prices are " << res1 << " and " << res2 << ".\n\n";
	}
	return 0;

}