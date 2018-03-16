#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*  Código sacado de internet. Única diferencia es que maneja strings.
    Todo lo demás fue entendido como se refleja en mi código original.
*/

int main()
{
    int cases, len;
    char s[2000];

    while(scanf("%d", &cases)==1){
     while(cases--){
        scanf("%s", s);
        len=strlen(s);
        if(strcmp(s, "1")==0 || strcmp(s, "4")==0 || strcmp(s, "78")==0)
            printf("+\n");
        else if(s[len-1]=='5' && s[len-2]=='3')
            printf("-\n");
        else if(s[0]=='9' && s[len-1]=='4')
            printf("*\n");
        else
            printf("?\n");
        }
    }
    return 0;
}