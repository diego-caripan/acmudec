#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	int m,n;
    int books[10000];

    while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
	    	scanf("%d",&books[i]);
	 	}
	    scanf("%d",&m);
	    sort(books,books+n);

	    int l = 0;
	    int r = n-1;
	    int L=0, R=0;

	    while(l<r){
	    	if(books[l] + books[r] < m){
	    		++l;
	    	}
	    	else if(books[l] + books[r] > m){
	    		--r;
	    	}
	    	else if(books[l] + books[r] == m){
	    		L = l;
	    		R = r;
	    		++l;
	    		--r;
	    	}
	    }

	    printf("Peter should buy books whose prices are %d and %d.\n\n",books[L],books[R]);
    }
}




