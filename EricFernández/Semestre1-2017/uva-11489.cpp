// uva-11489
#include <iostream>
using namespace std;

int main(){
	int K,M,N,X,Y;
	cin>>K;
	while(K!=0){
		cin>>M;
		cin>>N;
		while(K--){
		cin>>X;
		cin>>Y;
			if(X==M || Y==N)cout<<"divisa"<<std::endl;
			else if (X<M && Y<N)cout<<"SO"<<std::endl;
	 		else if (X>M && Y>N)cout<<"NE"<<std::endl;
	 		else if (X<M && Y>N)cout<<"NO"<<std::endl;
	 		else if (X>M && Y<N)cout<<"SE"<<std::endl;	
	 	}
	 cin>>K;

	}
return 0;

}
// al parecer no era necesario eso de guardar y lo que hice en el anterior xD
