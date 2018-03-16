#include <cstdio>
#include <algorithm>

//Lo que se realiza en este codigo es leer los valores correspondientes al numero de camas
//disponibles en cada hotel, sacando asi el numero maximo de ellos, para luego verificar si
//el monto de cada pieza por la cantidad necesitada superaba al monto disponible.

using namespace std;

int main(){

	int N,B,H,W,p,ans,cap;
	
	while(scanf("%d %d %d %d",&N,&B,&H,&W) == 4){
	
		ans = B + 1;
	
		for(int i = 0;i < H;++i){
		
			scanf("%d",&p);
			cap = 0;
	
			for(int j = 0,x;j < W;++j){
	
				scanf("%d",&x);
				cap = max(cap,x);
			}
			
			if(cap >= N) ans = min(ans,N * p);
		}

		if(ans == B+1) puts("stay home");
		else printf("%d\n",ans);
	}

	return 0;
}
