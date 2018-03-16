// César Bolívar Severino
// resuelto propio
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int l1, l2;
	scanf("%d", &l1);
	scanf("%d", &l2);
	if (l1 % 2 == 0 || l2 % 2 == 1) {
		puts("yes");
	}
	else {
		puts("no");
	}
	return 0;
}
