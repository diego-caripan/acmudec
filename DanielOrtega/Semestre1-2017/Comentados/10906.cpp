#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;

/*
El problema consiste en que entregada una secuencia de operaciones, con literales separados, se debe poder entregar una ecuacion
que este en una sola linea, en el fondo corresponde a reemplazar las variables en un expresion simple

*/

/*
A corresponde al primer numero/variables antes del operando 
B es el operando
C corresponde al primer numero/variables despues del operando
*/
struct E {
    string A, B, C; // A (C) B
};


map<string, E> R;

/*
la funcion dfs, genera un recorrido en preorder para poder recorrer el arbol,
funcion recibe la variable para encontrar el string, ya que estos sestan almacenads en un map y se busca por el nombre de la variable


esta funcion corresponde a hacer un recorrido en preorder en el grafo
*/

string dfs(string val) {

    E &v = R[val];

    //ret es el string donde se ira generando la expresion y es el valor que se retonar
    //right variable auxiliar que almacena el valor de la derecha
    //left variable auxiliar que almacena el valor de la izquierda
    string ret = "", right, left;

    	/* revisa el valor de s2, si corresponde a una variable o a un numero
			si es un numero este que almacenado en left
			si es una variable este vuelve a llamar a dfs, pero con la variable encontrada a la izquierda	

	*/
    if(v.A[0] >= '0' && v.A[0] <= '9')
        left = v.A;
    else
        left = dfs(v.A);
    /* revisa el valor de s4, si corresponde a una variable o a un numero
			si es un numero este que almacenado en left
			si es una variable este vuelve a llamar a dfs, pero con la variable encontrada a la derecha	

	*/

    if(v.B[0] >= '0' && v.B[0] <= '9')
        right = v.B;
    else
        right = dfs(v.B);

// esta aparte revisa el valro de s3
/*
donde si s3 es un +, se ira almacenando de la forma ( left + derecho),
donde derecho puede ser un numero, o puede ser una variable, que ya fue pasado por la funcion dfs

*/
    if(v.C == "+") {
        ret = left + "+";
        if(v.B[0] >= '0' && v.B[0] <= '9')
            ret = ret + right;
        else
            ret = ret + "(" + right + ")";
    } 
/*
en el caso del signo *

significa que deben existir mas varibales, por lo que se busca el + de tal manera que el mas sea el unico en la operacion


*/
    else { // v.C == "*"

        int i, flag = 0, l = 0, flag2 = 0;
        for(i = 0; i < left.length() && !flag; i++) {
            if(left[i] == '(')  l++;
            if(left[i] == ')')  l--;
            if(l == 0 && left[i] == '+')
                flag = 1;
        }
    
/*
asi si se pilla el mas unico se concatena y se pone entre parentesis.
en el casos de qe no se encuentre se coloca el * ya que este indica que la operacion anterior estaba lista
*/
        if(flag)
            ret = "(" + left + ")*";
        else
            ret = left + "*";
        i, l = 0;
  

//significa que deben existir mas varibales, por lo que se busca el + de tal manera que el mas sea el unico en la operacion

        for(i = 0; i < right.length() && !flag; i++) {
            if(right[i] == '(')  l++;
            if(right[i] == ')')  l--;
            if(l == 0 && right[i] == '+')
                flag2 = 1;
        }
        if(flag == 0 && flag2 == 0)
            ret = ret + "(" + right + ")";
        else
            ret = ret + right;
    }
    return ret;
}


int main() {

    int testcase, cases = 0;
    int n, i;
	// casos de prueba    
    scanf("%d", &testcase);
    
    while(testcase--) {
    	// lee la cantidad de varibales a entregar
        scanf("%d", &n);
        // limpia el map
        R.clear();
        char s1[50], s2[50], s3[50], s4[50];
        E tmp;
        // se encarga de hacer la lectura correspondiente, por el formato entregado en el input
        /*
        s1 Corresponde a la variable antes de =, osea al nombre de la variable
        s2 corresponde al primer numero/variables antes del operando 
        s3 es el operando
        s4 corresponde al primer numero/variables despues del operando
        R[s1] almacena el "string", que es el concantecion de s2.s3.s4 asociado a s1
        */
        for(i = 0; i < n; i++) {
            scanf("%s = %s %s %s", s1, s2, s3, s4);
            tmp.A = s2, tmp.B = s4;
            tmp.C = s3;
            R[s1] = tmp;
        }
        printf("Expression #%d: ", ++cases);
        // llama a la funcion que resuelve el problema
        cout << dfs(s1);
        puts("");
    }
    return 0;
}