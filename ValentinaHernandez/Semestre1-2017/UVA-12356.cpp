#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> l,r;
	int i,j,cont,S,B,L,R;
	while(true){
		cin >> S >> B;
		if(S==0 & B==0)
			break;
		for(i=0 ; i<=S ; i++){
			l.push_back(i-1);
			r.push_back(i+1);
		}
			l.push_back(0);
			r.push_back(0);
		for(i=0 ; i<B ; i++){
			cin >> L >> R; 
			l.at( r.at(R) ) = l.at(L);
			r.at( l.at(L) ) = r.at(R);
			if(l[L] < 1)
				cout << "* ";
			else
				cout << l[L] << " ";
			if(r[R] > S)
				cout << "*" << endl;
			else
				cout << r[R] << endl;
			}
			cout << "-" << endl;
			l.clear();
			r.clear();
		}
	return 0;
}