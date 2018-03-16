
#include <stdio.h>
#include <string.h>

int main()
{
    char arr[40][100],m,vec[100];
    int a,b,i,n=0,ts,j;
    scanf("%d",&a);
    scanf("%c",&m);
    for(b=0; n<a*2; b++)
    {
        gets(arr[b]);
        n++;
    }
    scanf("%d",&ts);
    for(i=0; i<=ts; i++)      
    {
        gets(vec);
        for(j=0; j<b; j+=2)
        {
            if(strcmp(vec,arr[j])==0)
            {
                puts(arr[j+1]);
                break;
            }
        }
    }
    return 0;
}