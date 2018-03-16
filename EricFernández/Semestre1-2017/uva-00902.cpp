#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> insertar;

int main(){
	int C,cont=0;
	string st1,st2,st3;
	map<string,int> mapa;
	map<string,int>::iterator it;
	while(cin>>C>>st1){		
		//cin.ignore(256,'\n');
		//getline(cin,st1);
		for(int i=0;i<=st1.size()-C;i++){
			st2=st1.substr(i,C);
			if (mapa.count(st2)>0)mapa.at(st2) +=1;
			mapa.insert(insertar(st2,1));
		}
		for(it=mapa.begin();it!=mapa.end();++it){
			//cout<<it->first<<"::"<<it->second<<endl;
			if(cont<it->second){
				cont=it->second;
				st3=it->first;
			}
		}
		cout<<st3<<endl;
		mapa.clear();
		cont=0;
	}
	return 0;
}