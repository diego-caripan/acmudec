#include <bits/stdc++.h>

using namespace std;

int main(){
	int ataque[11],defensa[11];
	int a,b;
	while(cin>>a>>b){
		if(a==0 && b==0){
			break;
		}
		for(int i=0;i<a;i++){
			cin>>ataque[i];
		}
		for(int i=0;i<b;i++){
			cin>>defensa[i];
		}
		sort(ataque,ataque+a);
		sort(defensa,defensa+b);
		if(ataque[0]<defensa[1]){
			cout<<"Y"<<endl;
		}else{
			cout<<"N"<<endl;
		}
	}
	return 0;
}