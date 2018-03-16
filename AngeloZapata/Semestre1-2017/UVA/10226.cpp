#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	bool flag = true;
	cin >> n;
	while(n){
		map <string,double> trees;
		if(flag) {
			cin.ignore();
			cin.ignore();
			flag = false;
		}
		string tree;
		double cont = 0;
		while(getline(cin,tree)){
			if(tree == "") break;
			trees[tree]++;
			cont++;
		}
		for(map<string,double>::iterator it=trees.begin(); it!=trees.end(); it++){
			cout << it->first << " ";
			printf("%.4f\n",it->second/cont *100);
		}
		trees.clear();
		if(n > 1) cout << endl;
		n--;
	}
	return 0;
}