#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;



int BAR(int lenght,vector<int> bars){


	if(lenght == 0) return 1;

	else if(bars.empty()) return 0;

	int aux = bars.back();
	bars.pop_back();


	if(lenght != 0) return max(BAR(lenght-aux,bars),BAR(lenght,bars));

}

int main(){

	int n,lenght,n_bars,aux;
	vector <int> bars;

	cin >> n;

	for(int x = 0;x < n;x++){

		cin >> lenght;
		cin >> n_bars;

		for (int i = 0; i < n_bars; i++){
			cin >> aux;
			bars.push_back(aux);
		}
		if(BAR(lenght,bars)) printf("YES\n");
		else printf("NO\n");

		bars.clear();

	}





	return 0;
}
