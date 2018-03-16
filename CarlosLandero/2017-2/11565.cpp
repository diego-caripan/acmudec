#include <cstdio>
using namespace std;

int main() {
	int n, A, B, C;
	scanf("%d", &n);
	while(n>0){
        scanf("%d %d %d", &A, &B, &C);
		int sol = 0;
		int x, y, z;
		for (x = -22; x <= 22 && sol==0; x++){
            if (x * x <= C){
                for (y = -58; y <= 58 && sol==0; y++){
                    if (y != x && x * x + y * y <= C){
                        for (z = -100; z <= 100 && !sol; z++){
                            if (z != x && z != y && x + y + z == A && x * y * z == B && x * x + y * y + z * z == C) {
								printf("%d %d %d\n", x, y, z);
								sol = true;
							}
                        }
                    }
                }
			}
		}
		if (sol==0){
            printf("No solution.\n");
		}
        n=n-1;
	}

	return 0;
}
