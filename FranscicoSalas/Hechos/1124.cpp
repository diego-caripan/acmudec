#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	
	char myChar;

	while((myChar = getchar()) != EOF ){
		cout << myChar;
	}

}