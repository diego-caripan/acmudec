#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
  return b == 0 ? a : gcd(b, a % b);
}

int main(){
  //char a[10], b_[10], c_[10];
  //  int a, b = -1, c = -1;
  long long int r, s, x, y;
  int a;
  long long int b = 0, c = 0, i, blen, clen;
  string str;
  bool minus = false;
  while(cin >> str){
    minus = false;
    if(str[0] == '-') minus = true;
    int dot = -1, open = -1, close = -1;
    for(i = 0; i < str.length(); i++){
      if(str[i] == '.') {dot = i; continue;}
      if(str[i] == '(') {open = i;continue;}  
      if(str[i] == ')') {close = i; continue;}
    }
    //cout << "a:" << dot << " " << open << " " << close << endl;
    char array[20];
  
    int limit = (dot != -1) ? dot: str.length();
    for(i = 0; i < limit; i++)
      array[i] = str[i];
    array[i] = 0;
    a = atoi(array);
    if(a < 0) a *= -1;
    if(dot != -1) {
      limit = (open != -1) ? open : str.length();
      blen = 0;
      for(i = dot + 1; i < limit; i++){
	array[i - (dot + 1)] = str[i];
	//cout << "a"<< str[i] << array[i - dot + 1] << " idx" << i - dot + 1<< endl;;
	blen++;
      }
      array[i - (dot + 1)] = 0;
      //cout << array << "qwdf" << endl;
      b = atoi(array);

    }else {b = 0; blen = 0;}
    
    if(open != -1){
      clen = 0;
      for(i = open + 1; i < close; i++){
	array[i - (open + 1)] = str[i];
	clen++;
      }
      array[i - (open + 1)] = 0;
      c = atoi(array);
      
    }else{c = 0; clen = 0;}
    /*
    cout << open << endl;
    cout << "a:" << dot << " " << open << " " << close << endl;
    cout << a << " " << b << " (" << blen << ") " << c <<  " (" << clen << ")"<< endl;
    cout << array << endl;
    cout << str << endl;
    */
    //cout << a << " " << b << " (" << blen << ") " << c <<  " (" << clen << ")"<< endl;

    
    r = (clen == 0) ? 1: (long long int)(pow(10, clen) - 1);
    s = (blen == 0) ? 1: (long long int)(pow(10, blen));
    x = b * r + c;
    y = r * s;

    //cout << "r: " << r << " s: " << s << endl;

    //    cout << "x, y, r, s: " << x << " " << y << " " << r << " " << s << endl;

    int gcd_ = gcd(x, y);
    x = x / gcd_;
    y = y / gcd_;
    if(minus) cout << "-";
    if(x == y){ a++; x = 0;}
    if(a != 0) cout << a;
    if(a != 0 && x != 0) cout << " ";
    if(x != 0) cout << x << "/" << y;
    if(a == 0 && x == 0) cout << 0;;
    cout << endl;
    a = 0; b = 0; c = 0;
  }
}
