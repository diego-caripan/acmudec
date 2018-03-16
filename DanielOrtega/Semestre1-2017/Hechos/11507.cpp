#include <iostream>
#include <string>

using namespace std;


int main() {

	int n;

	while(1){
	cin >> n;
		if (n ==0)
			break;
 		
 		string pos1,a;
 		pos1= "+x";
		for( int i = 0; i <n-1; i++  ){

			cin >> a;
	

			if(!pos1.compare("+x")){
		
				if(!a.compare("+y"))
					pos1="+y";
				else if(!a.compare("-y"))
					pos1="-y";
				else if(!a.compare("+z"))
					pos1= "+z";
				else if(!a.compare("-z"))
					pos1 = "-z";
			}

			else if(!pos1.compare("-x")){

				if(!a.compare("+y"))
					pos1="-y";
				else if(!a.compare("-y"))
					pos1="+y";
				else if(!a.compare("+z"))
					pos1= "-z";
				else if(!a.compare("-z"))
					pos1 = "+z";
			}



			else if(!pos1.compare("+y")){
				if(!a.compare("+y"))
					pos1="-x";
				else if(!a.compare("-y"))
					pos1="+x";
				else if(!a.compare("+z"))
					pos1= "+y";
				else if(!a.compare("-z"))
					pos1= "+y";
			}
			else if(!pos1.compare("-y")){
				if(!a.compare("+y"))
					pos1="+x";
				else if(!a.compare("-y"))
					pos1="-x";
				else if(!a.compare("+z"))
					pos1= "-y";
				else if(!a.compare("-z"))
					pos1= "-y";
			}



			else if(!pos1.compare("+z")){
			
				if(!a.compare("+y"))
					pos1="+z";
				else if(!a.compare("-y"))
					pos1="+z";
				else if(!a.compare("+z"))
					pos1= "-x";
				else if(!a.compare("-z"))
					pos1= "+x";
			}
			else if(!pos1.compare("-z")){
				if(!a.compare("+y"))
					pos1="-z";
				else if(!a.compare("-y"))
					pos1="-z";
				else if(!a.compare("+z"))
					pos1= "+x";
				else if(!a.compare("-z"))
					pos1= "-x";	
			}
		}

		cout << pos1 << "\n";
	}
	
}

