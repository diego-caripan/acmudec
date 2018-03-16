	#include <bits/stdc++.h>

	using namespace std;

	int n,k,maximo;
	vector <vector <int> >grafo;
	vector <bool> visitado;

	bool bfs(int pos){
		bool retorno = true;
		if(grafo[pos].size() == 0){
			visitado[pos]= true;
			return false;
		}
		int act = pos;
		queue <int> q;
		q.push(act);
		visitado[pos] = true;
		while(!q.empty()){
			act = q.front();
			q.pop();
			if(grafo[act].size() == 1)retorno = false;
			for(int j = 0; j < grafo[act].size();j++){
				if(!visitado[grafo[act][j]]){
					visitado[grafo[act][j]] = true;
					q.push(grafo[act][j]);
				}
			}
		}
		return retorno;
	}

	bool comp(){
		bool entro = false,aux,uno = false;
		visitado.clear();
		visitado.resize(grafo.size(),false);
		for(int i = 0; i < grafo.size(); i++){
			if(!visitado[i]){
				aux = bfs(i);
				if(aux && !entro)entro = true;
				else if(aux && entro){ 
					return false;
				}
			}
		}
		for(int i = 0; i < grafo.size();i++){
			if(grafo[i].size() > 2){
				return false;
			}
			if(grafo[i].size() == 1)uno = true;
		}
		if(entro && maximo  < n){
			return false;
		}
		if(entro && uno ){
			return false;
		}
		return true;
	}

	int main(){
		int a,b;
		while(1){
			scanf("%d %d",&n,&k);
			if(n == 0 && k == 0)break;
			for(int i = 0; i < grafo.size();i++)grafo[i].clear();
			map <int,int>existe;
			int pos = 1;
			vector <pair <int,int> >wi;
			for(int i = 0; i < k; i++){
				scanf("%d %d",&a,&b);
				wi.push_back(make_pair(a,b));
				if(existe[a] == 0){
					existe[a] = pos;
					pos++;
				}
				if(existe[b] == 0){
					existe[b] = pos;
					pos++;
				}
			}
			grafo.resize(pos-1);
			for(int i = 0; i < wi.size();i++){
				bool meter = true;
				for(int j = 0; j < grafo[existe[wi[i].first]-1].size();j++){
					if(grafo[existe[wi[i].first]-1][j] == existe[wi[i].second]-1)meter = false;
				}
				if(meter){
				grafo[existe[wi[i].first]-1].push_back(existe[wi[i].second]-1);
				grafo[existe[wi[i].second]-1].push_back(existe[wi[i].first]-1);					
				}
			}
			maximo = pos-1;
			if(comp())printf("Y\n");
			else puts("N");
		}
		return 0;
	}