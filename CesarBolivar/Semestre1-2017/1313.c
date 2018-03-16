// César Bolívar Severino
// resuelto propio
#include <stdio.h>
// apostaria a que esta wea no necesita tantos ciclos...
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int pixeles[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &pixeles[i][j]);
		}
	}
	for (int k = 0; k < n; k++)
	{
		int i = k;
		int j = 0;
		while (i >= 0 && j < n) {
			printf("%d ", pixeles[i][j]);
			i--;
			j++;
		}
	}
	for (int k = 1; k < n; k++)
	{
		int i = n - 1;
		int j = k;
		while (i >= 0 && j < n) {
			printf("%d ", pixeles[i][j]);
			i--;
			j++;
		}
	}
	return 0;
}
