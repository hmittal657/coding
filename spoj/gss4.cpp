#include <iostream>
#include <cmath>
using namespace std;

// https://www.spoj.com/problems/GSS4/

#define ll long long

int n;
ll arr[100001];

struct data {
	ll sum;
};

ll root(ll x) {
	double a = (double)(x);
	a = pow(a, 0.5);
	return (ll)(a);
}

data segtree[400004];

data merge(data left, data right) {
	data res;
	res.sum = left.sum + right.sum;
	return res;
}

void buildTree(int node, int i, int j) {
	if (i > j) return;
	if (i == j) {
		segtree[node] = {arr[i]};
		return;
	}
	int m = (i+j)/2;
	buildTree(2*node, i, m);
	buildTree(2*node + 1, m+1, j);
	segtree[node] = merge(segtree[2*node],	segtree[2*node + 1]);
}

data query(int node, int i, int j, int l, int r) {
	if (i > j ||  l > r || i > r || l > j) {
		return {0};
	}

	if (i >= l && j <= r) {
		return segtree[node];
	}

	int m = (i+j)/2;
	data a = query(2*node, i, m, l, r);
	data b = query(2*node + 1, m+1, j, l, r);
	return merge(a, b);
}

void update(int node, int i, int j, int l, int r) {
	if (i > j || l > r || j < l || i > r) {
		return;
	}
	if (i == j) {
		segtree[node] = {root(segtree[node].sum)};
		return;
	}

	if (i >= l && j <= r) {
		if (segtree[node].sum == ((ll)(j) - (ll)(i) + 1)) {
			return;
		}
	}

	int m = (i+j)/2;
	update(2*node, i, m, l, r);
	update(2*node + 1, m+1, j, l, r);
	segtree[node] = merge(segtree[2*node], segtree[2*node + 1]);
}

ll query(int x, int y) {
	data res = query(1,1,n, x, y);
	return res.sum;
}

int main() {

	int ind = 0;

	while(scanf("%d", &n) != EOF) {
		ind++;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &arr[i]);
		}

		buildTree(1, 1, n);

		printf("Case #%d:\n", ind);
		
		int m;
		scanf("%d", &m);
		int x, y, z;
		for (int i =0; i < m; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			scanf("%d", &z);
			if (y > z) {
				swap(y, z);
			}
			if (x == 0) {
				update(1, 1, n, y, z);
			} else {
				printf("%lld\n", query(y, z));
			}
		}
		
		printf("\n");
	
	}


	return 0;
}