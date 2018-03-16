#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define MAX_DAYS 7

double days[MAX_DAYS];

int main() {
  while(cin >> days[0]) {
    for(int i = 1; i < MAX_DAYS; i++) {
      cin >> days[i];
    }

    int nextWeek[MAX_DAYS] = {0};
    double nextWeek2[MAX_DAYS] = {0};

    for(int i = 0; i < MAX_DAYS; i++) {
      if(days[i] == 1) {
	int n1 = (i + 1) % MAX_DAYS;
	int n2 = (i + 2) % MAX_DAYS;
	
	nextWeek[n1] += 60000;
	nextWeek[n2] += 40000;
	nextWeek2[n1] += 0.6;
	nextWeek2[n2] += 0.4;
      }
    }

    double sum = 0;
    double sum2 = 0;
    for(int i = 0; i < MAX_DAYS; i++) {
      sum += nextWeek[i]/10000;
      sum2 += nextWeek2[i];
    }
    sum /= 10;

    for(int i = 0; i < MAX_DAYS; i++) {
      if(sum > 0) {
	nextWeek[i] /= sum;
	nextWeek2[i] /= sum2;
      }
    }
    
    for(int i = 0; i < MAX_DAYS; i++) {
      //printf("%d ", nextWeek[i] );
      
      //unsigned int n = (unsigned int)(nextWeek[i] * 10000);
      int n = nextWeek[i];
      //if(n % 10 != 0) n++;
      //n /= 10;
      int num = 0;
      while(n != 0 && n % 10 == 0){
	n /= 10;
	num++;
      }
      //printf("%d(%d) ", n, num);
      
      if( nextWeek2[i] == 0) printf("0");
      else if(num == 4) printf("%.1f", nextWeek2[i]);
      else if(num == 3) printf("%.2f", nextWeek2[i]);
      else if(num == 2) printf("%.3f", nextWeek2[i]);
      else if(num == 0 || num == 1) printf("%.4f", nextWeek2[i]);
      //p/rintf(" (%d)", num);
      /*
      // double n = nextWeek[i];
      */
      if(i < MAX_DAYS - 1)
	printf(" ");
      
      // printf("%.4f ", nextWeek[i]);
    }
   
    printf("\n");
  }

  return 0;
}
