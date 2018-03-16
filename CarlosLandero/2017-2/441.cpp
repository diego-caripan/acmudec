#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int n, buffer[13], selected[6];

int main(){
    int first = 1, i;
    int a,b,c,d,e,f;
    int flag=0;
    while(scanf("%d", &n) == 1 && n) {
        if(flag!=0){
            printf("\n");
        }
        for(i = 0; i < n; i++){
            scanf("%d", &buffer[i]);
        }
        vector<int> numeros(buffer,buffer+n);
        sort(numeros.begin(),numeros.end());
        vector<int> aux;
        for(a=0;a<n;a++){
            for(b=0;b<n;b++){
                if(b==a){
                  continue;
                }
                for(c=0;c<n;c++){
                    if(c==b || c==a){
                        continue;
                    }
                    for(d=0;d<n;d++){
                        if(d==c || d==b || d==a){
                            continue;
                        }
                        for(e=0;e<n;e++){
                            if(e==d || e==c || e==b || e==a){
                                continue;
                            }
                            for(f=0;f<n;f++){
                                if(f==e || f==d || f==c || f==b || f==a){
                                    continue;
                                }
                                else if(a<b && b<c && c<d && d<e && e<f){
                                    printf("%d %d %d %d %d %d\n",numeros[a],numeros[b],numeros[c],numeros[d],numeros[e],numeros[f]);
                                    aux.clear();
                                }
                            }
                        }
                    }
                }
            }
        }
        flag++;
    }
    return 0;
}
