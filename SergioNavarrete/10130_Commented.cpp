#include <cstdio>

using namespace std;

// Problema de la mochila 0/1 (DP)
// No puedes tomar mas de un objeto a la vez y puedes levantarte con un maximo de 30 kg de peso
// Un objeto tiene peso de 10 kg pero solamente puedes tomar el objeto una sola vez.

int main() {
	int T, i, j;
	scanf("%d", &T);
	while(T--) {
		int N, P, W, G, MW, Ans = 0;
		int DP[31] = {};
		scanf("%d", &N);
		for(i = 0; i < N; i++) {
			scanf("%d %d", &P, &W);
			for(j = 30; j >= W; j--)
				if(DP[j] < DP[j-W]+P)
					DP[j] = DP[j-W]+P;
		}
		scanf("%d", &G);
		while(G--) {
			scanf("%d", &MW);
			Ans += DP[MW];
		}
		printf("%d\n", Ans);
	}
    return 0;
}
