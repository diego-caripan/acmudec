/*************************************************************************************************************************
 * Uva 12526 - 
 *
 * Classification: 
 *
 * Author: Jury
 *
 * Date: 26-09-2014
 *
 * Descripcion:
 *  se usa un Trie, se tienen nodos y cada nodo tiene un arreglo con el
 *  diccionario a utilizar, 
 *  nota: hice new pero nunca delete, igual me dio accepted.
 * 
**/
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <list>

int ctoi( char a ){ return a - 'a'; }

typedef struct node{
  node * D[26];
  bool end;
  node()
  {
      end = false;
      for( int i = 0; i < 26; i++)
          D[i] = NULL;
  }
} Node;

double SUM;

void dfs( Node * node, int count, bool first)
{
    int childs = 0;
    int add = 0;
    // contar cuantos hijos tiene
    for( int i = 0; i < 26; i++ ) if( node->D[i] != NULL ) childs++;
    if( node->end ) childs++;
    if( childs > 1 ){
         add = 1;
    }else if ( first ) add++; // no habia leido que siempre se cuenta el primer keystroke


    // seguir viajando a cada hijo
    for( int i = 0; i < 26; i++ )
      if( node->D[i] != NULL ){
 //         std::cout << (char)(i+'a') << " ";
          dfs( node->D[i], count+add, false );
      }
    // si es terminal, añadir a la suma
    if( node->end ){
        SUM += count;
   //     std::cout << count;
    }
   // std::cout << std::endl;
}

int main()
{
    int N;
    while( scanf("%d", &N) != EOF )
    {
        SUM = 0;
        std::list< Node*> Tray;
        Node * root = new Node();
        Tray.push_front( root );
    
        // para cada string
        for( int i = 0; i < N; ++i )
        {
            std::string str;
            std::cin >> str;
            Node * tmp = root;
            for( std::string::iterator it = str.begin(); it != str.end(); ++it ) // para cada caracter del string
            {
                if( tmp->D[ ctoi(*it) ] == NULL ) // se debe crear un nuevo nodo
                {
                    Node * newNode = new Node();
                    tmp->D[ ctoi(*it) ] = newNode;
                }
                tmp = tmp->D[ ctoi(*it) ];
            }
            // al terminar, se añade el "fin"
            tmp->end = true;
        }

        dfs( root, 0, true );
        delet( root );
        printf("%.2f\n", SUM/(double)N);
    }
    return 0;
}
