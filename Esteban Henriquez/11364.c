#include <stdio.h>

int main()
{
    int caso;
    scanf("%d", &caso);
    while (caso--)
    {
        int n, i, min = 100, max = 0, num;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &num);
            if (num > max)
                max = num;
            if (num < min)
                min = num;
        }
        printf("%d\n", (max - min) * 2);
    }
    return 0;
}