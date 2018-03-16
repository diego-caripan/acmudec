#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int* array, int start, int size);

int main(){
	int i,j,n,inserts,removes,stack[1000], queue[1000],sortedElements[1000];
	int op, ele, realSize,size,start;
	char isQ, isPQ, isStack, print=0;
	while(scanf("%d",&n) != EOF){
		
		if(print)
			printf("number of cases: %d\n",n);
		size=realSize=inserts=start=0;
		isQ=isPQ=isStack=1;		
		for(i=0;i<1000;i++){
			stack[i]=0;
			queue[i]=0;
			sortedElements[i]=0;
		}
		for(i=0; i<n; i++){
			scanf("%d %d", &op, &ele);
			if(print)
			printf("%d %d\n", op, ele);
			if(op==1){
				if(isQ)
					queue[size+start]=ele;
				if(isStack)
					stack[size]=ele;
				if(isPQ){
					sortedElements[size+start]=ele;
					sort(&sortedElements[0], start, size+start+1);
				}
				if(size==realSize){
					realSize++;					
				}
				size++;
			}
			else if(op==2){				
				if(isQ && queue[start]!=ele){
					if(print){
						printf("elements[%d]: %d - ele: %d\n", start,queue[start], ele);
						puts("not a queue");
					}
					isQ=0;
				}
				if(isStack && stack[size-1]!=ele){
					if(print){
						printf("elements[%d]: %d - ele: %d\n", size-1,stack[size-1], ele);
						puts("not a stack");						
					}
					isStack=0;
				}
				if(isPQ && sortedElements[start]!=ele){
					if(print){
						printf("elements[%d]: %d - ele: %d\n", start,sortedElements[start], ele);
						puts("not a priq");
					}
					isPQ=0;			
				}
				size--;
				start++;		
				if(!size){
					realSize=0;
					inserts=0;
					start=0;
				}
			}
			if(print){
				printf("realSize:%d size:%d\n",realSize,size);
				if(isQ){
					printf("\tqueue: ");
					for(j=0;j<size+start; j++){
						if(j==start){
							printf("[ ");
						}
						printf("%d ", queue[j]);
					}
					puts("]");
				}
				if(isStack ){
					printf("\tstack: [ ");
					for(j=0;j<realSize; j++){
						printf("%d ", stack[j]);
						if(j==size-1){
							printf("] ");
						}
					}
					puts("");
				}
				if(isPQ){
					printf("\tpriq: ");
					for(j=0;j<start+size; j++){
						if(j==start){
							printf("[ ");
						}
						printf("%d ", sortedElements[j]);
					}
					puts("]");
				}
			}

		}
		if(isQ+isPQ+isStack>1){
			puts("not sure");
		} else if(isQ){
			puts("queue");
		} else if(isPQ){
			puts("priority queue");
		} else if(isStack){
			puts("stack");
		} else{
			puts("impossible");
		}
		if(print)
			puts("///");
	}
	return 0;
}

void sort(int* array, int start, int size){
	if(size==1){
		return;
	}
	int i,j, aux;
	for(i=start;i<size; i++){
		for(j=i+1; j<size; j++){
			if(array[i]<array[j]){
				aux=array[i];
				array[i]=array[j];
				array[j]=aux;
			}
		}
	}
	/*
	printf("\tsorted: [ ");
	for(i=start;i<size; i++){
		printf("%d ", array[i]);
	}
	puts("]");*/
	
}