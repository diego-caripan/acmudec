#include <iostream>

using namespace std;


int main() {

int casos;
int div1,div2;
int pos1,pos2;

while (cin >> casos  && (casos!=0)){

		cin >> div1 >> div2;
		 

		while(casos--){
		cin >> pos1 >> pos2;

		
			if(div1 == pos1 || div2 == pos2)
				cout << "divisa\n";

		
			 else if(pos1 > div1){
			
					if(pos2 > div2)
					  cout << "NE\n";
					else 
						cout << "SE\n";

			}

			else if (pos1 < div1){

				if(pos2 > div2)
					cout << "NO\n";
				else	
					 cout << "SO\n";
  
  

			}


			

    
    	



 




}

}


}