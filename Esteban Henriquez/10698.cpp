 #include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

#define leapYear(year) (((year%4==0)&&(year%100!=0))||(year%400==0))
#define validMove(x,y) ((x>=0 && x<row) && (y>=0 && y<col))
#define mod(n,m) (!(n%m))
#define bit(n,m) (n&m?1:0)
#define REP(i,a) for(__typeof(a) i=0;i<a;i++)
#define FOR(i,a,b) for(__typeof(a) i=a;i<=b;i++)
#define SET(t) memset((t),0,sizeof(t))

#define INF 1000000
#define LIMIT 11
#define MASK 64
#define SIZE 26

typedef long long int int64;
typedef struct {
    int x,y;
}Point;
bool compare(int a,int b) {
    return a<b;
}
using namespace std;

int fx[]={0,0,1,-1,-1,1,-1,1}; // eje x
int fy[]={1,-1,0,0,1,1,-1,-1}; // eje y
struct TEAM {                              // crea estructuras tipo TEAM
    string name,lower_name;
    int points,played,scored,against;
    float percentage;
   
    TEAM() {
        name="";
        points=played=scored=against=0;  //las rellena
        percentage=0.0;
    }
   
    void into_lower() {
        REP(i,name.size()) {
            lower_name+=tolower(name[i]);
        }
    }
   
    bool operator < (const TEAM& b) const {
        if(points!=b.points) return points>b.points;
        if((scored-against)!=(b.scored-b.against)) return (scored-against)>(b.scored-b.against);
        if(scored!=b.scored) return scored>b.scored;
       
        return lower_name<b.lower_name;
    }
};

int main() {
    int t,m;
    bool flag=true;
    
   
    while(cin>>t>>m) {
        if(!(t+m)) break;
        if(flag) {
            flag=false;
        } else printf("\n");
        vector<TEAM> team_list;
        map<string,int> mapping;
       
        REP(i,t) {
            string name;
            cin >> name;
            mapping[name]=i;
            TEAM temp;
            temp.name=name;
            temp.into_lower();
            team_list.push_back(temp);
        }
       
        string team1,team2;
        char hyphen;
        int goal1,goal2;
       
        REP(i,m) {
            cin >> team1 >> goal1 >> hyphen >> goal2 >> team2;
            team_list[mapping[team1]].played++;
            team_list[mapping[team1]].scored+=goal1;
            team_list[mapping[team1]].against+=goal2;
            team_list[mapping[team1]].points+=((goal1>goal2?3:0)+(goal1==goal2?1:0));
           
            team_list[mapping[team2]].played++;
            team_list[mapping[team2]].scored+=goal2;
            team_list[mapping[team2]].against+=goal1;
            team_list[mapping[team2]].points+=((goal1<goal2?3:0)+(goal1==goal2?1:0));
        }
       
        sort(team_list.begin(),team_list.end());
       
        REP(i,team_list.size()) {
            if(team_list[i].played==0) continue;
            int te,mp;
            te=team_list[i].played;
            mp=team_list[i].points;
            team_list[i].percentage=(100.00*mp)/(te*3);
        }
       
        int rank=0;
        REP(i,team_list.size()) {
            int scored,against,diff;
            scored=team_list[i].scored,against=team_list[i].against;
            diff=scored-against;
            if(i==0) {
                rank=i+1;
                printf("%2d.",rank);
            } else if(team_list[i].points!=team_list[i-1].points || (team_list[i].scored-team_list[i].against)!=(team_list[i-1].scored-team_list[i-1].against) || team_list[i].scored!=team_list[i-1].scored) {
                rank=i+1;
                printf("%2d.",rank);
            } else {
                printf("   ");
            }
            printf("%16s%4d%4d%4d%4d%4d",team_list[i].name.c_str(),team_list[i].points,team_list[i].played,scored,against,diff);
            if(team_list[i].played==0) {
                printf("%7s\n","N/A");
                continue;
            }
            printf("%7.2f\n",team_list[i].percentage);
        }
    }
   
    return 0;
}
