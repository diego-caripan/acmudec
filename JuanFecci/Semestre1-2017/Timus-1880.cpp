#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <int> vec1, vec2;
	int a,b,c, i, aux;
	int j, k;

	cin >> a;
	for(i=0; i<a; i++){
		cin >> aux;
		vec1.push_back(aux);
	}

	cin >> b;
	for(i=0; i<b; i++){
		cin >> aux;
		vec2.push_back(aux);
	}

	int count=0;
	cin >> c;
	for(i=0; i<c; i++){
		cin >> aux;
		for (j=0; j<b; j++){
			if (vec2[j] == aux){
				for (k=0; k<a; k++){
					if (vec1[k] == aux){
						count++; break;
					}
				}
			}
		}
	}

	cout << count << '\n';
	return 0;

}