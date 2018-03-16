#include <stdio.h>
#include <string.h>
#include <limits.h>

int N=0;

int kadane(int* arr, int* start, int* finish, int n){
    int sum = 0, maxSum = INT_MIN, i;
    *finish = -1;
    int local_start = 0;
    for (i = 0; i < n; ++i){
        sum += arr[i];
        if (sum < 0){
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum){
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
    if (*finish != -1)
        return maxSum;
    maxSum = arr[0];
    *start = *finish = 0;
 
    for (i = 1; i < n; i++){
        if (arr[i] > maxSum){
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}
int findMaxSum(int M[][N]){
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
    int left, right, i;
    int temp[N], sum, start, finish;
    for (left = 0; left < N; ++left){
        memset(temp, 0, sizeof(temp));
        for (right = left; right < N; ++right){
            for (i = 0; i < N; ++i)
                temp[i] += M[i][right];
            sum = kadane(temp, &start, &finish, N);
            if (sum > maxSum){
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
    return maxSum;
}

int main(){
    scanf("%d",&N);
    int M[N][N];
    int i,j;
    for(i=0; i<N ; i++){
        for(j=0; j<N; j++){
            scanf("%d",&M[i][j]);
        }
    }
    printf("%d\n",findMaxSum(M));
 
    return 0;
}
