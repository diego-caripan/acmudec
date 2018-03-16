#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <ctype.h>
using namespace std;
/*
El problema consiste en encontrar la "entropia dle texto", que dada las formulas dadas, y las
condiciones especiales para cierto simbolos, se calcula,
*/
int main() {
    string s;
    //Lee hasta encontrar la palabra reservada END_OF_INPUT
    while(getline(cin, s)) {
        if(s.substr(0, 20) == "****END_OF_INPUT****")
            return 0;
        map<string, int> r;
        int lambda = 0;
        do {
            if(s == "****END_OF_TEXT****")
                break;
            int i, len = s.length();
            for(i = 0; i < len; i++) {
                if(!isalpha(s[i]))
                    continue;
                string word = "";
                int j(i);
                while(j < len) {
                    bool flag = false;
                    switch(s[j]) {
                        case ',':break;
                        case '.':break;
                        case ':':break;
                        case ';':break;
                        case '!':break;
                        case '?':break;
                        case '\"':break;
                        case '\t':break;
                        case '(':break;
                        case ')':break;
                        case ' ':break;
                        case '\n':break;
                        case EOF:break;
                        case '\0':break;
                        default:
                            if(isupper(s[j]))
                                s[j] += 32;
                            word += s[j];
                            flag = true;
                    }
                    if(!flag)
                        break;
                    j++;
                }
                //cout << word << endl;
                i = j;
                lambda++;
                r[word]++;
            }
        } while(getline(cin, s));
        double Et = 0, Emax = log10(lambda);
        for(map<string, int>::iterator it = r.begin(); it != r.end(); it++) {
            Et += it->second*(log10(lambda)-log10(it->second));
        }
        Et /= lambda;
        //si da 0 solo se ejecuta esto
        if(lambda == 0)
            puts("0 0.0 0");
        else
        //entropia != 0
            printf("%d %.1lf %.0lf\n", lambda, Et, Et*100/Emax);
    }
    return 0;
}