#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, vector<int> wt, vector<int> val, int n){
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++){
       for (w = 0; w <= W; w++){
           if (i==0 || w==0)  K[i][w] = 0;
           else if (wt[i-1] <= w)  K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else    K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
 
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    vector <int> w,val;
    int num;
    cin>>num;
    for(int j=0;j<num;j++){
      int a,b;
      cin>>a>>b;
      val.push_back(a);
      w.push_back(b);
    }
    int sum = 0;
    int f,mw;
    cin>>f;
    for(int i=0;i<f;i++){
      cin>>mw;
      sum+=knapSack(mw, w, val, num);
    }
    cout<<sum<<'\n';
  }
    return 0;
}
