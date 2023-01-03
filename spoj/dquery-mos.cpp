#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

struct query {
	int left;
	int right;
	int index;
};

int arr[30001];

int n;
int sqn;
int q;
query proc[200001];
int ans[200001];

static bool comp(query x, query y) {
	int a = x.left / sqn;
	int b = y.left / sqn;
	if (a != b) {
		return a < b;
	}
	return x.right < y.right;
}

void process() {
	unordered_map<int, int> m;
	query cur = proc[0];

	int l =  cur.left;
	int r = cur.right;

	for (int i = l; i <= r; i++) {
		m[arr[i]]++;
	}

	ans[cur.index] = m.size();

	int last_l = l;
	int last_h = r;

	for (int i = 1; i < q; i++) {
		cur = proc[i];
		l = cur.left;
		r = cur.right;
		if (l == r) {
			ans[cur.index] = 1;
			continue;
		}
		if (r > last_h) {
			for (int j = last_h + 1; j <= r ; j++) {
				m[arr[j]]++;
				if (m[arr[j]] == 0) {
					m.erase(arr[j]);
				}

			}
		} else if (r < last_h) {
			for (int j = r+1; j <= last_h ; j++) {
				m[arr[j]]--;
				if (m[arr[j]] == 0) {
					m.erase(arr[j]);
				}
			}
		}

		last_h = r;

		if (l < last_l) {
			for (int j = l; j < last_l ; j++) {
				m[arr[j]]++;

				if (m[arr[j]] == 0) {
					m.erase(arr[j]);
				}

			}
		} else if (l > last_l) {
			for (int j = last_l ; j < l ; j++) {
				m[arr[j]]--;
				if (m[arr[j]] == 0) {
					m.erase(arr[j]);
				}
			}
		}
		last_l = l;

		
		ans[cur.index] = m.size();
	}
}

static bool comp2(query x, query y) {
	return x.index <= y.index;
}

int main() {

	std::ios::sync_with_stdio(false);

	scanf("%d", &n);
	sqn = sqrt(n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	cin >> q;

	for (int i =0; i < q; i++) {
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);
		
		query z;
		z.left = x;
		z.right = y;
		z.index = i;
		proc[i] = z;

	}

	sort(proc, proc + q, comp);
	
	process();

	for (int i =0; i  < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}

/**
10
1 1 2 1 3 10 2 2 3 10
5
1 1
2 2
3 3
8 10
5 5

*/