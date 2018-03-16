#include <bits/stdc++.h> 
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int algo = 0;
	while(n!=0){
		if(algo !=0) printf("\n");
		algo++;
		int number =1234;
		int res;
		vector <int> respuesta;
		while(number<98765){
			bool posible = true;
			bool reviso = true;
			string num,nume;
			num = to_string(number);
			vector <bool> vec (10,false);
			if(number<=9999){
			 	num = "0" + num;
			 }
			for(int i=0;i<num.size();i++){
				if(vec[(int)num[i]]==true){
					reviso = false;
				}
				vec[(int)num[i]] = true;
			}
			if(reviso){
				res=n*number;
				nume = to_string(res);
				if(res<=98765){
					if((res>9999 && number>9999) || (res>=9999 || number>=9999) && (res<9999 || number<9999)){
					for(int i=0;i<nume.size();i++){
						if(vec[(int)nume[i]]){
				 			posible = false;
				 			i = nume.size();
				 			}
				 		vec[(int)nume[i]] = true;
					}
				}else posible = false;
				} else break;
			}
			else posible = false;
			if(!posible) number++;
			else{
				respuesta.push_back(res);
				respuesta.push_back(number);
				number++;
			}
		}
			if(!respuesta.empty()){
				for(int i=0;i<respuesta.size();i+=2){
					if(respuesta[i+1]<9999) printf("%d / 0%d = %d\n",respuesta[i],respuesta[i+1],n);
					else printf("%d / %d = %d\n",respuesta[i],respuesta[i+1],n);
				}
			}
			else printf("There are no solutions for %d.\n",n);
		scanf("%d",&n);
	}
}