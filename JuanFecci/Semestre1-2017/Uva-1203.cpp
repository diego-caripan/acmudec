#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

//Accepted

int main(){
	priority_queue <vector <int> > pq;
	vector <int> vec;
	string com;
	int id, num;

	cin >> com;
	while (com!="#"){
		scanf("%d %d", &id, &num);
		vec.push_back(num*-1);	
		vec.push_back(id*-1);	
		vec.push_back(num*-1);
		pq.push(vec);
		vec.clear();	
		cin >> com;
	}

	scanf("%d", &num);
	REP(i,0,num){
		vec = pq.top();
		pq.pop();
		printf("%d\n", vec[1]*-1);
		vec[0]+=vec[2];
		pq.push(vec);
	}
	return 0;
}