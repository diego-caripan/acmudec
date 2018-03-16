#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n;
        int p;
        scanf("%d",&n);
        scanf("%d",&p);
        vector<int> bars;
        int buffer;
        int i,j,k,m,x,y;
        for(i=0;i<p;i++){
            scanf("%d",&buffer);
            bars.push_back(buffer);
        }
        vector<int> sumas;
        sumas.push_back(0);


        for(i=0;i<bars.size();i++){

            vector<int> temp = sumas;

            for(j=0;j<temp.size();j++){
            	temp[j] += bars[i];
            }

            for(j=0;j<temp.size();j++){
                sumas.push_back(temp[j]);
            }
        }

        for(i=0;i<sumas.size();i++){
            if(sumas[i]==n){
                printf("YES\n");
                break;
            }
            else if(i==sumas.size()-1 && sumas[i]!=n){
                printf("NO\n");
            }
        }
        
        t--;
    }

}

