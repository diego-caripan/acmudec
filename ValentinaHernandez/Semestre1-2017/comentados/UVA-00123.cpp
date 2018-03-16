/*
COMENTADO
https://github.com/morris821028/UVa/blob/master/volume001/123%20-%20Searching%20Quickly.cpp
*/
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <cctype>
using namespace std;
const int kMaxn(207);
const string kSign("::");

int main()
{
    /*
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    //*/

    set<string> ignore; //strings a ignorar
    string t;
    while(getline(cin,t) && t!=kSign)
        ignore.insert(t);
    multimap<string,string> r;
    while(getline(cin,t))
    {
        for(int i=0;i<t.size();i++)
            t[i]=tolower(t[i]); // letras minusculas
        for(int i=0;i<t.size();i++)
        {
            if(!isalpha(t[i])) //si no es una letra, se salta lo siguiente
                continue;
            int j(i);
            string t2;
            while(j<t.size() && isalpha(t[j]))
            {
                t2+=t[j]; //se forma la palabra
                j++;
            }
            if(!ignore.count(t2))
            {
                for(int k=0;k<t2.size();k++)
                    t2[k]=toupper(t2[k]); //se pone en mayuscula si no es a ignorar
                string t3(t);//se copia t en t3
                t3.replace(i,t2.size(),t2);//se copia el string que sirve
                r.insert(make_pair(t2,t3));//se agrega el par al mapa
            }
            i=j;
        }
    }

    for(map<string,string>::iterator i=r.begin();i!=r.end();i++)
        cout<<i->second<<endl;

    return 0;
}