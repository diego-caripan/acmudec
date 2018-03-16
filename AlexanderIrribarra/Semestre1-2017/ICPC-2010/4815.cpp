/*
	codigo propio
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<bool> visited;
vector<bool> ready;
vector<int> height;
bool work=true;
int k,w,a,b,l;
void dfs(int node, int prev, int h){
    if(visited[node]) return;
    visited[node] = true;
    height[node]= h;
    
    for(int i = 0;i<graph[node].size();i++){
        int next= graph[node][i];
        
        if(!visited[next])
        	dfs(next,node,h + 1);
        else if(next != prev && !ready[next]) 
        	l = h - height[next] + 1;
    }
    
    ready[node] = true;
}
int main(){
	while(scanf("%d %d",&k,&w)&&k){
		map<int,int> trans;
		int index=0;
		work=true;
		graph.clear();
		for(int i=0;i<w;i++){
			cin>>a>>b;
			//cout<<a<<" "<<b<<endl;	
			if(trans.count(a)==0){
				trans[a]=index++;
				graph.push_back(vector<int>());
			}
			if(trans.count(b)==0){
				trans[b]=index++;
				graph.push_back(vector<int>());
			}
			a=trans[a];
			b=trans[b];
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for(int i=0;i<graph.size();i++){
			sort(graph[i].begin(),graph[i].end());
			vector<int>::iterator last=unique(graph[i].begin(),graph[i].end());
			graph[i].erase(last,graph[i].end());
			if(graph[i].size()>2){
				//cout<<"RIP"<<endl;
				work=false;
				break;
			}
		}
		
		visited.assign(graph.size(),false);
		ready.assign(graph.size(),false);
		height.assign(graph.size(),0);
		l=-1;
		for(int i=0;i<graph.size()&&work;i++){
			if(!visited[i])
				dfs(i,-10,0);
		}
		//cout<<l<<endl;
		if(l!=-1&&l!=k){
			work=false;
			//cout<<"RIP2"<<endl;
		}
		printf("%s\n",(work?"Y":"N"));
	}
	return 0;
}