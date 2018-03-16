#include <stdio.h>
#include <stdlib.h>

int main(){

	char c = 'a';

	//nota: 0 diamonds, 1 spades, 2 hearts, 3 clubs

	int suits[4];
	for(int i=0; i<4; i++){
		suits[i] = 0;
	}

	int score = 0;

	int stopped = 0;
	int trumpbid = 0;

	int dking = 0, dqueen = 0, djack = 0, dace = 0;
	int sking = 0, squeen = 0, sjack = 0, sace = 0;
	int hking = 0, hqueen = 0, hjack = 0, hace = 0;
	int cking = 0, cqueen = 0, cjack = 0, cace = 0;


	char mano[13][2];

	while(1){

		for(int i=0; i<13; i++){
			scanf("%s",mano[i]);
		}

		//paso 1

		for(int j=0; j<13; j++){

			if(mano[j][0]=='A'){

				score += 4;
			} else if(mano[j][0]=='K'){

				score += 3;

			} else if(mano[j][0]=='Q'){

				score += 2;

			} else if(mano[j][0]=='J'){

				score += 1;

			} 

		}

		// paso 2

		for(int n=0; n<13; n++){


			if(mano[n][1]=='D'){

				suits[0]++;

				if(mano[n][0]=='K'){
					dking++;
				} else if(mano[n][0]=='Q'){
					dqueen++;
				} else if(mano[n][0]=='J'){
					djack++;
				} else if(mano[n][0]=='A'){
					dace++;
					
				}

			} else if(mano[n][1]=='S'){

				suits[1]++;

				if(mano[n][0]=='K'){
					sking++;
				} else if(mano[n][0]=='Q'){
					squeen++;
				} else if(mano[n][0]=='J'){
					sjack++;
				} else if(mano[n][0]=='A'){
					sace++;
					
				}

			} else if(mano[n][1]=='H'){

				suits[2]++;

				if(mano[n][0]=='K'){
					hking++;
				} else if(mano[n][0]=='Q'){
					hqueen++;
				} else if(mano[n][0]=='J'){
					hjack++;
				} else if(mano[n][0]=='A'){
					hace++;
					
				}

			} else if(mano[n][1]=='C'){

				suits[3]++;

				if(mano[n][0]=='K'){
					cking++;
				} else if(mano[n][0]=='Q'){
					cqueen++;
				} else if(mano[n][0]=='J'){
					cjack++;
				} else if(mano[n][0]=='A'){
					cace++;
					
				}

			}


		}

		if(dking>0&&suits[0]<2){
			score--;
		}
		if(dqueen>0&&suits[0]<3){
			score--;
		}
		if(djack>0&&suits[0]<4){
			score--;
		}

		if(sking>0&&suits[1]<2){
			score--;
		}
		if(squeen>0&&suits[1]<3){
			score--;
		}
		if(sjack>0&&suits[1]<4){
			score--;
		}
		if(hking>0&&suits[2]<2){
			score--;
		}
		if(hqueen>0&&suits[2]<3){
			score--;
		}
		if(hjack>0&&suits[2]<4){
			score--;
		}
		if(cking>0&&suits[3]<2){
			score--;
		}
		if(cqueen>0&&suits[3]<3){
			score--;
		}
		if(cjack>0&&suits[3]<4){
			score--;
		}

		//paso 3 (calcular stopped suits y si aplica trumpbid)

		if( (dace>0) || (dking>0&&suits[0]>1) ||(dqueen>0&&suits[0]>2)){
			stopped++;
		}

		if( (sace>0) || (sking>0&&suits[1]>1) ||(squeen>0&&suits[1]>2)){
			stopped++;
		}

		if( (hace>0) || (hking>0&&suits[2]>1) ||(hqueen>0&&suits[2]>2)){
			stopped++;
		}

		if( (cace>0) || (cking>0&&suits[3]>1) ||(cqueen>0&&suits[3]>2)){
			stopped++;
		} 


		if(score>15&&stopped==4){
			trumpbid = 1;
		}

		//paso : score + por num de cartas de un palo en la mano

		if(suits[0]==2){
			score++;
		}
		if(suits[1]==2){
			score++;
		}
		if(suits[2]==2){
			score++;
		}
		if(suits[3]==2){
			score++;
		}

		if(suits[0]==1||suits[0]==0){
			score+= 2;
		}
		if(suits[1]==1||suits[1]==0){
			score+= 2;
		}
		if(suits[2]==1||suits[2]==0){
			score+= 2;
		}
		if(suits[3]==1||suits[3]==0){
			score+= 2;
		}



		//resultado

		int mayor = -1;

		if(score<14){
			printf("PASS\n");
		} else if(trumpbid){
			printf("BID NO-TRUMP\n");
		} else{

			for(int i=0; i<4; i++){
				if(suits[i]>mayor){
					mayor = suits[i];
				}
			}

			if(suits[1]==mayor){
				printf("BID S\n");
			} else if(suits[2]==mayor){
				printf("BID H\n");
			} else if(suits[0]==mayor){
				printf("BID D\n");
			} else {
				printf("BID C\n");
			}

		}


	
	for(int i=0; i<4; i++){
		suits[i] = 0;
	}

	score = 0;

	stopped = 0;
	trumpbid = 0;

	dking = 0;
	dqueen = 0;
	djack = 0;
	dace = 0;
	sking = 0;
	squeen = 0;
	sjack = 0;
	sace = 0;
	hking = 0;
	hqueen = 0;
	hjack = 0;
	hace = 0;
	cking = 0;
	cqueen = 0;
	cjack = 0;
	cace = 0;

	c = getchar();
	c = getchar();
	if(c==EOF){
		break;
	} else{
		ungetc(c, stdin);
	}

	} 


	




	return(0);
}