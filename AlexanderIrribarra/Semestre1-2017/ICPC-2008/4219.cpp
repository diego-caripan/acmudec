/*
	codigo propio
*/

#include <bits/stdc++.h>

using namespace std;

int cardn(char c){
	if(c=='C')
		return 0;
	else if(c=='D')
		return 1;
	else if(c=='H')
		return 2;
	else if(c=='S')
		return 3;
}

pair<int,int> current;

bool valid(pair<int,int> c){
	return c.first==current.first || c.second==current.second;
}




/*
	efectos:
	12: da vuelta el sentido
	7: +2 y salta
	1: +1 y salta
	11: solo salta	

*/

int main(){
	int p,m,n;
	int dir;
	while(cin>>p>>m>>n && p+m+n){
		int player=0;
		dir=1;		//parte en sentido horario
		queue<pair<int,int> > deck;
		vector<vector<pair<int,int> > > hand(p,vector<pair<int,int> >());
		for(int i=0;i<n;i++){	//leo el mazo
			int aux;
			char c;
			cin>>aux>>c;
			deck.push(make_pair(aux,cardn(c)));		//numero - pinta
		}
		for(int i=0;i<p;i++){	//reparto cartas
			for(int j=0;j<m;j++){
				hand[i].push_back(deck.front());
				deck.pop();
			}
			sort(hand[i].begin(),hand[i].end());
		}
		current=deck.front();	//descarta la primera;
		deck.pop();
		if(current.first==1||current.first==7||current.first==11){
			if(current.first==7){
				hand[player].push_back(deck.front());
				deck.pop();
				hand[player].push_back(deck.front());
				deck.pop();
				sort(hand[player].begin(),hand[player].end());
			}
			if(current.first==1){
				hand[player].push_back(deck.front());
				deck.pop();
				sort(hand[player].begin(),hand[player].end());
			}
			player++;
		}
		if(current.first==12){
			dir=-1;
		}
		while(1){
			//intentar tirar una carta
			bool lanzo=false;
			pair<int,int> jugada;
			for(int i=hand[player].size()-1;i>=0;i--){
				if(valid(hand[player][i])){			//lanza la de mayor prioridad
					jugada=hand[player][i];
					hand[player].erase(hand[player].begin()+i);
					lanzo=true;
					sort(hand[player].begin(),hand[player].end());
					break;
				}
			}

			if(!lanzo){	//roba otra e intenta tirarla
				pair<int,int> robada=deck.front();
				deck.pop();
				if(valid(robada)){
					jugada=robada;
					lanzo=true;
				}else{
					hand[player].push_back(robada);
					sort(hand[player].begin(),hand[player].end());
				}
			}

			if(hand[player].empty()){
				break;
			}
			if(lanzo){
				current=jugada;
				if(current.first==1||current.first==7||current.first==11){
					player=(player+dir+p)%p;	//avanzo al siguiente y le paso cartas
					if(current.first==7){
						hand[player].push_back(deck.front());
						deck.pop();
						hand[player].push_back(deck.front());
						deck.pop();
						sort(hand[player].begin(),hand[player].end());
					}
					if(current.first==1){
						hand[player].push_back(deck.front());
						deck.pop();
						sort(hand[player].begin(),hand[player].end());
					}
					
				}
				if(current.first==12){	//cambio la direccion
					dir*=-1;
				}
			}
			player=(player+dir+p)%p;
		}
		cout<<player+1<<endl;
	}
	return 0;
}