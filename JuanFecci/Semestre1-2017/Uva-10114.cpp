#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){

	int times, a, ite, mes;
	double suma, original, b, car, money, x, months;
	vector < pair <int, double> > elements;

	while(1){
		cin >> months >> suma >> original >> times;
		if (months < 0) break;

		elements.clear();

		REP(i,0,times){
			cin >> a >> b;
			elements.push_back(make_pair(a,b));
		}

		car = (original+suma)*(1-elements[0].second);

		ite = 1;
		mes = 1;
		x = original/months;

		money = original;

		if (money < car)cout << "0 months\n";
		else{

			while(1){
				money-=x;
				if (mes >= elements[ite].first){
					car*=(1-elements[ite].second);
					if (ite != times-1) ite++;
				}
				else{
					car*=(1-elements[ite-1].second);
				}

				if (money < car){
					if (mes == 1) cout << "1 month\n";
					else cout << mes << " months\n";
					break;
				}

				mes += 1;
			}
		}
	}

}