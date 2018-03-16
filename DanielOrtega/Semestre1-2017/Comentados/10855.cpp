#include <iostream>
#include <cstring>
#define MAX 500
using namespace std;


//define las matrices
char big[MAX][MAX];
char small[MAX][MAX];


/*
Esta funcion define una nueva matriz con las mismas dimensasiones 
primero crea la nueva matriz
luego copia en la nueva matriz los elementos en sentido horario
para luego volver a copiarlas en la matriz original
*/
void rotateClockwise(char matrix[MAX][MAX], int size){
    char newMatrix[MAX][MAX];
    memset(newMatrix,0,sizeof(newMatrix));

    //(1)
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            newMatrix[i][j] = matrix[size-1-j][i];
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            matrix[i][j] = newMatrix[i][j];
        }
    }
    return;
}



/*
Esta funcion es la que va buscando los match dentro de la matriz

s corresponde a la matriz pequeña
l corresponde a la matriz grande
sizeS al tamaño de la matriz pequeña
sizeL al tamaño de la matriz grande
x corresponde al desfase en el eje i o filas
y corresponde al desfase en el eje j o columnas



*/
bool match(char s[MAX][MAX], char l[MAX][MAX], int sizeS, int sizeL, int x, int y){
    // este if sirve para comprobar que nos encontremos en un rango valido de comparacion para la matriz
    if((x+sizeS>sizeL)||(y+sizeS>sizeL)){
        return false;
    }
    bool valid = true;
// comprueba las combinaciones posibles, uno por uno
    for(int i=0;i<sizeS;i++){
        for(int j=0;j<sizeS;j++){
            if(s[i][j] != l[i+x][j+y]){
                valid = false;
            }
        }
    }
    return valid;
}


/*
Tal cual como el nombre de la funcion, imprime 
*/
void printMatrix(char matrix[MAX][MAX], int size){
    for (int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}



int main(){
    int n1, n2;

    //lee las dimensiones n1, corresponde a la grande y n2 a la pqueña
    while((cin >> n1 >> n2)&&(!((n1==0)&&(n2==0)))){
       
        //lee la matriz grande
        for (int i=0;i<n1;i++){
            for(int j=0;j<n1;j++){
                cin >> big[i][j];
            }
        }

        //lee la matriz chica
        for (int i=0;i<n2;i++){
            for(int j=0;j<n2;j++){
                cin >> small[i][j];
            }
        }

        
        /*
    z corresponde al numero de rotaciones que se puede hacer 0, 90,180,270
    count, es un contador de cuantas veces se produce un match de buscar la matriz mas pequeña en la matriz mas grande,
    luego de pasar por todas las iteraciones se entrega el resultado

        */
        for(int z=0;z<4;z++){
            int count = 0;
            // se iteracion de n1-n2 que son la cantidad de casos que se pueden comparar, como n1 es mayor a n2 el numero siempre sera positivo
            for (int i=0;i<=n1-n2;i++){
                for(int j=0;j<=n1-n2;j++){

                    if(match(small,big,n2,n1,i,j)){
                        count++;
                    }
                }
            }
            // para el primer caso
            if(z==0){
                cout << count;
            }
            // para los casos que viene despues del priemro
            else{
                cout << " " << count;
            }
            // se rota la matriz pequeña, mostrando su tamaño
            rotateClockwise(small,n2);
        }
        cout << endl;

    }
    return 0;
}