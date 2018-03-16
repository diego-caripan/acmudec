#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

	int clicks[1001];
	int count;

	void click(int n){

		if(clicks[n] == 1){
			clicks[n] = 0;
			count -= 1;
		}
		else if(clicks[n] == 0){
			clicks[n] = 1;
			count += 1;
		}

		printf("%d\n",count);

	}

int main(){

	int r;
	int n_click;
	string action;

	count = 0;

	cin >> r;
	cin >> n_click;

	memset(clicks,0,sizeof(clicks));

	for(int i = 0; i< n_click;i++){

		cin >> action;

		if(!action.compare("CLICK")){

			cin >> r;

			click(r);

		}

		else{

			memset(clicks,0,sizeof(clicks));
			count = 0;
			printf("%d\n",count);

		}
	}




	return 0;
}
