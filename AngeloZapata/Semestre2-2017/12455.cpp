#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, p, l;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> p;
        bool dp[3000] = {};
        dp[0] = true;
        for(int j = 0; j < p; j++) {
            cin >> l;
            for(int k = n-l; k >= 0; k--) {
                if(dp[k] && !dp[k+l])
                    dp[k+l] = true;
            }
        }
        if(dp[n])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}