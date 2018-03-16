#include <cstdio>
using namespace std;

int main(){
    int r,s;
    int stops[30000];
    int test_case=1;
    int max=0;
    int i=1;
    int j=1;
    int k=1;
    int sum=0;
    scanf("%d",&r);
    while(r--){
        scanf("%d",&s);
        int x=1;
        while(x<=s-1){
            scanf("%d",&stops[x]);
            x++;
        }
        max=0;
        i=1;
        j=1;
        k=1;
        sum=0;
        for(int it=1;it<s;it++){
            sum += stops[it];
            if(sum < 0){
                sum = 0;
                k = it+1;

            }
            else if(sum >= max){
                if(sum > max || (sum == max && (it - k > j - i))){
                    i = k;
                    j = it+1;
                }
                max = sum;
            }
        }
        if(max > 0){
            printf("The nicest part of route %d is between stops %d and %d\n",test_case,i,j);
        }
        else{
            printf("Route %d has no nice parts\n",test_case);
        } 
        test_case++;
    }
    return 0;
}
