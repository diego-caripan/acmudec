// César Bolívar Severino
// resuelto propio
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);
	if (n <= k) {
		printf("%d\n", 2);
	}
	else {
		printf("%d\n", (int)ceil(2*(n/(double)k)));
	}
	return 0;
}
