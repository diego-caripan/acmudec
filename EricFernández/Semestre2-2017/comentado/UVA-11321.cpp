#include <vector>
#include <iostream>
#include <algorithm>
/*
El problema consiste en ordenar una lista de numeros
pero de una forma especial

*/
using namespace std;
int M;

/*
Una variancon de sort exclusiva para el problema
*/
bool SortFunc(int i, int j)
{
    if (i % M != j % M)
        return i % M < j % M;
    if (i & 1) // i is odd
    {
        if (j & 1)
            return i > j;
        return true;
    }
    if (j & 1)
    {
        return false;
    }
    return i < j;
}

int main()
{
    int N;
    //un vectro bien grandecito
    vector<int> numbers(10005);
    
    while (cin >> N >> M, cout << N << ' ' << M << '\n', N)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> numbers[i];
        }
        /*
        Aqu usa el sort pero con el parametro mas que es la funcion de como ordenara
        segun lo propuesto en el enunciado
        */
        sort(numbers.begin(), numbers.begin() + N, SortFunc);
        ;
        for (int i = 0; i < N; ++i)
            cout << numbers[i] << '\n';
    }
}