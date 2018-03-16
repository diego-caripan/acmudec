#include <iostream>
#include <iomanip>

using namespace std;


int main() {

	int m, d;
	double p, c, meses[102][2], dactual, aactual;
	int md = 0;

	while (cin >> m  ) {
		md = 0;
		if (m < 0 )
			break;
		cin >> p >> c >> d;

		for (int j = 0; j < 102; j++) {
			meses[j][0] = -1;
			meses[j][1] = -1;
		}

		for (int i = 0; i < d; i++) {
			cin >> meses[i][0] >> meses[i][1];
		}

		double depreciacion = meses[0][1];
		dactual = c;
		aactual = c + p;
		p = c / (double)m;
		int y = 1;

		while (1) {

			if (md == meses[y][0]) {
				depreciacion =  meses[y++][1];
			}

			if (md != 0 )
				dactual -= p;
			if (dactual < 0)
				dactual = 0;

			aactual = aactual - (aactual * depreciacion);

			if (dactual < aactual - 1e-10)
				break;
			md++;
		}

		if (md == 1)
			cout << md << " month\n";
		else
			cout << md << " months\n";

	}


}