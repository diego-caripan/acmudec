#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	
	char myChar;
	bool first = true;

	while((myChar = getchar()) != EOF ){
		if(myChar == '\"'){
			if(first){
				cout << "``";
				first = false;
				continue;
			}
			else{
				cout << "\'\'";
				first = true;
				continue;
			}
		}
			cout << myChar;
	} 

}
