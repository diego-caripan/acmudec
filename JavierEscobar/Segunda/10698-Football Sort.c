#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct teams{
	char name[16];
	int score;
	int games;
	int goals;
	int goalsSuf;
	int goalDif;
} Team;


char isLess(char* first, char* second);
void swap(int* a, int*b);
void sortTeams(Team* t, int* p, int numTeams);

int main(){
	int i,j, numTeams, numGames;
	char teamLeft[16], teamRight[16];
	int goalsLeft, goalsRight, scoreLeft, scoreRight;
	Team teams[28]={0};
	int board[28]={0};
	char first=1;
	while(1){
		scanf("%d %d", &numTeams, &numGames);
		if(!numTeams && !numGames){
			break;
		}
		if(!first){
			puts("");
		}
		first=0;
		for(i=0; i<numTeams; i++){
			scanf("%s", teams[i].name);
		}		
		for(i=0; i<numGames; i++){
			scanf("%s %d - %d %s", teamLeft, &goalsLeft, &goalsRight, teamRight);
			if(goalsLeft==goalsRight){
				scoreLeft=scoreRight=1;
			}
			else{
				if(goalsLeft>goalsRight){
					scoreLeft=3;
					scoreRight=0;
				}
				else{
					scoreLeft=0;
					scoreRight=3;
				}
			}
			for(j=0; j<numTeams;j++){
				if(!strcmp(teamLeft, teams[j].name)){
					teams[j].score+=scoreLeft;
					teams[j].goals+=goalsLeft;
					teams[j].goalsSuf+=goalsRight;
					teams[j].games++;	
					teams[j].goalDif=teams[j].goals-teams[j].goalsSuf;
				}
				if(!strcmp(teamRight, teams[j].name)){
					teams[j].score+=scoreRight;
					teams[j].goals+=goalsRight;
					teams[j].goalsSuf+=goalsLeft;
					teams[j].games++;	
					teams[j].goalDif=teams[j].goals-teams[j].goalsSuf;
				}
			}
		}
		sortTeams(teams, board,numTeams);
		Team tm;
		for(i=0;i<28;i++){
			strcpy(teams[i].name,"");
			teams[i].score=0;
			teams[i].games=0;
			teams[i].goals=0;
			teams[i].goalsSuf=0;
			teams[i].goalDif=0;
			board[i]=0;
		}


	}
}

void sortTeams(Team* teams, int* board,int numTeams){
	int i,j, k, max;
	for(i=0; i<numTeams; i++){
		board[i]=i;		
	}
	for(i=0; i<numTeams; i++){
		max=i;
		for(j=i+1; j<numTeams; j++){
			if(teams[board[j]].score>teams[board[max]].score)	{
				max = j;
			}
		}
		if(max!=i){
			swap(&board[i],&board[max]);
		}
	}
	for(i=0;i<numTeams; i++){
		max=i;
		for(j=i+1; j<numTeams 
					&& teams[board[j]].score==teams[board[max]].score; j++){
			if(teams[board[j]].goalDif>teams[board[max]].goalDif){
				max=j;
			}
		}		
		if(max!=i){
			swap(&board[i],&board[max]);
		}
	}
	for(i=0;i<numTeams; i++){
		max=i;
		for(j=i+1; j<numTeams 
					&& teams[board[j]].score==teams[board[max]].score
					&& teams[board[j]].goalDif==teams[board[max]].goalDif; j++){
			if(teams[board[j]].goals>teams[board[max]].goals){
				max=j;
			}
		}		
		if(max!=i){
			swap(&board[i],&board[max]);
		}
	}
	for(i=0;i<numTeams; i++){
		max=i;
		for(j=i+1; j<numTeams 
					&& teams[board[j]].score==teams[board[max]].score
					&& teams[board[j]].goalDif==teams[board[max]].goalDif
					&& teams[board[j]].goals==teams[board[max]].goals; j++){
			if(isLess(teams[board[j]].name,teams[board[max]].name)){
				max=j;
			}
		}		
		if(max!=i){
			swap(&board[i],&board[max]);
		}
	}
	for(i=0; i<numTeams; i++){
		if(i && teams[board[i]].score==teams[board[i-1]].score
			&& teams[board[i]].goalDif==teams[board[i-1]].goalDif
			&& teams[board[i]].goals==teams[board[i-1]].goals){
			printf("    ");
		}
		else{
			printf("%2d. ", i+1);
		}
		printf("%15s  %2d  %2d  %2d  %2d  %2d", teams[board[i]].name, 
												teams[board[i]].score, 
												teams[board[i]].games, 
												teams[board[i]].goals, 
												teams[board[i]].goalsSuf, 
												teams[board[i]].goalDif);	
		if(teams[board[i]].games){
			printf(" %6.2f\n", (float)teams[board[i]].score/(3*teams[board[i]].games)*100);
		}
		else{
			printf("    N/A\n");	
		}
	}
}

void swap(int* a, int*b){
	int aux;
	aux = *a;
	*a=*b;
	*b=aux;
}

char isLess(char* first, char* second){
	int i;
	for(i=0; i<strlen(first) && i<strlen(second); i++){
		if(toupper(first[i])<toupper(second[i])){
			return 1;
		}
		else if(first[i]>second[i]){
			return 0;
		}
	}
	if(strcasecmp(first, second)<0){
		return 1;
	}
	return 0;
}