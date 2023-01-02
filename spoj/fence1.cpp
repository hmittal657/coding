#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/FENCE1/

int main() {

	std::ios::sync_with_stdio(false);

	double l;
	double pi = 3.14159265359;

	while (true) {
		
		cin >> l;

		if (l == 0) break;

		double r = (l/pi);

		double area = (l*l)/(2.0 * pi);

		cout<<fixed<<setprecision(2)<<area<<endl;

	}

	return 0;
}