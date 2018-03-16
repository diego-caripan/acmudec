/*************************************************************************************************************************
 * UVa 10656 - Maximum Sum II
 * http://uva.onlinejudge.org/external/106/10656.html
 *
 * Classification: No algorithm required
 *
 * Author: Javier González N.
 *
 * Date: 15-08-2014
 *
 * Description:
 * Maximum sum of an array of only non-negative numbers is always the whole array.
 * But shortest maximum sum array is the subsequence of only non-zero numbers.
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    while(cin >> n && n != 0)
    {
        vector<int> v;
        while(n--)
        {
            int tmp;
            cin >> tmp;
            if(tmp > 0)
                v.push_back(tmp);
        }

        bool bSpace = false;
        for(int i = 0; i < v.size(); i++)
        {
            if(bSpace)
                cout << " ";
            bSpace = true;
            cout << v[i];
        }

        if(v.size() == 0)
            cout << "0";

        cout << endl;
    }


    return 0;
}
