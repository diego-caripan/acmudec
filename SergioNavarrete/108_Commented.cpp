#include <cstdio>
#include <cstdlib>
#include <climits>

#define MAX(X, Y) (X > Y) ? X : Y
#define POS(X) MAX(X, 0)

#define N 101

// Este problema se soluciona mediante Kadane Algorithm (DP). Pero Kadane resuelve problemas en 1D
// Para reducir la 2D/matrix tenemos que:
// Usamos suma acumulativa. Es decir, agregamos el valor de cada fila a todas las siguientes conforme recibo el input
// Luego combinamos ambas filas y aplicamos Kadane.


int matrix[N][N], n, maxSum = INT_MIN;

int kadane(int* row, int len) {
    int x, sum;
    for (x = 0, sum = POS(row[0]); x < len; ++x, sum = POS(sum + row[x]))
        maxSum = MAX(sum, maxSum);
    return maxSum;
}

int kadane2(int* row1, int* row2, int len) {
    int x, sum;
    for (x = 0, sum = POS(row2[0] - row1[0]); x < len; ++x, sum = POS(sum + row2[x] - row1[x]))
        maxSum = MAX(sum, maxSum);
    return maxSum;
}

int main() {
    int x, y, y2;
    /*input*/
    scanf("%d", &n);
    for (x = 0; x < n; ++x)
        scanf("%d", &matrix[0][x]);
    for (y = 1; y < n; ++y) {
        for (x = 0; x < n; ++x) {
            scanf("%d", &matrix[y][x]);
            matrix[y][x] += matrix[y - 1][x];
        }
    }
    /*solve*/
    for (y = 0; y < n; ++y) {
        kadane(matrix[y], n);
        for (y2 = y + 1; y2 < n; ++y2)
            kadane2(matrix[y], matrix[y2], n);
    }
    /*result*/
    printf("%d\n", maxSum);
    return 0;
}
