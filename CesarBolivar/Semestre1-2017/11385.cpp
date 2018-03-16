// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int fib[] = {
	1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584,
	4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,
	514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352,
	24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437,
	701408733, 1134903170, 1836311903
};

int bsearch(int A[], int x, int l, int r) {
	int mid = (l + r)/2;
	if (l == r) {
		return mid;
	}
	else if (A[mid] > x) {
		bsearch(A, x, l, mid);
	}
	else {
		bsearch(A, x, mid+1, r);
	}
}

int main(int argc, char const* argv[])
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		string s;
		cin >> n;
		// cout << "n: " << n << endl;
		vector<int> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			// cout << v[j] << endl;
		}
		getline(cin, s);
		getline(cin, s);
		// cout << s << endl;
		// char s2[s.size()]; // Esto no deberia ser el largo del string original, ya que el fibonacci dado podria ser el ultimo del arreglo
		char s2[44]; // Esto no deberia ser el largo del string original, ya que el fibonacci dado podria ser el ultimo del arreglo
		// puts(s2);
		// string s2 = s;
		// memset(s2, ' ', s.size());
		memset(s2, ' ', 44);
		// fill(s2.begin(), s2.end(), ' ');
		int k = 0;
		int max_fib = 0;
		for (int j = 0; j < s.size(); j++) {
			// cout << "k: " << k << ", v.size(): " << v.size() << endl;
			if ('A' <= s[j] && s[j] <= 'Z' && k < v.size()) {
				// cout << "len: " << strlen(s2) << endl;
				max_fib = v[k] > max_fib ? v[k] : max_fib;
				// cout << j << ": " << s[j] << endl;
				int index = bsearch(fib, v[k], 0, 44);
				// cout << v[k] << " at " << index - 1 << endl;
				s2[index - 1] = s[j]; // no me convence el -1, pero funciona
				k++;
			}
		}
		int null_char_pos = bsearch(fib, max_fib, 0, 44);
		// cout << "k: " << null_char_pos << endl;
		// cout << "s2[5]: " << s2[5] << endl;
		// cout << strlen(s2) << endl;
		s2[null_char_pos] = '\0';
		puts(s2);
		// cout << s2 << endl;
	}
	return 0;
}
