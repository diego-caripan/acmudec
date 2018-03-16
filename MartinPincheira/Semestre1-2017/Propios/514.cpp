#include <stack>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;


int main(){

  int tam;

	cin >> tam;
 
	while(tam != 0){
    
		while(1){
			
			int primer,valores[tam],contador = 1;
			stack <int> mystack;
  
			scanf("%d",&primer);
        
			if(primer!= 0){
				valores[0]=primer;

				for(int i=1;i<tam;i++) cin >> valores[i];
        
   				for(int i=0;i<tam;i++){

					if(valores[i] == contador) contador++;
					else if(valores[i] < contador){
                     
						if(mystack.empty() || valores[i] != mystack.top()){
							cout << "No" << endl;
							break;
						}
                         
						else  mystack.pop(); 
					}

					else if(valores[i] > contador){
			
						while(valores[i] > contador){
               
							mystack.push(contador);
							contador++; 
						}

						contador++; 
					}
				} 

				if(mystack.empty())  cout << "Yes" << endl; 
			}

			else { 
			        cin >> tam;
        			puts("");
				break;
      			}
		}
	}

	return 0;
}
