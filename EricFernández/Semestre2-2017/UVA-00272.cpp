#include <bits/stdc++.h>
using namespace std;

int main(){
	char mander;
	bool abre=false;
	/*
	La pa leer a la mala caracter por caracter
	*/
	while((mander=getchar())!= EOF){
		if(mander=='"'){
            if((abre = !abre)){
                cout<<"``";
            }
            else{
                cout<<"''";
            }
		}
		else{
			cout<<mander;
		}

	}
	cout<<endl;
	return 0;
}
