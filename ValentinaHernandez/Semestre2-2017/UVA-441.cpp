#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<vector<int> > vec;

void resp(vector<int> v){
   for(int a=0 ; a<v.size() ; a++)
      for(int b=a+1 ; b<v.size() ; b++)
         for(int c=b+1 ; c<v.size() ; c++)
            for(int d=c+1 ; d<v.size() ; d++)
               for(int e=d+1 ; e<v.size() ; e++)
                  for(int f=e+1 ; f<v.size() ; f++){
                     printf("%d %d %d %d %d %d\n",v[a],v[b],v[c],v[d],v[e],v[f]);
                  }
}

int main( ){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int k;
   int c = 0;
   while(cin >> k){
      if(k == 0) break;
      vector<int> v;
      if(c == 0) c++;
      else
         puts("");
      //cout << "k: " << k << endl;
      for(int n=0 ; n<k ; n++){
         int x;
         cin >> x;
         v.pb(x);
      }
      resp(v);
      v.clear();
   }
   return 0;
}