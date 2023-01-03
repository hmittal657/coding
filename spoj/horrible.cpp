#include <iostream>
using namespace std;

// https://www.spoj.com/problems/HORRIBLE/

#define ll long long

int n;

ll segtree[400005];

ll lazy[400005];

void propagate(int node, int i, int j) {
	if (i > j) return;
	ll delta = (ll)(j) - (ll)(i) + 1L;
	delta *= lazy[node];
	segtree[node] += delta;
	if (i != j) {
		lazy[2*node] += lazy[node];
		lazy[2*node + 1] += lazy[node];
	}
	lazy[node] = 0;
}


void buildTree(int node, int i, int j) {
	if (i > j) return;
	if (i == j) {
		segtree[node] = 0;
		lazy[node] = 0;
		return;
	}
	ll mid = (i+j)/2;
	buildTree(2*node, i, mid);
	buildTree(2*node + 1, mid+1, j);
	segtree[node] = 0;
	lazy[node] = 0;
}

void update(int node, int i, int j, int l, int r, ll v) {
	if (lazy[node] > 0) {
		propagate(node, i, j);
	}
	if (i > j || l  > r || j < l || r < i) return;
	if (i >= l && j <= r) {
		ll delta = (ll)(j) - (ll)(i) + 1L;
		delta = delta * v;
		segtree[node] += delta;
		if (i != j) {
			lazy[2*node] += v;
			lazy[2*node + 1] += v;
		}
		return;
	}
	int mid = (i+j)/2;
	update(2*node, i, mid, l, r, v);
	update(2*node+1, mid+1, j, l, r, v);
	segtree[node] = segtree[2*node] + segtree[2*node + 1];
}

ll query(int node, int i, int j, int l, int r) {
	if (lazy[node] > 0) {
		propagate(node, i, j);
	}
	if (i > j || l  > r || j < l || r < i) return 0;
	if (i >= l && j <= r) {
		return segtree[node];
	}
	int mid = (i+j)/2;
	ll x = query(2*node, i, mid, l, r);
	ll y = query(2*node+1, mid+1, j, l, r);
	return (x+y);
}

int main() {

	int t;
	scanf("%d", &t);


	while (t > 0) {
		scanf("%d", &n);

		buildTree(1, 1, n);

		int q;
		scanf("%d", &q);

		for (int i =0; i < q; i++) {
			int x, y, z;
			scanf("%d", &x);

			scanf("%d", &y);

			scanf("%d", &z);

			if (x == 0) {
				ll v;
				scanf("%lld", &v);
				update(1, 1, n, y, z, v);
			} else {
				printf("%lld\n", query(1, 1, n, y, z));
			}
		}

		t--;
	}

	return 0;
}