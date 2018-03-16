#include <cstdio>
#include <algorithm>
int main() {
  /*
  COnsiste en que a todos los numeros ingresados se les reste un valor y la suma de todos esos valores sea el minimo
  debe imprimir el numero que cumpla con esto, el total de numeros que podrian cumplir y la cantidad posible dentro del input que lo cumpla
  */
  int x[1000005], n;
  //lee los numeros del input
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
    //los ordena con sort
    std::sort(x, x + n + 1);
    //define las variables y tamp elige el mayor tomando en cuanta si es par o impar.
    int a2 = 0, a3, tmp = ((double)n / 2 > n / 2 ? n / 2 + 1 : n / 2);
    for (int i = 1; i <= n; ++i) {
      if (x[i] == x[tmp]) ++a2;
      else if (n % 2 == 0 && x[i] == x[tmp + 1]) ++a2;
    }
    if (n % 2 == 0) a3 = x[tmp + 1] - x[tmp] + 1;
    else a3 = 1;
    //imprime
    printf("%d %d %d\n", (n / 2 == 0 ? x[1] : x[tmp]), a2, a3);
  }
  return 0;
}