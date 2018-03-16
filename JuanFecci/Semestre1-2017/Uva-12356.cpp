#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){

	int B, S, L, R, auxL, auxR, lim;
	vector<int> soldadosL, soldadosR;

	scanf("%d %d",&S, &B);

	while (B!=0 && S!=0){

		REP(i,0,S){
			soldadosL.push_back(i-1);
			soldadosR.push_back(i+1);
		}
		lim = S;

		REP(i,0,B){

			scanf("%d %d",&L, &R);
			L--; R--;
			auxL=soldadosL[L];
			auxR=soldadosR[R];

			if (auxL==-1)cout << "* ";
			else{
				cout << auxL+1 << " ";
				soldadosR[auxL] = auxR;
			} 

			if (auxR==S)cout<< "*\n";
			else{
				cout << auxR+1 << "\n";
				soldadosL[auxR] = auxL;
			} 

		}

		D("-");
		soldadosL.clear();
		soldadosR.clear();

		scanf("%d %d",&S, &B);
	}	

}