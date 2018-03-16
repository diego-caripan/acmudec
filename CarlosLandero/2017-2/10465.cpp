#include <bits/stdc++.h>

using namespace std;

int burgersAt[10000];
int beer;

int numberOfBurgers(int n, int m, int t){
    beer = 0;
    for(int i=0;i<=t;i++){
        burgersAt[i]=-1;
    }
    burgersAt[0]=0;
    for(int i=1;i<=t;i++){
        if (i >= m && burgersAt[i - m] >= 0){
            burgersAt[i] = burgersAt[i - m] + 1;
        }
        if (i >= n && burgersAt[i - n] >= 0){
            burgersAt[i] = max(burgersAt[i - n] + 1, burgersAt[i]);
        }
    }
    if(burgersAt[t]>=0){
        return burgersAt[t];
    }
    else{
        beer=1;
        while(burgersAt[t-beer]==-1){
            ++beer;
        }
        return burgersAt[t-beer];
    }
}

int main(){
    int n,m,t;
    while(scanf("%d %d %d",&n,&m,&t)!=EOF){
        int x = numberOfBurgers(n,m,t);
        if(beer==0){
            printf("%d\n",x);
        }
        else if(beer>0){
            printf("%d %d\n",x,beer);
        }
    }
    return 0;
}