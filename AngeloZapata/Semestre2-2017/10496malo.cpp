#include <bits/stdc++.h>
using namespace std;

int _min = INT_MAX;
int cbeep;
int xmax,ymax;
vector<vector<int> > DP;
vector<vector<int> > beep;

bool revisar(vector <bool> &nbeep){
	for(int i=0; i<nbeep.size(); i++) {
		if(nbeep[i] == false){
			return false;
		}
	}
	return true;
}
void mostrarDP(){
	for(int i=0; i<ymax; i++){
		for(int j=0; j<xmax; j++) {
			cout << DP[j][i] << " ";
		}
		cout << endl;
	}
}

bool busq(bool inicio ,int x,int y, int pasos,vector<bool> nbeep,vector<vector<bool> > pasitos){
	//cout << pasos << endl;
	pasitos[x-1][y-1] = true;
	if(revisar(nbeep)){
		cout << "revisar" << endl;
		if(pasos < _min) _min = pasos;
		DP[x-1][y-1] = pasos;
		mostrarDP();
		if(!inicio) return true;
	}


	if(beep[x-1][y-1] != -1) {
	//	cout << "if reemplazo" << endl;
		nbeep[beep[x-1][y-1]] = true;
	}
	if(x+1 < xmax && pasitos[x][y-1] == false && DP[x][y-1] > pasos+1) {
		if(busq(false,x+1,y,pasos+1,nbeep,pasitos)){
			cout << "derecha   " << x << " " << y << endl;
			DP[x-1][y-1] = pasos;
			if(!inicio) return true;
		}
	}
	if(y+1 < ymax && pasitos[x-1][y] == false && DP[x-1][y] > pasos+1){
		if(busq(false,x,y+1,pasos+1,nbeep,pasitos)){
			cout << "abajo     " << x << " " << y << endl;
			DP[x-1][y-1] = pasos;
			if(!inicio) return true;
		}
	}
	if(x-1 > 0 && pasitos[x-2][y-1] == false && DP[x-2][y-1] > pasos+1){
	//	cout << pasitos[x-2][y-1] << endl;
		if(busq(false,x-1,y,pasos+1,nbeep,pasitos)){
			cout << "izquierda " << x << " " << y << endl; 
			DP[x-1][y-1] = pasos;
			if(!inicio) return true;
		}
	}
	if(y-1 > 0 && pasitos[x-1][y-2] == false && DP[x-1][y-2] > pasos+1){
		if(busq(false,x,y-1,pasos+1,nbeep,pasitos)){
			cout << "arriba    " << x << " " << y << endl;
			DP[x-1][y-1] = pasos;
			if(!inicio) return true;
		}
	}
	if(inicio) return true;	
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x,y,yox,yoy;
		cin >> xmax >> ymax;
		cin >> yox >> yoy;
		DP = vector <vector <int> > (ymax, vector<int> (xmax,INT_MAX));
		beep = vector <vector <int> > (ymax, vector<int> (xmax, -1));
		vector <vector <bool> > pasitos(ymax, vector<bool> (xmax, false));
		cin >> cbeep;
		for(int j=0; j<cbeep; j++){
			cin >> x >> y;
			beep[x-1][y-1] = j;
		}
		vector <bool> nbeep(cbeep,false);
		cout << "busq" << endl;
		busq(true,yox,yoy,0,nbeep,pasitos);
		cout << "min " << _min << '\n';
	}
	return 0;
}