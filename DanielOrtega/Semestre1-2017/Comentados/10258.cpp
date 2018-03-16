#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>



/*
El problema consiste en rankear a lso participantes usando el siguiente criterio

Por la cantidad de de numero de problemas resueltos
decreciendo por el numero de penalidades
si para un los concusante los 2 parametros anteriores son iguales, se muestran en orden creciente por el numero de equipo


*/


/*

*/

/*
estructura usada para almacenar el input
contestant: id del concursante
nproblem: nro de problemas resueltos por el concursante
problem[1..9]: numero de problemas resueltos por el concusante
penalty[1..9]: tiempo penalizado por el concursante, por x problema
time: tiempo total de penalizacion del concursante por la competencia entera

*/

struct board {

  int contestant;
  int nproblem;
  int problem[10];
  int penalty[10];
  int time;
  board(int c): contestant(c), nproblem(0){
    time = 0;
    for ( int i = 0; i < 10; ++i )   {
          problem[i] = 0;
          penalty[i] = 0;
      }
  }


  //funcion que calcula el tiempo de penalizacion

  void calc_time()   {
    for ( int i = 1; i < 10; ++i ) {
          if ( problem[i] == 1 )
          time += penalty[i];
      }
  }
};

/*
Esta funcion se encarga de calcular 
si el problema es 1, no se penaliza
si el problema tiene un identificador c es correcto, y se suma en penalty, el tiempo que se demora en resolver
si el problema tiene un identificador i es incorrecto, se suma 20 minutos en tiempo de penalizacion mas el tiempo que se demora en resovler
*/
void judge(board &b, const int &problem, const int &time, const char &L) {
  if (b.problem[problem] == 1)     {
      return;
    }

  if ( L == 'C' )     {
      ++b.nproblem;
      b.problem[problem] = 1;
      b.penalty[problem] += time;
    }

  else if ( L == 'I' )     {
      b.penalty[problem] += 20;
    }
}

// iniciliza el array indice con solo -1 
inline void init(int index[]){
  for ( int i = 0; i < 101; ++i )
    index[i] = -1;
}

// modifica el operador <, para ir comparando por los elementos dentro de la estructura board
bool operator<(const board &b1, const board &b2)
{
  if ( b1.nproblem > b2.nproblem )
    return true;
  if ( b1.nproblem == b2.nproblem && b1.time < b2.time )
    return true;
  if ( b1.nproblem == b2.nproblem && b1.time == b2.time
       && b1.contestant < b2.contestant )
    return true;
  return false;
}

/*
El problema es resuelto de la siguiente manera

se analizan todos los casos de pruebas
se analiza cada envio de un problema
si un nuevo concursantre envia una solucion a un problema, este concursante queda "registrado" hasta el final de la competencia,
juzgar la solucion del problema.
si la solucion al problema no es correcta, se sigue evaluando hasta que sea correcta
  por cada problema se analiza cada sumision hecha, donde se calcula o no el tiempo de penalizacion

al final se imprime el id del concursante, con la cantidad de problema resuletos, y el tiempo de penalizacion total.

la salida, se muestran en orden creciente por id del concursante


*/




    calculate the penalty time for solved problems for every contestant
    print it

int main()
{
  int T;
  std::string s;
  int contestant, problem, time;
  char L;

  std::cin >> T;
  getline(std::cin, s);
  getline(std::cin, s);
  for ( int t = 1; t <= T; ++t )  {
      int index[101];
      std::fill(index, index + 101, -1);
      std::vector<board> v;

      while( getline(std::cin, s) )
    {
      if ( s == "" ) break;

      std::istringstream iss(s);
      iss >> contestant >> problem >> time >> L;

      if ( index[contestant] == -1 )
        {
          v.push_back(*new board(contestant));
          index[contestant] = (int)v.size() - 1;
        }
      judge(v[index[contestant]], problem, time, L);
    }


      for ( std::vector<board>::iterator it = v.begin(); it != v.end(); ++it )
          it->calc_time();

      sort(v.begin(), v.end());
      for ( std::vector<board>::iterator it = v.begin(); it != v.end(); ++it )
          std::cout << it->contestant << ' ' << it->nproblem << ' ' << it->time << std::endl;
      if ( t < T )
          std::cout << std::endl;
    }
  return 0;
}