#include <bits/stdc++.h>
using namespace std;

int main(){
    int c,n,m,x;
    cin>>c;
    while(c--){
        //cin>>n>>m;
        //nose como hacerlo con cin esta parte
        while(scanf("%d %d", &n, &m) == 2){
            map<int,int> Map;
            while(n--){
                cin>>x;
                Map[x]++;
            }
           // cout<<"los n"<<endl;
            while(m--){
                cin>>x;
                Map[x]--;
            }
            //cout<<"los m"<<endl;
            x=0;
            map<int,int>::iterator it;
            for(it = Map.begin();it != Map.end(); it++)
                x += abs(it->second);
            cout<<x<<endl;;
        }
    }
}