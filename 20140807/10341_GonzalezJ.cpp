/*************************************************************************************************************************
 * UVa 10341 - Solve It
 * http://uva.onlinejudge.org/external/103/10341.html
 *
 * Classification: Binary Search
 *
 * Author: Javier González N.
 *
 * Date: 11-08-2014
 *
 * Description:
 * La función que propone el problema devuelve un conjunto ordenado de resultados (usando x entre 0 y 1)
 * asi que se puede hacer busqueda binaria para encontrar el x que hace cero la función.
 *
 * The function returns an ordered set of values using x between 0 and 1. We can do binary search
 * on the results to find x such as the function returns 0.
 */

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int p, q, r, s, u, t;

double solve(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main()
{
    while(cin >> p >> q >> r >> s >> t >> u)
    {
        double minV = 0.0f;
        double maxV = 1.0f;

        bool bFound = false;

        for(int i = 0; i < 100; i++)
        {
            double midV = (minV + maxV) * 0.5f;
            double currResult = solve(midV);

            if(currResult < 1e-9 && currResult > -1e-9)
            {
                bFound = true;
                printf("%.4f\n", midV);
                break;
            }
            else if(currResult > 1e-9)
            {
                minV = midV;
            }
            else
            {
                maxV = midV;
            }
        }

        if(!bFound)
            cout << "No solution" << endl;
    }

    return 0;
}
