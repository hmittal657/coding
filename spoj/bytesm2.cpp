#include <iostream>
using namespace std;

// https://www.spoj.com/problems/BYTESM2/

int main() {
	int t;
	scanf("%d", &t);

	while (t > 0) {
		int m, n;
		scanf("%d", &m);
		scanf("%d", &n);

		vector<int> f(n, 0);
		vector<int> s(n, 0);

		int ans = 0;

		for (int j =0; j < n; j++) {
			scanf("%d", &f[j]);
			ans = max(ans, f[j]);
		}

		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				s[j]  = f[j] + x;
				if (j - 1 >= 0) {
					s[j] = max(s[j], f[j-1] + x);
				}
				if (j + 1 < n) {
					s[j] = max(s[j], f[j+1] + x);
				}
				ans = max(ans, s[j]);
			}

			for (int j = 0; j < n; j++) {
				f[j] = s[j];
			}
		}

		printf("%d\n", ans);

		t--;
	}

	return 0;
}