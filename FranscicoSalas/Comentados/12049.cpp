// Comentario 12049

#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
int main()
{
int casos, l1, l2, val;
// Escanea el número de casos
scanf("%d", &casos);

// Por cada caso
while(casos--)
{
// Define un mapa de <int,int> para cada lista
    map<int, int> mySet1, mySet2;
    set<int> enums;
// Lee los largos de las listas
    scanf("%d %d", &l1, &l2);
// Lee los items de la lista 1, guarda un registro de el total de apariciones por número en un mapa STL (mySet1) e ingresa el item en el STL set.
    for(int i=0; i<l1; i++)
    {
        scanf("%d", &val);
        mySet1[val]++;
        enums.insert(val);
    }
// Lee los items de la lista 2, guarda un registro del total de apariciones por número en un mapa STL (mySet2) e ingresa el item en el STL set
    for(int i=0; i<l2; i++)
    {
        scanf("%d", &val);
        mySet2[val]++;
        enums.insert(val);
    }

// Recorre el set, y calcula la diferencia entre los mapas de la lista1 y lista2 con el objeto actual del set
    int ans = 0, tmp;
    for(set<int>::iterator it=enums.begin(); it!=enums.end(); it++)
    {
        tmp =  abs(mySet1[*it] - mySet2[*it]);
        ans += tmp;
    }
// Imprime el resultado
    printf("%d\n", ans);
}
return 0;
}