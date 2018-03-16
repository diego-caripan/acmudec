#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,c;
	cin >>c;
	for(int h=0; h<c; h++){
		cin >> n;
		int sum = 0, summax = 0, sum2 = 0, aux,s=1,f=1,smax=1,fmax=1;
		for(int i=0; i<n-1; i++){
			cin >> aux;
			sum += aux;
			if(sum <= 0){
				if(sum >= summax) {
					summax = sum;
					f = i+1;
					if(f-s > fmax-smax){
						smax = s;
						fmax = f;
					}
				}
				sum = 0;
				s = i+1;
			}
			if(sum >= summax) {
				summax = sum;
				f = i+1;
				if(f-s > fmax-smax){
						smax = s;
						fmax = f;
				}
			}
		}
		(summax>0)? cout << "The nicest part of route " << h+1 << " is between stops " <<smax+1 << " and " << fmax+1 << "\n":
					cout << "Route " << h+1 << " has no nice parts\n";

	}
	return 0;
}