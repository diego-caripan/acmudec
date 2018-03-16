#include <cstdio>

using namespace std;

int main() {

	int casos;

	scanf("%d", &casos);

	while (casos--) {
			int frecuencia, amplitud;

		scanf("%d", &amplitud);
		getchar();
		scanf("%d", &frecuencia);



		for (int i = 0; i < frecuencia; i++) {
			for (int j = 1; j <= amplitud; j++) {

				for (int w = 0; w < j; w++) {
					printf("%d", j);
				}
				printf("\n");
			}
			for (int j = amplitud - 1; j >= 1; j--) {
				for (int w = 0; w < j; w++) {
					printf("%d", j);
				}
				printf("\n");
			}
			if (i != frecuencia - 1)
				printf("\n");
		}
		if (casos != 0)
			printf("\n");
	}

	return 0;
}