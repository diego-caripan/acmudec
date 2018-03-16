#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)

void D(int x, string fin="\n"){
	return;
}

int main(){
	int n, aux, i;
	vector<int> vec;
	stack<int> sta;
	bool verif, lol=true;

	scanf("%d",&n);
	while(n!=0){
		scanf("%d",&aux);
		while (aux!=0){
			vec.push_back(aux);
			REP(i,1,n){scanf("%d",&aux);vec.push_back(aux);}

			i=1;
			verif = true;
			while (vec.empty()==false){
				if (sta.size()!=0 && sta.top()==vec[0]){
					D(sta.top());
					sta.pop();
					vec.erase(vec.begin());
				}
				else if(i > n) {verif=false; break;}
				else if (i<vec[0])sta.push(i++);
				else if (i==vec[0]){vec.erase(vec.begin());i++;}
				else {
					verif=false; break;
				}
			}

			if (verif)printf("Yes\n");
			else printf("No\n");

			vec.clear();
			sta = stack<int>();
			scanf("%d",&aux);
		}
		printf("\n");
		scanf("%d", &n);
	}
}