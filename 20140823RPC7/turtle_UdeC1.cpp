#include <iostream>
#include <stack>
using namespace std;
#define mod 1000003

int main(){
  int T;
  string str;
  cin >> T;
  while(T--){
    unsigned long long int l = 0, r = 0, f = 0, n;
    stack <int> S;
    S.push(1);
    cin >> str;
    while(cin >> str){
      if(str == "end") break;
      
      if(str == "left"){
	cin >> n;
	l += (n*S.top() % mod) % mod;
      }
      else if(str == "right"){
	cin >> n;
	r += (n*S.top() % mod) % mod; 
      }
      else if(str == "forward"){
	cin >> n;
	f+= (n*S.top() % mod) % mod; 
      }
      else if(str == "repeat"){
	cin >> n;
	S.push((n*S.top() % mod) % mod);
	cin >> str;
      }
      else if(str == "]"){
	S.pop();
      }
      
    }
    cout << l % mod << " " << r % mod << " " << f % mod << endl;
    l = r = f = 0;
  }
}
