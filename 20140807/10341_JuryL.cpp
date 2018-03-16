/*************************************************************************************************************************
 * Uva 10341 - Solve It
 * http://uva.onlinejudge.org/external/103/10341.html
 *
 * Classification: Busqueda Binaria
 *
 * Author: Jury
 *
 * Date: 11-08-2014
 *
 * Descripcion:
 * Se utiliza busqueda binaria para buscar X.
 */

#include <stdio.h>
#include <math.h>

#define EPS 0.0000001

int p,q,r,s,t,u;

double f( double x )
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x +u;
}

double binary_search()
{
    double lo = 0, hi = 1;

    double mid = lo+(hi-lo)/2;

  //   while( fabs(f(mid)) > EPS ) esta condicion no sirve :(!
    for( int i = 0; i < 100; ++i )
    {
      mid = lo + (hi-lo)/2;
      if( f(mid) <= 0 )
          hi = mid;
      else
          lo = mid;
    }
    return lo;
}

int main()
{
  while( scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u ) > 0 )
  {
    if( f(0) * f(1) > 0 ) printf("No solution\n");
    else if( f(0) == 0 )  printf("%.4lf\n", 0.0);
    else if( f(1) == 0 )  printf("%.4lf\n", 1.0);
    else                  printf("%.4lf\n", binary_search() );
  }
  return 0;
}
