#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class dictionaryWords{
public:
  dictionaryWords(string s);
  string showWord();
  string showSortedWord();

private:
  string word;
  string sortedWord;
  string sortWord();
};

dictionaryWords::dictionaryWords(string s){
  word = s;
  sortedWord = sortWord();
}

string dictionaryWords::showWord(){
    return(word);
}
string dictionaryWords::showSortedWord(){
    return(sortedWord);
}

string dictionaryWords::sortWord(){
  string aux = word;
  transform(aux.begin(), aux.end(), aux.begin(),(int (*)(int))tolower);
  std::sort(aux.begin(),aux.end());
  return(aux);
}



int main() {

    std::vector<dictionaryWords> dict;
    std::vector<dictionaryWords> ananagrams;
    string s;
    int i = 0;
    bool comp = false;

    while(true){
        cin >> s;
        if(s[0]!='#'){
            dict.push_back(dictionaryWords(s));
            i++;
        }else{
            break;
        }
    }
    
    for(i=0; i<dict.size();i++){
        for(int j=0; j<dict.size();j++){
            if((i!=j) && (dict[i].showSortedWord()==dict[j].showSortedWord())){
                comp = true;
            }
        }
        if(comp == false){
            ananagrams.push_back(dict[i]);
            
        } else{
            comp = false;
        }
    }
    
    for(i = 0; i<ananagrams.size();i++){
        for(int j=0; j<ananagrams.size();j++){
            
            if(ananagrams[i].showWord()<ananagrams[j].showWord() && i!=j){
                iter_swap(ananagrams.begin()+i,ananagrams.begin()+j);
            }
            
        }
    }

    for(i = 0; i<ananagrams.size();i++){
        
        cout << ananagrams[i].showWord() << endl;
    }
    
   return 0;
}