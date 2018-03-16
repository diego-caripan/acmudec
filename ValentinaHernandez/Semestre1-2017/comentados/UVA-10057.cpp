/* https://github.com/morris821028/UVa/blob/master/volume100/10057%20-%20A%20mid-summer%20night%27s%20dream.cpp */

#include <stdio.h>
#include <stdlib.h>


int cmp(const void *i, const void *j) {
	return *(int *)i - *(int *)j;
	//diferencia entre los numeros
}
int findIdx(int idx, int A[]) {
	int i, sum = 0;
	for(i = 0; ; i++) {
		sum += A[i];
		if(sum >= idx)
			return i;
	}
	//busca la suma de los numeros
}
int ReadInt(int *x) {
    static char c, neg;
    while((c = getchar()) < '-')    {if(c == EOF) return EOF;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = getchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

/*lee los numeros, mientras sean distintos de eof, para lo cual se usa readint,
si los numeros son impares, se busca la media con n/2 +1, si no solo con n/2, se 
busca la siguiente para compararlo. 
Esto hace que la suma de las distancias sea minima, así se busca todos los que 
safisfagan el problema,.*/
int main() {
	int n, i, x;
	while(scanf("%d", &n) == 1) {
		int A[65537] = {};
		for(i = 0; i < n; i++) {
			ReadInt(&x);
			A[x]++;
		}
		int mid, midn, midp, next;
		if(n&1) {
			mid = findIdx(n/2+1, A);
			midn = A[mid];
			midp = 1;
		} else {
			mid = findIdx(n/2, A);
			midn = A[mid];
			next = findIdx(n/2+1, A);
			if(next != mid) {
				midn += A[next];
				midp = next - mid+1;
			} else {
				midp = 1;
			}
		}
		printf("%d %d %d\n", mid, midn, midp);
	}
    return 0;
}