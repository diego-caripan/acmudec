#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main(int argc, char const* argv[])
{
	int n, m;
	for (cin >> n >> m; n != 0 || m != 0; cin >> n >> m) {
		vi dragon(n), knight(m);
		for (int i = 0; i < n; i++) {
			cin >> dragon[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> knight[i];
		}
		sort(dragon.begin(), dragon.end());
		sort(knight.begin(), knight.end());
		int gold = 0;
		int i, j;
		for (i = 0, j = 0; i < n && j < m; ) {
			if (dragon[i] <= knight[j]) {
				i++;
				gold += knight[j];
			}
			j++;
		}
		if (i == n) {
			cout << gold << endl;
		}
		else {
			cout << "Loowater is doomed!" << endl;
		}
	}

	return 0;
}
