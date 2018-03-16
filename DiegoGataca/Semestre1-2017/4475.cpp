#include <bits/stdc++.h>

using namespace std;

int main(){
  int N,a,b,d,hora;
  char c;
  while(1){
    scanf("%d",&N);
    if(N == 0)break;
    vector <pair <int,char> > v(N);
    int in = 0,out = 0;
    for(int i = 0; i < N ; i++){
      scanf("%d:%d:%d",&a,&b,&d);
      getchar();
      scanf("%c",&c);
      if(c == 'X')out++;
      if(c == 'E')in++;
      v[i] = make_pair(a*3600+b*60+d,c);
    }
    sort(v.begin(),v.end());
    int meter = (N/2)-in;
    for(int i = 0; i < N; i++){
      if(meter == 0)break;
      if(v[i].second == '?'){
	v[i] = make_pair(v[i].first,'E');
	meter--;
      }
    }
    int mayor = 0,actual=0;
    for(int i = 0; i < N; i++){
      if(v[i].second == 'E')actual++;
      else actual--;
      mayor = max(mayor,actual);
    }
    printf("%d\n",mayor);
  }
  return 0;
}
