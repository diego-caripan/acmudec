/* https://github.com/morris821028/UVa/blob/master/volume001/118%20-%20Mutant%20Flatworld%20Explorers.c */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, sx, sy;
    char D[2], cmd[1000], pre[100][100] = {};
    scanf("%d %d", &n, &m);
    while(scanf("%d %d %s", &sx, &sy, D) == 3) {
        scanf("%s", cmd);
        int d = D[0], flag = 0, i;
        for(i = 0; cmd[i]; i++) {
            /*Ve el caso en que el char sea F, si lo es, 
            se fija en que posición está para ver con que 
            coordenada avanzar*/
            if(cmd[i] == 'F') {
                switch(d) {
                    case 'N':sy++;break;
                    case 'E':sx++;break;
                    case 'W':sx--;break;
                    case 'S':sy--;break;
                }
            } else if(cmd[i] == 'R') {
                /*Similar a F, pero con R, en donde va a girar con 
                X coordenada, dependiendo de a donde mire actualmente*/
                switch(d) {
                    case 'N':d = 'E';break;
                    case 'E':d = 'S';break;
                    case 'W':d = 'N';break;
                    case 'S':d = 'W';break;
                }
            } else {
                /*Lo mismo que antes, solo que ahora gira hacia la izquierda*/
                switch(d) {
                    case 'N':d = 'W';break;
                    case 'E':d = 'N';break;
                    case 'W':d = 'S';break;
                    case 'S':d = 'E';break;
                }
            }
            //Ve si el robot no se ha caido
            if(sx < 0 || sy < 0 || sx > n || sy > m) {
                switch(d) {
                    case 'N':sy--;break;
                    case 'E':sx--;break;
                    case 'W':sx++;break;
                    case 'S':sy++;break;
                }
                if(pre[sx][sy] == 1)
                    continue;
                flag = 1;
                pre[sx][sy] = 1;
                break;
                //si se cae, el flag es 1 -> true
                //en el otro caso, se imprime el LOST
            }
        }
        if(!flag)
            printf("%d %d %c\n", sx, sy, d);
        else {
            printf("%d %d %c LOST\n", sx, sy, d);
        }
    }
    return 0;
}