#include <bits/stdc++.h>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/ARMY/

int main() {

	std::ios::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t > 0) {
		int ng,  nm;
		cin>>ng>>nm;

		int maxng = INT_MIN;
		int maxnm = INT_MIN;

		for (int i =0; i < ng; i++) {
			int x;
			cin>>x;
			maxng = max(maxng, x);
			

		}

		for (int i = 0; i < nm; i++) {
			int x;
			cin>>x;
			maxnm = max(maxnm, x);
			
		}

		if (maxng >= maxnm) {
			cout << "Godzilla" << endl;
		} else {
			cout << "MechaGodzilla" << endl;
		}

		t--;
	}

	return 0;
}
