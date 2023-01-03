#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// https://www.spoj.com/problems/PPATH/

bool primes[10001];

int dist[10001];

bool solved = false;

void dfs(int a, int cur, int dest) {
	if (solved) return;
	vector<int> digits;

	int temp = a;
	while (temp > 0) {
		digits.push_back(temp%10);
		temp = temp/10;
	}
	
	vector<int> v;
	
	for (int k = 0; k < 4; k++) {
		int r = digits[k];
		int mul = pow(10, k);
		if (k == 0) {
		for (int j = 2; j <= r; j+=2) {
			int next = a - (j*mul);
			if (next >= 1000 && next <= 9999 && !primes[next]) {
				v.push_back(next);
			}
		}
		for (int j = 2; j < (10-r); j+=2) {
			int next = a + (j*mul);
			if (next >= 1000 && next <= 9999 && !primes[next]) {
				v.push_back(next);
			}
		}
		} else {
			for (int j = 1; j <= r; j++) {
			int next = a - (j*mul);
			if (next >= 1000 && next <= 9999 && !primes[next]) {
				v.push_back(next);
			}
			}
			for (int j = 1; j < (10-r); j++) {
				int next = a + (j*mul);
				if (next >= 1000 && next <= 9999 && !primes[next]) {
					v.push_back(next);
				}
		}
		}
	}

	vector<int> v2;
	for (int i = 0; i < v.size(); i++) {
		if (dist[v[i]] > cur+1) {
			v2.push_back(v[i]);
			dist[v[i]] = cur+1;
		}
	}

	for (int i = 0; i < v2.size(); i++) {
		dfs(v2[i], cur+1, dest);
	}
}

int main() {

	primes[1] = true;
	int count = 0;

	for (int i = 2; i < 10001; i++) {
		if (primes[i] == false) {
			for (int j = i*i ; j < 10001 ; j+=i) {
				primes[j] = true;
			}
		}
	}	
	
	int t;
	scanf("%d", &t);

	while (t > 0) {
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);

		if (a == b) {
			printf("0\n");
		} else {
			solved = false;
			for (int i = 1001; i <= 9999; i+=2) {
				dist[i] = 1061;
			}
			dist[a] = 0;
			dfs(a, 0, b);
			if (dist[b] != 1061) {
				printf("%d\n", dist[b]);
			} else {
				printf("Impossible\n");
			}
		}
		t--;
	}

	return 0;
}