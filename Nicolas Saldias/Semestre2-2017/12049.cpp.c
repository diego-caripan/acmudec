#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

int main(){
    int casos, l1, l2, val;
    scanf("%d", &casos);  //primero se lee el numero de casos

    while(casos--)  {
        map<int, int> mySet1, mySet2;
        set<int> enums;
        scanf("%d %d", &l1, &l2); // se lee la cantidad de elementos de cada lista
        for(int i=0; i<l1; i++){  //se lee y guardan los numeros de la primera lista
            scanf("%d", &val);
            mySet1[val]++;
            enums.insert(val);//inserta el elemento actual en el conjunto
        }
        for(int i=0; i<l2; i++){ // se lee y guardan los numeros de la segunda lista
            scanf("%d", &val);
            mySet2[val]++;
            enums.insert(val);//inserta el elemento actual en el conjunto
        }

        int ans = 0, tmp;
        for(set<int>::iterator it=enums.begin(); it!=enums.end(); it++){ //Recorre el conjunto y calcula la diferencia entre map1 y map 2 con el elemento set actual.
            tmp =  abs(mySet1[*it] - mySet2[*it]);
            ans += tmp;
        }
    printf("%d\n", ans);//imprime la respuesta
    }
return 0;
}