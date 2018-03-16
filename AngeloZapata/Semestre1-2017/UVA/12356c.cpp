/*https://github.com/dseco/acmudec/blob/master/JuanFecci/Semestre1-2017/Uva-12356.cpp*/
#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){

	int B, S, L, R, auxL, auxR, lim;
	vector<int> soldadosL, soldadosR;

	scanf("%d %d",&S, &B); //lee numero de soldados en la linea de ataque y el numero de bajas.

	while (B!=0 && S!=0){

		REP(i,0,S){
			soldadosL.push_back(i-1);		//son 2 vectores para cada soldado de la 
			soldadosR.push_back(i+1);		//derecha y la izquierda estan vivos. (numero total)
		}
		lim = S;

		REP(i,0,B){

			scanf("%d %d",&L, &R); // lee los soldados que mataron.
			L--; R--;
			auxL=soldadosL[L];
			auxR=soldadosR[R];

			if (auxL==-1)cout << "* ";	//ve si los soldados de la izq muerieron.
			else{
				cout << auxL+1 << " ";		//cuenta cuantos soldados de la izq estan.
				soldadosR[auxL] = auxR;
			} 

			if (auxR==S)cout<< "*\n";	//ve si los soldados de la derecha muerieron.
			else{
				cout << auxR+1 << "\n";	//cuenta cuantos soldados de la derecha estan.
				soldadosL[auxR] = auxL;
			} 

		}

		D("-");
		soldadosL.clear();
		soldadosR.clear();

		scanf("%d %d",&S, &B);
	}	

}
