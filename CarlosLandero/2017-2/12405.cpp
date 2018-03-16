#include <iostream>

using namespace std;

int main(){
    int T,caso;
    cin >> T;
    caso=1;
    while(T>0){
        int N,fertil=0,infertil=0;
        int scarecrows=0,e=0;
        cin >> N;
        char field[N];
        for(int i=0;i<N;i++){
            cin >> field[i];
            if(field[i]=='.'){
                fertil++;
            }
            else if(field[i]=='#'){
                infertil++;
            }
        }
        while(N-e >= 3){
           if(field[e]=='#'){
            e++;
            }
            else if(field[e]=='.'){
                scarecrows++;
                e += 3;
            }
        }
            if(N-e == 2){
                if(field[e]=='#'){
                    e++;
                }
                else{
                    scarecrows++;
                    e += 2;
                }
            }
            if(N-e == 1){
                if(field[e]=='#'){
                    e++;
                }
                else{
                    scarecrows++;
                    e++;
                }
            }
            cout << "Case " << caso << ": "<< scarecrows << endl;
        
        caso++;
        T--;
    }
    return 0;
}
