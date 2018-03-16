#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,esp=0;
	cin>>n;
	while(n-- !=0){
		int a,b;
		cin>>a>>b;
		for(int i=0;i<b;i++){

            if(esp!=0)cout << endl;
            else esp++;

			for(int i2=1;i2<=a;i2++){
				for(int i3=1;i3<=i2;i3++)
					cout << i2;
					cout << endl;
			}
			for(int i2=a-1;i2>=1;i2--){
					for(int i3=i2;i3>=1;i3--)
					cout << i2;
					cout << endl;
			}
		}
	}
	//return 0;
}