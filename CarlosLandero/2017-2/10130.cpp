#include<cstdio>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }
 
int knapSack(int W, int wt[], int val[], int n){
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++){
       for (w = 0; w <= W; w++){
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   return K[n][W];
}
 
int main(){
    int T=0,N=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        int P[N];
        int W[N];
        for(int i=0;i<N;i++){
            scanf("%d %d",&P[i],&W[i]);
        }
        int G=0;
        scanf("%d",&G);
        int MW[G];
        int result=0;
        for(int j=0;j<G;j++){
            scanf("%d",&MW[j]);
            result += knapSack(MW[j],W,P,N);
        }
        printf("%d\n",result);
    }
    return 0;
}
