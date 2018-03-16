#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int turnNumber(long num);
char even;

int main(){
	int gridSize, midPos, currTurn=0;
	long position, currPos,start;
	int x=0,y=0, found=0;
	while(1){
		scanf("%d %ld", &gridSize, &position);
		if(!gridSize || !position){
			break;
		}
		midPos=gridSize/2+1;
		currTurn=turnNumber(position);
		start = 2*currTurn-1;
		currPos=start*start;
		found=0;
		x=turnNumber(currPos)-even;y=x;
		even=0;
		while(!found){
			if(currPos==position){
				found=1;
				break;
			}
			y++;
			currPos++;
			if(currPos==position){				
				found=1;
				break;
			}

			currTurn=turnNumber(currPos);
			for(;x>-currTurn && !found; x--){
				currPos++;
				if(currPos==position){
					found=1;
				}
			}
			if(found){
				break;
			}

			for(;y>-currTurn && !found;y--){
				currPos++;
				if(currPos==position){
					found=1;
				}	
			}
			if(found){
				break;
			}
			for(;x<currTurn && !found; x++){
				currPos++;
				if(currPos==position){
					found=1;
				}
			}
			if(found){
				break;
			}
			for(;y<currTurn && !found; y++){
				currPos++;
				if(currPos==position){
					found=1;
				}
			}
			if(found){
				break;
			}
		}
		printf("Line = %d, column = %d.\n", midPos+y ,midPos+x);
	}
	return 0;
}

int turnNumber(long num){
	if(num==1){
		return 0;
	}
	if(ceil(sqrt(num))==sqrt(num) && num%2){
		even=1;
		return sqrt(num)-sqrt(num)/2+1;
	}
	return (int)ceil(sqrt(num))%2==1 ? (int)ceil(sqrt(num))-((int)ceil(sqrt(num))/2)-1 : (int)ceil(sqrt(num)) - ((int)ceil(sqrt(num))/2);
	
}