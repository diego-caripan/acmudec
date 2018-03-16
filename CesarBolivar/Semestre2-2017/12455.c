#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const* argv[])
{
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++) {
		int n, p;
		scanf("%d %d\n", &n, &p);
		int bar[p];
		for (int j = 0; j < p; j++) {
			scanf("%d\n", &bar[j]);
		}
		int max = 1 << p;
		bool found = false;
		for (int j = 0; j < max; j++) {
			int aux = j;
			int sum = 0;
			for (int k = 0; k < p; k++) {
				sum += aux % 2 == 1 ? bar[k] : 0;
				aux /= 2;
			}
			if (sum == n) {
				puts("YES");
				found = true;
				break;
			}
		}
		if (!found) {
			puts("NO");
		}
	}
	return 0;
}
