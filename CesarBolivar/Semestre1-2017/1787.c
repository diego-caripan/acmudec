// César Bolívar Severino
// resuelto propio
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int k, n;
	int autos = 0;
	scanf("%d", &k);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		autos = autos + tmp - k;
		if (autos < 0) {
			autos = 0;
		}
	}
	printf("%d\n", autos);
	return 0;
}
