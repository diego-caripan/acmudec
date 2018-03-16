#include <cstdlib>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm> 


using namespace std;

/*
i push
o pop

*/

int main(){

	string source,target;
	stack s;

while(!cin.eof()){

	cin >> source;
	cin >> target;

		

	cout << "[\n";

	if(is_permutation(source.begin(),source.end(),target.begin())){

		cout << "aqui deberia ir algo\n";
	
		

		cout << "]\n";
	}	  
	else {
			cout << "]\n";
			continue;
		}


}
		
	return 0;
}