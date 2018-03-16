#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void sort(int *array, int size, int mod);
void swap(int* num1, int* num2);

int main(){
	int a,i,j,n,m, neg, pos;
	int nums[10000];
	int negs[10000];
	while(1){
		scanf("%d %d", &n,&m);
		if(n==0 && m==0){
			printf("%d %d\n", n, m);
			break;
		}
		neg=pos=0;
		for(i=0;i<n;i++){
			scanf("%d",&j);
			if(j<0){
				if(!(j%m)){
					nums[pos]=j;
					pos++;
				}
				else{
					negs[neg]=j;
					neg++;				
				}
			}
			else{
				nums[pos]=j;
				pos++;
			}
		}
		printf("%d %d\n",n,m);
		sort(&negs[0], neg,m);		
		sort(&nums[0], pos,m);
		/*for(i=0;i<neg;i++){
			printf("%d\n",negs[i]);
		}
		for(i=0;i<pos;i++){
			printf("%d\n",nums[i]);
		}*/
	}
	return 0;
}



void sort(int* array, int size, int mod){
	if(!size){
		return;
	}
	int i,j,k, res1, res2, even1, even2;
	for(i=0; i<size-1; i++){
		for(j=i+1; j<size;j++){
			res1=array[i]%mod;
			res2=array[j]%mod;
			if(res1>res2){
				/*intf("%d>%d\n",array[i]%mod,array[j]%mod);
				printf("swapped %d with %d\n", array[i],array[j]);*/
				swap(&array[i],&array[j]);
			}
			else if(res1==res2){
				/*puts("tie!");
				printf("\t%d vs %d\n",array[i],array[j]);*/
				even1 = array[i]%2==0;
				even2 = array[j]%2==0;
				if(even1 && !even2){
					/*printf("\t%d<%d\n",array[i],array[j]);
					printf("swapped %d with %d\n", array[i],array[j]);*/
					swap(&array[i],&array[j]);
				}
				else if(!even1 && !even2){
					if(array[i]<array[j]){
						/*printf("\t%d>%d\n",array[i],array[j]);
						printf("swapped %d with %d\n", array[i],array[j]);*/
						swap(&array[i],&array[j]);
					}
				}
				else if(even1 && even2){
					if(array[i]>array[j]){
						/*printf("\t%d<%d\n",array[i],array[j]);
						printf("swapped %d with %d\n", array[i],array[j]);*/
						swap(&array[i],&array[j]);
					}
				}
			}
		}
		printf("%d\n",array[i]);
	}
	printf("%d\n",array[i]);
}

void swap(int* num1, int* num2){
	int aux= *num1;
	*num1=*num2;
	*num2=aux;
}