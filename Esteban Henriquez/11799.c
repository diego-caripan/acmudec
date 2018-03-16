#include <stdio.h>
int main()
{
    int T,caso;
    while (scanf("%d",&T)==1)
    {
        caso=0;
        while (T--)
        {
            long int c,N,i,max=0;
            scanf("%ld",&N);
            for (i=0;i<N;i++)
            {
                scanf("%ld",&c);
                if (c>max)
                    max=c;
            }
            caso++;
            printf("Case %d: %ld\n",caso,max);
        }
    }
    return 0;
}