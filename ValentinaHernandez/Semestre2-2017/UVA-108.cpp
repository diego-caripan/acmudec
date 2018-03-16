#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> v){
	int max = 0;
	//for(int k=1 ; k<=v.size() ; k++){
		int valor,sum = 0,t = 0,i = 0, j = 0,x;
		bool verif = false;
		for(int h=0 ; h<v.size() ; h++){
			//cin >> valor;
			sum += v[h];
			if(sum >= max){
				max = sum;
				verif = true;
			}
			else if(sum < 0){
				sum = 0;
			}
		}
		if(!verif){
			sort(v.begin(),v.end());
			max = v[v.size()-1];
		}
	
	return max;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<vector<int> > m(N,vector<int> (N,0));
	vector<int> asd;
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			int x;
			scanf("%d",&x);
			m[i][j] = x;
		}
	}
	int max = INT_MIN,sum;
	for(int i=0 ; i<N ; i++){
		asd = vector<int> (N,0);
		for(int j=i ; j<N ; j++){
			for(int h=0 ; h<N ; h++)
				asd[h] += m[h][j];
			sum = kadane(asd);
			if(sum > max) max = sum;
		}
	}
	printf("%d\n",max);
	return 0;
}
