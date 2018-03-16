#include <bits/stdc++.h>  
using namespace std;  

#define rep(i,a,n) for(int i=a;i<(int)n;++i)
typedef long long ll;

int knapSack(int W, vector <int> wt, vector <int> val, int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
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
	
	int n; scanf("%d", &n);

	int N, P, W, G, MW;
	vector <int> wt, val;

	int suma;
	rep(i,0,n){
		scanf("%d", &N);
		wt.clear(); val.clear();
		suma = 0;

		rep(j,0,N){
			scanf("%d %d", &P, &W);
			val.push_back(P);
			wt.push_back(W);
		}


		scanf("%d", &G);
		rep(j,0,G){
			scanf("%d", &MW);
			suma += knapSack(MW, wt, val, N);
		}

		printf("%d\n", suma );
	}

}