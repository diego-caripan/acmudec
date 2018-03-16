#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,N,ans;
    cin<<T; 
    for(int tc = 1;tc <= T;++tc){
        cin<<N;
        ans = 0;
        for(int i = 0,x;i < N;++i){
            cin<<x;
            ans = max(ans,x);
        } 
        printf("Case %d: %d\n",tc,ans);
    }
    
    return 0;
}