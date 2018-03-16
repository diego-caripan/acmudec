#include <bits/stdc++.h>
using namespace std;

int main(){
   int T, ntienda, min, max, temp;
   cin >> T;
   while (T--){
       min = 99; max = 0;
       cin >> ntienda;
       for (int i = 0; i < ntienda; ++i){
       	cin>>temp;
           if (temp < min)  min = temp;
           if (temp > max)  max = temp;
        }
        cout<<(max-min)*2<<endl;
    }
    return 0;
}