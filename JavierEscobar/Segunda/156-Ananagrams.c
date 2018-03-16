#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORDS 1000
#define MAXLEN 21

void swap(char* first, char* second);
char isLess(char* first, char* second);
char isAnagram(char* main, char* sec);

int main(int argc, char** argv){
	char** dictionary = malloc(MAXWORDS*MAXLEN);
	int c, wordLen=0, dicLen=0, i;
	dictionary[dicLen] = malloc(MAXLEN);
	while((c=getchar())!=EOF && dicLen<MAXWORDS){
		if(c==' ' || c=='\n' || c=='#'){
			if(wordLen){
				dictionary[dicLen][wordLen+1]='\0';
				if(dicLen>1){
					for(i=0; i<dicLen-1; i++){
						
						if(isLess(dictionary[dicLen], dictionary[i])){
							
							swap(dictionary[dicLen], dictionary[i]);
						}
					}
				}
				dicLen++;
				dictionary[dicLen] = malloc(MAXLEN);
				wordLen=0;
			}
			if(c=='#')			{
				break;
			}
			continue;
		}
		else{
			dictionary[dicLen][wordLen]=c;
			wordLen++;
		}
	}
	char poss[dicLen][dicLen];
	int j;
	for(i=0; i<dicLen; i++){	
		poss[i][i]=0;
		for(j=i+1; j<dicLen; j++){	
			if(isAnagram(dictionary[i],dictionary[j])){
				poss[i][j]=1;
				poss[j][i]=1;
			}
			else{
				poss[i][j]=0;
				poss[j][i]=0;
			}
		}			
	}
	int found=0;
	for(i=0; i<dicLen; i++){
		found=0;
		for(j=0; j<dicLen; j++){
			if(poss[i][j]){
				found=1;
				break;
			}	
		}
		if(!found){
			printf("%s\n", dictionary[i]);
		}		
	}
	for(i=0; i<dicLen; i++){
		free(dictionary[i]);
	}
	free(dictionary);
	return 0;
}

void swap(char* first, char* second){
	char aux[21];
	strcpy(aux, first);
	strcpy(first, second);
	strcpy(second,aux);
}

char isLess(char* first, char* second){
	int i;
	for(i=0; i<strlen(first) && i<strlen(second); i++){
		if(first[i]<second[i]){
			return 1;
		}
		else if(first[i]>second[i]){
			return 0;
		}
	}
	if(i>=strlen(first) || i>=strlen(second)){
		if(strcasecmp(first, second)<0){
						return 1;
		}		
	}
	return 0;
}

char isAnagram(char* main, char* sec){

	char fset[26]={0}, sset[26]={0};
	int c=0;
	while(main[c]!='\0'){
		fset[toupper(main[c])-'A']++;
		c++;
	}
	c=0;
	while(sec[c]!='\0'){
		sset[toupper(sec[c])-'A']++;
		c++;
	}
	for(c=0; c<26; c++){
		if(fset[c]!= sset[c]){
			return 0;
		}
	}
	return 1;
}
