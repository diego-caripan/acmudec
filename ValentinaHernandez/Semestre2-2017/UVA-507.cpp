#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	for(int k=1 ; k<=N ; k++){
		int valor,sum = 0,t = 0,i = 0, j = 0, max = 0,x;
		cin >> x;
		for(int h=1 ; h<x ; h++){
			cin >> valor;
			sum += valor;
			if(sum > max || (sum == max && h-i > j-t)){
				t = i;
				j = h;
				max = sum;			
			}
			else if(sum < 0){
				i = h;
				sum = 0;
			}
		}
		if(max > 0){
			//if(t > 0 ) t+= 2;
			//else t = 1;
			cout << "The nicest part of route " << k << " is between stops " << t+1 << " and " << j+1 << "\n";
		}
		else
			cout << "Route " << k << " has no nice parts\n";
	}
	return 0;
}