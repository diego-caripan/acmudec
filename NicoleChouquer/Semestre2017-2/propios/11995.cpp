#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>

using namespace std;

int main(){

vector<int> bag;
stack<int> empty;
queue<int> empty2;
stack<int> bagstack;
queue<int> bagqueue;
vector<int> bagpriority;
vector<int> taken;
vector<int> stacktaken;
vector<int> queuetaken;
vector<int> priortaken;

int n, comp=0;
bool stack=false, queue=false, priority=false;
int command, value;



 while(true){

    cin >> n;
   if(cin.eof()){
      break;
    }
    

    for(int i=0; i<n; i++){
      cin >> command >> value;

      if(command==1){
        bag.push_back(value);
        bagstack.push(value);
        bagqueue.push(value);
        bagpriority.push_back(value);
      } else if(command==2){
        taken.push_back(value);
        if(bagstack.empty()==false){
          stacktaken.push_back(bagstack.top());
          bagstack.pop();
        }
        if(bagqueue.empty()==false){
          queuetaken.push_back(bagqueue.front());
          bagqueue.pop();
        }
        if(bagpriority.empty()==false){
          priortaken.push_back(*max_element(bagpriority.begin(),bagpriority.end()));
          bagpriority.erase(max_element(bagpriority.begin(),bagpriority.end()));
        }        

      }

      

    }
  
    if(taken==stacktaken){
      comp++;
      stack=true;
    }
    if(taken==queuetaken){
      comp++;
      queue = true;
    }
    if(taken==priortaken){
      comp++;
      priority = true;
    }

  
    if(comp==0){
      printf("impossible\n");
      
    } else if(comp>1){
      printf("not sure\n");
    } else{
      if(stack==true){
        printf("stack\n");
      } else if(queue==true){
        printf("queue\n");
      } else if(priority==true){
        printf("priority queue\n");
      }
    }
   
   bag.clear();
   bagstack = empty;
   bagqueue = empty2;
   bagpriority.clear();
   taken.clear();
   stacktaken.clear();
   queuetaken.clear();
   priortaken.clear();
   comp = 0;
   stack = false;
   queue = false;
   priority = false;

   
    
 }
  
  return 0;
}