#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m) && n!=0 && m!=0){

        int dragons[n];
        int knights[m];
        for(int i=0;i<n;i++){
            scanf("%d",&dragons[i]);
        }
        for(int j=0;j<m;j++){
            scanf("%d",&knights[j]);
        }

        sort(dragons, dragons + n);
        sort(knights, knights + m);

        int sum = 0;
        int flag = 0;
        int j=0;

        if(n>m){
            printf("Loowater is doomed!\n");
        }
        else{
            for(int i=0;i<n && flag==0;i++){
                for(j;j<m;j++){
                    if(j < m && knights[j] < dragons[i]){
                        continue;
                    }
                    else{
                        break;
                    }
                }
                if(j==m){
                    flag = 1;
                }
                else{
                    sum += knights[j++];
                }
            }
            if(flag == 1){
                printf("Loowater is doomed!\n");
            }
            else{
                printf("%d\n",sum);
            }
        }
    }
    return 0;

}

