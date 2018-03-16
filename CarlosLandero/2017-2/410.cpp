#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int c;
    int s;
    double avg;
    double imbalance;
    int set = 0;
    vector<int> especimen;

    while(scanf("%d %d",&c,&s)!=EOF){
        avg = 0.0;
        imbalance = 0.0;
        for(int i=0;i<2*c;++i){
            especimen.push_back(0);
        }
        for(int i=0;i<s;i++){
            int aux;
            scanf("%d",&aux);
            especimen[i]=aux;
            avg += aux;
        }
        avg = avg/c;
        
        sort(especimen.begin(),especimen.end());

        printf("Set #%d\n", ++set);
        for (int i = 0; i < c; ++i) {
            printf(" %d:", i);
            int o = 2*c-i-1;
            if (especimen[i] != 0) printf(" %d", especimen[i]);
            imbalance += abs(especimen[o]+especimen[i]-avg);
            if (especimen[o] != 0) printf(" %d", especimen[o]);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);
        especimen.clear();
    }
    return 0;
}
