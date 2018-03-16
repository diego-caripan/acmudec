#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){
	int N, n, total1,total2, total3, total4;
	char aux;
	bool verif;
	cin >> N >> n;
	cin.ignore();
	vector< vector <char> > Square, square;
	while (N!=0 && n!=0){
		REP(i,0,N){
			Square.push_back(vector<char>());
			REP(j,0,N){
				cin >> aux;
				Square[i].push_back(aux);
			}
			cin.ignore();
		}

		REP(i,0,n){
			square.push_back(vector<char>());
			REP(j,0,n){
				cin>>aux;
				square[i].push_back(aux);
			}
			cin.ignore();
		}
		total1=0;
		total2=0;
		total3=0;
		total4=0;
		REP(j,0,N-n+1){REP(k,0,N-n+1){
				if (Square[j][k] == square[0][0]){
					verif=true;
					REP(l,0,n){REP(p,0,n){
							if(Square[j+l][k+p]!=square[l][p]){
								verif=false;
								break;
							}
						}
						if (verif==false)break;
					}
					if (verif) total1++;
				}

				if (Square[j][k] == square[n-1][0]){
					verif=true;
					REP(l,0,n){REP(p,0,n){
							if(Square[j+l][k+p]!=square[n-1-p][l]){verif=false;break;}
						}
						if (verif==false)break;
					}
					if (verif) total2++;
				}

				if (Square[j][k] == square[n-1][n-1]){
					verif=true;
					REP(l,0,n){REP(p,0,n){
							if(Square[j+l][k+p]!=square[n-1-l][n-1-p]){verif=false;break;}
						}
						if (verif==false)break;
					}
					if (verif) total3++;
				}

				if (Square[j][k] == square[0][n-1]){
					verif=true;
					REP(l,0,n){REP(p,0,n){
							if(Square[j+l][k+p]!=square[p][n-1-l]){verif=false;break;}
						}
						if (verif==false)break;
					}
					if (verif) total4++;
				}

			}
		}
		printf("%d %d %d %d\n",total1, total2, total3, total4 );
		scanf("%d %d", &N, &n);		
		Square.clear();
		square.clear();
	}
}