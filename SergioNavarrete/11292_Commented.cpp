#include <iostream>
#include <algorithm>

using namespace std;

// Lo realize hace años, de hecho tengo el registro en mi cuenta de UvA pero no me di el tiempo de hacerlo de nuevo
// La idea es sencilla, simplemente ordenar tanto las cabezas de dragon como los caballeros
// Y comenzar con el caballero mas pequeño y la cabeza mas pequeña y asi... 

int heads[20005], knights[20005];

int main()
{
    int n, m;

    while (cin >> n >> m, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> heads[i];

        sort(heads, heads + n);

        for (int i = 0; i < m; ++i)
            cin >> knights[i];

        sort(knights, knights + m);

        if (m < n)
        {
            cout << "Loowater is doomed!\n";
            continue;
        }

        int head = 0, knight = -1;
        int cost = 0;
        for (; head < n; ++head)
        {
            // Need to increase the knight
            ++knight;

            while (knight < m && knights[knight] < heads[head])
                ++knight;

            // No match was found
            if (knight == m)
                break;

            cost += knights[knight];
        }

        if (head != n)
            cout << "Loowater is doomed!\n";
        else
            cout << cost << '\n';
    }
}
