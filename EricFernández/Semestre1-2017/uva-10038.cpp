#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,aux;
	while(cin>>n){
		vector <int> vector1,vector2;
		for(int i=0;i<n;i++){
			cin>>aux;
			vector1.push_back(aux);
		}
		//cout<< "termino de insertar1"<<endl;
		for(int i=1;i<n;i++){
			vector2.push_back(abs(vector1[i]-vector1[i-1]));
		}
		//cout<< "termino de insertar2"<<endl;
		bool X=true;
		//cout<<vector2.size()<<endl;
		sort(vector2.begin(),vector2.end());
		/*cout<<"ordene..."<<endl;
		for(int i=0;i<vector2.size();i++){
			cout<<vector2[i]<<endl;
		}
		cout<<"....ordene"<<endl;
		*/
		for(int i=0;i<vector2.size();i++){
			if(vector2[i]!=i+1)X=false;
		}

	if(X==true)cout<<"Jolly"<<endl;
	else cout <<"Not jolly"<<endl;
	}
	return 0;

}
// 3 2 3 7          3 2 1
//  1 1 4            1 1