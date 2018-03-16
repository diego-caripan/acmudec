#include <bits/stdc++.h>

using namespace std;

unsigned long long table[30010];
int S[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

void count(){
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<11; i++)
        for(int j=S[i]; j<=30000; j++)
            table[j] += table[j-S[i]];
}

int main(){
   count();
   double n = 0;
   while(scanf("%lf",&n) && n != 0.00){
        printf("%6.2f%17lld\n",n,table[(int)round(n*100)]);
   }
   return 0;
}
