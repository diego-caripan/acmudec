#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


	int salaries[101];
	int n_workers;
	int mini;
	int turns;

	int equialize(){
		int index_max = 0;

		for(int i = 0; i < n_workers;i++) {
			if(salaries[i] > salaries[index_max]) index_max = i;
		}

		if(salaries[index_max] == mini) return 1;

		turns += (salaries[index_max] - mini);
		salaries[index_max] = mini;
		
		return 0;
	}

int main(){


	int test_case;
	int w_salaries;

	cin >> test_case;
	


	
	for(int i=0;i < test_case;i++){

		cin >> n_workers;
		turns = 0;	

		for(int i=0; i < n_workers; i++){
			scanf("%d",&w_salaries);
			if(i==0)	mini= w_salaries;

			if(w_salaries < mini) mini = w_salaries;

			salaries[i] = w_salaries;
			
		}


		while(1){
			if(equialize()) break;
		}	

		printf("%d\n",turns);
	}
	return 0;
}
