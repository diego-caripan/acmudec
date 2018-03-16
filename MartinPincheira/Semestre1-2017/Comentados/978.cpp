#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef multiset<int, greater<int> >::iterator it_type;

int main(){

	int N,B,SG,SB;
	int i,temp;
	int actualB;
	multiset<int, greater<int> > SG_army;
	multiset<int, greater<int> > SB_army;
	it_type my_iterator;
	vector<int> fightersSG;
	vector<int> fightersSB;
	bool flag_first = false;

	cin>>N;
	
	while(N--){

		if(flag_first){
			cout<<endl;
		}
		//Lectura de valores y almacenamiento en SG_army y SB_army respectivamente, los cuales guardaran los
		//valores de poder de cada soldado.
		cin>>B>>SG>>SB;

		for(i=0; i<SG; i++){

			cin>>temp;
			SG_army.insert(temp);
		}

		for(i=0; i<SB; i++){

			cin>>temp;
			SB_army.insert(temp);
		}

		//Mientras ninguno de ambos equipos sea vacio, se calcula el numero de campos de batallas a ser
		//usados y luego se almacenan en fightersSG y fightersSB los soldados que se enfrentaran por cada
		//equipo.
		while(!SG_army.empty() && !SB_army.empty()){

			actualB = min(B, min((int)SG_army.size(),(int)SB_army.size()));
			i=0;

			for(my_iterator = SG_army.begin(); i<actualB; i++){

				fightersSG.push_back(*my_iterator);
				SG_army.erase(my_iterator++);
			}

			i=0;
	
			for(my_iterator = SB_army.begin(); i<actualB; i++){

				fightersSB.push_back(*my_iterator);
				SB_army.erase(my_iterator++);
			}

			for(i=0;i<actualB;i++){
				//Se verifica si el soldado del equipo azul tiene un nivel de poder mayor o igual
				//a su contrincante del equipo verde, si es asi quiere decir que el soldado del equipo
				//verde es eliminado, o ambos, cambiando su valor a 0. En caso contrario, es el soldado 
				//del equipo azul el eliminado.
				if(fightersSB[i] >= fightersSG[i]){
				
					fightersSB[i] -= fightersSG[i];
					fightersSG[i] = 0;
				}else{

					fightersSG[i] -= fightersSB[i];
					fightersSB[i] = 0;
				}
			}

			//Aqui se verifica que soldado es el que se devuelve al equipo para otro enfrentamiento, en donde
			//para que se cumpla, su nivel de poder debe ser mayor que 0.
			for(i=0;i<actualB;i++){
				
				if(fightersSB[i]!=0){
					SB_army.insert(fightersSB[i]);
				}

				if(fightersSG[i]!=0){
					SG_army.insert(fightersSG[i]);
				}
			}

			fightersSG.clear();
			fightersSB.clear();
		}
		//Si ambos multiset estan vacios, quiere decir que todos los soldados murieron en batalla.
		if(SG_army.empty() && SB_army.empty()){
			cout<<"green and blue died"<<endl;
		}else if(!SG_army.empty()){
			cout<<"green wins"<<endl;
			//En este caso es el multiset definido para el equipo verde el que queda con elementos
			//para lo cual se utiliza un iterador para obtenerlos.
			for(my_iterator = SG_army.begin(); my_iterator!= SG_army.end(); my_iterator++){
				cout<<*my_iterator<<endl;
			}
		}else{
			//Este es el caso en donde el multiset definido para el equipo azul queda con elementos.
			cout<<"blue wins"<<endl;
			for(my_iterator = SB_army.begin(); my_iterator!= SB_army.end(); my_iterator++){
				cout<<*my_iterator<<endl;
			}
		}

		flag_first = true;
		SG_army.clear();
		SB_army.clear();
	}

	return 0;
}
