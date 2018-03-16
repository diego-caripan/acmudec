#include <bits/stdc++.h>

using namespace std;

typedef long long intt;
typedef pair<int, int> par;
typedef vector<vector<int> > graph;
typedef vector<vector<par> > wgraph;
#define pb push_back
#define ppb pop_back


class Dinic {
  struct edge {
    int to, rev;
    intt f, cap;
  };
  vector<vector<edge> > g;
  vector<intt> dist;
  vector<int> q, work;
  int n, sink;
  bool bfs(int start, int finish) {
    dist.assign(n, -1);
    dist[start] = 0;
    int head = 0, tail = 0;
    q[tail++] = start;
    while (head < tail) {
      int u = q[head++];
      for (const edge &e : g[u]) {
	int v = e.to;
	if (dist[v] == -1 and e.f < e.cap) {
	  dist[v] = dist[u] + 1;
	  q[tail++] = v;
	}
      }
    }
    return dist[finish] != -1;
  }
  intt dfs(int u, intt f) {
    if (u == sink)
      return f;
    for (int &i = work[u]; i < (int)g[u].size(); ++i) {
      edge &e = g[u][i];
      int v = e.to;
      if (e.cap <= e.f or dist[v] != dist[u] + 1)
	continue;
      intt df = dfs(v, min(f, e.cap - e.f));
      if (df > 0) {
	e.f += df;
	g[v][e.rev].f -= df;
	return df;
      }
    }
    return 0;
  }
public:
  Dinic(int n) {
    this->n = n;
    g.resize(n);
    dist.resize(n);
    q.resize(n);
  }
  // aristas bidireccionales !!
  void add_edge(int u, int v, intt cap) {
    edge a = {v, (int)g[v].size(), 0, cap};
    edge b = {u, (int)g[u].size(), 0, cap};
    g[u].pb(a);
    g[v].pb(b);
  }
  intt max_flow(int source, int dest) {
    sink = dest;
    intt ans = 0;
    while (bfs(source, dest)) {
      work.assign(n, 0);
      while (intt delta = dfs(source, 1000)) ans += delta;
    }
    return ans;
  }
};



int main(){
  int n,m,g,a,b,sumara,sumarb;
  char c;
  while(1){
    scanf("%d %d %d",&n,&m,&g);
    if(n == 0 && m == 0 && g == 0)break;
    Dinic D(2*(n-1) + 2);
    vector < vector < vector <int> > > juegos(n);
    for(int i = 0; i < n; i++){
      juegos[i].resize(n);
    }
    int ganados = 0,jugue=0,sumar=0;
    for(int i = 0;i < g; i++){
      scanf("%d %c %d",&a,&c,&b);
      switch(c){
      case '<':
	sumara = 0;
	sumarb = 2;
	break;
      case '=':
	sumara = 1;
	sumarb = 1;
	break;
      case '>':
	sumara = 2;
	sumarb = 0;
	break;
      }
      juegos[a][b].pb(sumara);
      juegos[b][a].pb(sumarb);
      if(a != 0)sumar+=sumara;
      if(b != 0)sumar += sumarb;
    }
    for(int j = 1; j < n; j++){
      for(int k = 0; k < juegos[0][j].size();k++){
	jugue++;
	ganados+=juegos[0][j][k];
      }
    }
    ganados+= ((n-1)*m - jugue)*2;
   // printf("sumar = %d   ganados = %d\n",sumar,ganados);
    vector <int> entrada(n,0);
    for(int i = 1; i < n; i++){ 	
      entrada[i] = (n-i-1)*m*2;
     // printf("nodo %d con entrada = %d\n",i,(n-i-1)*m*2);
    }
   //  for(int i = 1; i < n; i++)printf("entrada de %d es %d\n",i,entrada[i]);
    vector <int>flujos(n,ganados-1);
    for(int i = 1; i < n; i++){
      for(int j = 0; j < n; j++){
	if(i != j)for(int k = 0; k < juegos[i][j].size();k++){
	    flujos[i]-= juegos[i][j][k];
	    if(j > i ){
	      //  printf("entre con %d %d\n",i,j);
	      entrada[i]-=2;
	    }
	  }
      }
    }
      // puts("mis flujos");
    for(int i = 1; i < n; i++){
     // printf("nodo %d = %d\n",i,entrada[i]);
    }
    bool imposible = false;
    for(int i = 1; i < n; i++){
    	if(flujos[i] < 0){
    		imposible = true;
    		break;
    	}
      //printf("nodo %d = %d\n",i,flujos[i]);
      }
      if(imposible){
      	puts("N");
      	continue;
      }
    for(int i = 1; i < n; i++){
//printf("conecto nodo %d con %d con un flujo de %d\n",0,i,entrada[i]);
//printf("conecto nodo %d con %d con un flujo de %d\n",i,i-1+n,entrada[i]);
      D.add_edge(0,i,entrada[i]);
      D.add_edge(i,i-1+n,entrada[i]);
    }
    for(int i = n; i < ((n-1)*2)+1;i++){
//printf("conecto nodo %d con %d con un flujo de %d\n",i,(n-1)*2 +1,flujos[i-n+1]);
    	D.add_edge(i,(n-1)*2 + 1,flujos[i-n+1]);
    }
    for(int  i = 1; i < n; i++){
      for(int j = i+1; j < n; j++){
	  int conex= m-juegos[i][j].size();
//	  printf("conecto nodo %d con %d con un limite de %d\n",i+n-1,j+n-1,2*conex);
	  D.add_edge(i+n-1,j+n-1,2*conex);	
      }
    }
    long long int respuesta = D.max_flow(0,(n-1)*2+1);
  //  printf("%d %d %lld\n",ganados + sumar,((n-1)*m*n),respuesta);
    if(sumar+respuesta+ganados == ((n-1)*m*n) )puts("Y");
    else puts("N");
  }
  return 0;
}
