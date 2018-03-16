#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){

	int N, B, aux;
	vector <int> balls, op;
	bool verif;

	while(1){
		cin >> N >> B;
		if (N==0 && B==0) break;

		REP(i,0,B){
			cin >> aux;
			balls.push_back(aux);
		}
		op = vector <int> (N,0);

		REP(i,0,balls.size()){
			REP(t,i+1,balls.size()){
				op[abs(balls[i] - balls[t])]=1;
			}
		}

		verif=true;
		REP(i,0,op.size()){
			if (op[i]==0){
				verif=false; break;
			}
		}

		if (verif) cout << "Y\n";
		else cout << "N\n";

	}

	return 0;
}