// UVa 417 - Word Index

#include <iostream>
#include <map>
#include <string>
using namespace std;

#define datatype unsigned long int

int main() {

	// Se hace el mapeo para los valores 
	// map['a'] = 1
	// map['b'] = 2
	// .. map['ab'] = 26
	// .. map['vwxyz'] = 83681

	map<string, datatype> map;
	datatype c = 1;
	string st = "0";
	for (int i = 0; i < 26; i++) {
		st[0] = i + 'a';
		map[st] = c++;
	}
	st = "00";
	for (int i = 0; i < 26; i++) {
		st[0] = i + 'a';
		for (int j = i + 1; j < 26; j++) {
			st[1] = j + 'a';
			map[st] = c++;
		}
	}
	st = "000";
	for (int i = 0; i < 26; i++) {
		st[0] = i + 'a';
		for (int j = i + 1; j < 26; j++) {
			st[1] = j + 'a';
			for (int k = j + 1; k < 26; k++) {
				st[2] = k + 'a';
				map[st] = c++;
			}
		}
	}
	st = "0000";
	for (int i = 0; i < 26; i++) {
		st[0] = i + 'a';
		for (int j = i + 1; j < 26; j++) {
			st[1] = j + 'a';
			for (int k = j + 1; k < 26; k++) {
				st[2] = k + 'a';
				for (int l = k + 1; l < 26; l++) {
					st[3] = l + 'a';
					map[st] = c++;
				}
			}
		}
	}
	st = "00000";
	for (int i = 0; i < 26; i++) {
		st[0] = i + 'a';
		for (int j = i + 1; j < 26; j++) {
			st[1] = j + 'a';
			for (int k = j + 1; k < 26; k++) {
				st[2] = k + 'a';
				for (int l = k + 1; l < 26; l++) {
					st[3] = l + 'a';
					for (int m = l + 1; m < 26; m++) {
						st[4] = m + 'a';
						map[st] = c++;
					}
				}
			}
		}
	}

	// Se busca en el mapa
	while (cin >> st)
		cout << map[st] << endl;

	return 0;
}