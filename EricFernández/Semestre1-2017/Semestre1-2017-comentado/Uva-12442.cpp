/*
 * Sai Cheemalapati
 * UVA 12442: Forwarding emails
 *
 */
 
#include <cstdio>
#include <vector>
 
using namespace std;
//El problema consiste en calcular la ruta mas larga(no en pesos, si no saltos de nodos posibles) entre el grafo de un nodo a otro 
int T, N, a, b;
vector<int> graph, sum;
vector<bool> vis;
 //metodod dfs definido de forma recursiva que retorna el camino mas largo
int dfs(int u) {
    vis[u] = true;
    int tot = 0;
    if(graph[u] != -1 && !vis[graph[u]])
        tot += 1 + dfs(graph[u]);
    vis[u] = false;
    return sum[u] = tot;
}
 
int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d", &N);
        //asigna los valores predeterminados
        graph.assign(N, -1);
        sum.assign(N, -1);
        vis.assign(N, false);
        //lee de forma a sigue a b
        for(int i = 0; i < N; i++) {
            scanf("%d %d", &a, &b);
            graph[a - 1] = b - 1;
        }
        //calcula el camino mas largo
        int ans = 0, best_len = 0;
        for(int i = 0; i < N; i++) {
            if(sum[i] == -1) dfs(i);
            if(sum[i] > best_len) {
                best_len = sum[i];
                ans = i;
            }
        }
        //imprime el caso y su respectiva ruta mas larga
        printf("Case %d: %d\n", t, ans + 1);
    }
}