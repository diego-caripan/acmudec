#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> par;

//primos:  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79
//fghij * n = abcde;

bool comp(string a, string b){
	if(b.size() == 4){
		if(a[0]=='0' || a[1]=='0' || a[2]=='0' || a[3] == '0' || a[4]=='0'){
			return false;
		}
		else if(b[0]!=b[1] && b[0]!=b[2] && b[0]!=b[3] && b[1]!=b[2] && b[2]!=b[3] &&
		a[0]!=a[1] && a[0]!=a[2] && a[0]!=a[3] && a[0]!=a[4] &&
		a[1]!=a[2] && a[1]!=a[3] && a[1]!=a[4] && 
		a[2]!=a[3] && a[2]!=a[4] && a[3]!=a[4] &&
		b[0]!=a[0] && b[0]!=a[1] && b[0]!=a[2] &&
		b[0]!=a[3] && b[0]!=a[4] && b[1]!=a[0] && b[1]!=a[1] && b[1]!=a[2] &&
		b[1]!=a[3] && b[1]!=a[4] && b[2]!=a[0] && b[2]!=a[1] && b[2]!=a[2] &&
		b[2]!=a[3] && b[2]!=a[4] && b[3]!=a[0] && b[3]!=a[1] && b[3]!=a[2] &&
		b[3]!=a[3] && b[3]!=a[4]) return true;
		else return false;
	}
	else{
		if(b[0]!=b[1] && b[0]!=b[2] && b[0]!=b[3] && b[1]!=b[2] && b[2]!=b[3]
			&& b[2]!=b[4] && b[3]!=b[4] &&
		a[0]!=a[1] && a[0]!=a[2] && a[0]!=a[3] && a[0]!=a[4] &&
		a[1]!=a[2] && a[1]!=a[3] && a[1]!=a[4] && 
		a[2]!=a[3] && a[2]!=a[4] && a[3]!=a[4] &&
		b[0]!=a[0] && b[0]!=a[1] && b[0]!=a[2] &&
		b[0]!=a[3] && b[0]!=a[4] && b[1]!=a[0] && b[1]!=a[1] && b[1]!=a[2] &&
		b[1]!=a[3] && b[1]!=a[4] && b[2]!=a[0] && b[2]!=a[1] && b[2]!=a[2] &&
		b[2]!=a[3] && b[2]!=a[4] && b[3]!=a[0] && b[3]!=a[1] && b[3]!=a[2] &&
		b[3]!=a[3] && b[3]!=a[4] && b[4]!=a[0] && b[4]!=a[1] && b[4]!=a[2] &&
		b[4]!=a[3] && b[4]!=a[4]) return true;
		else return false;
	}
}

int main(){
	vector<par> v;
	int n,a,f = 0,cont = 0,c;
	while(1){
		scanf("%d",&n);
		c = 0;
		if(n == 0)
			break;
		if(cont != 0)
			printf("\n");
			f = 1000;
		for(int i=0 ; i<50000 ; i++){
			a = f*n;
			if(a >= 10000 && a < 100000){
				stringstream ss;
				ss << a << ' ' << f;
				string ab,fg;
				ss >> ab >> fg;
				if(ab[0]!=ab[1] && ab[0]!=ab[2] && ab[0]!=ab[3] && ab[0]!=ab[4] &&
					ab[1]!=ab[2] && ab[1]!=ab[3] && ab[1]!=ab[4] && 
					ab[2]!=ab[3] && ab[2]!=ab[4] && ab[3]!=ab[4] &&

					fg[0]!=fg[1] && fg[0]!=fg[2] && fg[0]!=fg[3] && fg[0]!=fg[4] &&
					fg[1]!=fg[2] && fg[1]!=fg[3] && fg[1]!=fg[4] && 
					fg[2]!=fg[3] && fg[2]!=fg[4] && fg[3]!=fg[4]){
					if(fg.size() == 4){
						if(fg[0]!='0' && fg[1]!= '0' && fg[2]!='0' && fg[3]!='0'){
							bool asd = comp(ab,fg);
							if(asd){
								printf("%d / 0%d = %d\n",a,f,n);
								c++;
							}
						}
					}
					else if(fg.size() == 5){
						bool asd = comp(ab,fg);
						if(asd){
							printf("%d / %d = %d\n",a,f,n);
							c++;
						}
					}
				}
			}
			f++;
		}
		cont++;
		if(c == 0)
			printf("There are no solutions for %d.\n",n);
	}
	return 0;
}