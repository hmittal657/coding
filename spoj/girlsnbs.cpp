#include <iostream>
using namespace std;

// https://www.spoj.com/problems/GIRLSNBS/

int solve(int g, int b) {
	if (g == 0) return b;
	if (b == 0) return g;
	if (g == b) return 1;

	int x = max(g, b);
	int y = min(g, b);

	y++;
	
	int q = x/y;
	int r = x%y;

	if (r  > 0) {
		q++;
	}

	return q;

}

int main() {

	int g, b;

	while (true) {
		scanf("%d", &g);
		scanf("%d", &b);

		if (g == -1 && b == -1) break;

		cout << solve(g, b) << endl;
	}
	return 0;
}