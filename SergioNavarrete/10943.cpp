#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 101

using namespace std;

int number,k_numbers;
long long int memo[MAX][MAX];


long long int dp(int n, int k_num) {
    if (k_num <= 1) return 1;
    else if (memo[n][k_num] != -1)  return memo[n][k_num];

    memo[n][k_num] = 0;
    for (int i = 0; i <= n; i++){
        memo[n][k_num] = (memo[n][k_num] + dp(i, k_num - 1)) % 1000000;
        printf("n=%d k=%d memo=%lld\n",n,k_num,memo[n][k_num]);
    }
    return memo[n][k_num];
}

int main() {
    memset(memo, -1, sizeof(memo));
    while(1){
        scanf("%d",&number);
        scanf("%d",&k_numbers);
        if (number == 0 && k_numbers == 0) break;
        printf("%lld\n", dp(number,k_numbers));
    }
    return 0;
}
