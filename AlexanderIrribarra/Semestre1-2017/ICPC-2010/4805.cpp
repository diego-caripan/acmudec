/*
	SegmentTree sacado del libro
	codigo propio
*/

#include <bits/stdc++.h>

using namespace std;


class SegmentTree {				 								// the segment tree is stored like a heap array
private: vector<int> st, A;										// recall that vi is: typedef vector<int> vi;
	int n;
	int left (int p) { return p << 1; }		 					// same as binary heap operations
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R) {							// O(n log n)
		if (L == R)												// as L == R, either one is fine
			st[p] = L;																				 // store the index
		else {													// recursively compute the values
			build(left(p) , L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2]) ? p1 : p2;
	} }

	int rmq(int p, int L, int R, int i, int j) {				// O(log n)
		if (i >	R || j <	L) return -1; 						// current segment outside query range
		if (L >= i && R <= j) return st[p];						// inside query range

		 														// compute the min position in the left and right part of the interval
		int p1 = rmq(left(p) , L, (L+R) / 2, i, j);
		int p2 = rmq(right(p), (L+R) / 2 + 1, R, i, j);

		if (p1 == -1) return p2;	 							// if we try to access segment outside query
		if (p2 == -1) return p1;								// same as above
		return (A[p1] <= A[p2]) ? p1 : p2; }					// as as in build routine
 
public:
	SegmentTree(const vector<int> &_A) {
		A = _A; n = (int)A.size();								// copy content for local usage
		st.assign(4 * n, 0);									// create large enough vector of zeroes
		build(1, 0, n - 1);										// recursive build
	}

	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }	// overloading
};

vector<vector<pair<int,long long int> > > graph;
vector<long long int> lengths;
vector<bool> visited;
vector<int> L;
vector<int> E;
vector<int> H;
int idx,n,a,l;

void dfs(int node,long long int weight){
	visited[node]=true;
	lengths[node]=weight;
	//cout<<weight<<endl;
	for(int i=0;i<graph[node].size();i++){
		if(!visited[graph[node][i].first]){
			dfs(graph[node][i].first,weight+graph[node][i].second);
		}
	}
}

void dfs2(int cur,int depth){
	H[cur]=idx;
	visited[cur]=true;
	E[idx]=cur;
	L[idx++]=depth;
	for(int i=0;i<graph[cur].size();i++){
		if(!visited[graph[cur][i].first]){	
			dfs2(graph[cur][i].first,depth+1);
			E[idx]=cur;
			L[idx++]=depth;
		}
	}
}

void buildRMQ(){
	idx=0;
	dfs2(0,0);
}

int main(){
	while(cin>>n && n){
		lengths.assign(n,0);
		visited.assign(n,false);
		L.assign(2*n,0);	
		E.assign(2*n,0);
		H.assign(n,0);
		graph.assign(n,vector<pair<int,long long int> >());
		for(int i=1;i<n;i++){
			cin>>a>>l;
			graph[i].push_back(make_pair(a,l));	
			graph[a].push_back(make_pair(i,l));
		}
		dfs(0,0);
		visited.assign(n,false);
		buildRMQ();
		SegmentTree st(L);
		int a1,a2;
		int q;
		cin>>q;
		for(int i=0;i<q;i++){
			cin>>a1>>a2;
			if(H[a1]>H[a2]){
				swap(a1,a2);
			}
			int ancestro=E[st.rmq(H[a1],H[a2])];
			cout<<(i==0?"":" ")<<(lengths[a1]-lengths[ancestro])+(lengths[a2]-lengths[ancestro]);
		}
		cout<<endl;
	}
	return 0;
}