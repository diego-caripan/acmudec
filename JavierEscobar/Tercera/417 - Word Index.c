#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char isValid(char* word);

int main(){
	int i,j,k,l,m, size, sum;
	char word[6];
	while(1){
		if(scanf("%s",word) == EOF){
			break;
		}
		
		/*printf("input: %s\n", word);*/
		if(!(size=isValid(word))){
			/*puts("\tinvalid, value: 0");*/
			puts("0");
			/*puts("///////");*/
			continue;
		}
		sum=0;
		/*printf("\tsize: %d\n", size);*/
		if(size==5){
			sum=17901;
			for(i=1;i<word[0]-96; i++){
				for(j=i+1; j<27; j++){
					for(k=j+1;k<27;k++){
						for(l=k+1;l<27;l++){
							for(m=l+1;m<27;m++){
								sum++;
							}
						}
					}
				}
			}
			for(i=word[0]-96+1;i<word[1]-96; i++){
				for(j=i+1; j<27; j++){
					for(k=j+1;k<27;k++){
						for(l=k+1;l<27;l++){
							sum++;							
						}
					}
				}
			}
			for(j=word[1]-96+1; j<word[2]-96; j++){
				for(k=j+1;k<27;k++){
					for(l=k+1;l<27;l++){
						sum++;							
					}
				}
			}
			for(k=word[2]-96+1;k<word[3]-96;k++){
					for(l=k+1;l<27;l++){
						sum++;							
					}
				}
			sum+=word[size-1]-word[size-2];
			printf("%d\n", sum);			
		}
		else if(size==4){
			sum=2951;
			for(i=1;i<word[0]-96; i++){
				for(j=i+1; j<27; j++){
					for(k=j+1;k<27;k++){
						for(l=k+1;l<27;l++){
							sum++;							
						}
					}
				}
			}
			for(j=word[0]-96+1; j<word[1]-96; j++){
				for(k=j+1;k<27;k++){
					for(l=k+1;l<27;l++){
						sum++;							
					}
				}
			}
			for(k=word[1]-96+1;k<word[2]-96;k++){
				for(l=k+1;l<27;l++){
					sum++;							
				}
			}
			sum+=word[size-1]-word[size-2];
			printf("%d\n", sum);
		}
		else if(size==3){
			sum=351;
			/*printf("word[0]=%d\n", word[0]-96);*/
			for(i=1;i<word[0]-96; i++){
				/*printf("%c\n",i+96);*/
				for(j=i+1; j<27; j++){
					/*printf("\t%c\n",j+96);*/
					for(k=j+1;k<27;k++){
						/*printf("\t\t%c\n",k+96);*/
						sum++;
					}
				}
			}	
			/*printf("sum so far: %d", sum);
			puts("-----------");*/
			for(j=word[0]-96+1; j<word[1]-96; j++){
				/*printf("\t%c\n",j+96);*/
				for(k=j+1;k<27;k++){
					/*printf("\t\t%c\n",k+96);*/
					sum++;
				}
			}
			sum+=word[size-1]-word[size-2];
			printf("%d\n", sum);
			/*puts("////");*/
		}
		else if(size==2){
			/*printf("word[0]=%d\nword[1]=%d\n",word[0]-96,word[1]-96);*/
			sum=26;
			for(i=1;i<word[0]-96; i++){
				/*printf("%c\n",i+96);*/
				for(j=i+1; j<27; j++){
					/*printf("\t%c\n",j+96);*/
					sum++;
				}
			}			
			sum+=word[size-1]-word[size-2];
			printf("%d\n", sum);
		}
		else if(size==1){
			printf("%d\n", word[0]-96);
		}

		

	}
	return 0;
}

char isValid(char* word){
	int i=0;
	while(word[i+1]!='\0'){
		if(word[i+1]<=word[i]){
			return 0;
		}
		i++;
	}
	return i+1;
}

