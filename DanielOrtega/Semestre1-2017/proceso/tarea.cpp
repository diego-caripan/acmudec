#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <sys/time.h>

using namespace std;


int lcs(string X,string Y, int m, int n ) {

  int L[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {

    for (int j = 0; j <= n; j++) {

      if (i == 0 || j == 0)
        L[i][j] = 0;

      else if (X[i - 1] == Y[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;

      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }
  return L[m][n];
}


int main() {

  string X,Y;
  int n, m;

  struct timeval start, end;
  gettimeofday(&start, NULL);

  while ( !cin.eof()) {
  	cin >> X;
	  cin >> Y;

    m = X.length() ;
    n = Y.length() ;
    printf("LCS %d\n", lcs( X, Y, m, n ) );

  }

  gettimeofday(&end, NULL);
  double elapsed = ((end.tv_sec - start.tv_sec) * 1000)
                   + (end.tv_usec / 1000 - start.tv_usec / 1000);

  cout << "\n" << "Tiempo total demorado: " << elapsed << "\n\n";
  //son segundos


  return 0;
}