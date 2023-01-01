#include <bits/stdc++.h>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/GSS1/

int n;

struct data {
	int preMax;
	int sufMax;
	int sum;
	int ans;
};

data segtree[200001];

int arr[50001];


data merge(data left, data right) {
	data cur;
	cur.ans = max(max(left.ans, right.ans), left.sufMax + right.preMax);
	cur.sum = left.sum + right.sum;
	cur.preMax = max(left.preMax, left.sum + right.preMax);
	cur.sufMax = max(right.sufMax, right.sum + left.sufMax);

	return cur;
}

void buildTree(int node, int i, int j) {
	if (i > j) {
		return;
	}
	if (i == j) {
		data cur;
		cur.sum = arr[i-1];
		cur.sufMax = arr[i-1];
		cur.preMax = arr[i-1];
		cur.ans = arr[i-1];
		segtree[node] = cur;
		return;
	}

	int mid = (i+j)/2;
	buildTree(2*node, i, mid);
	buildTree(2*node + 1, mid+1, j);
	segtree[node] = merge(segtree[2*node], segtree[2*node + 1]);
}

data identity() {
	data t;
	t.sum = 0;
	t.ans = -1000000000;
	t.preMax = -1000000000;
	t.sufMax = -1000000000;
	return t;
}

data query(int node, int i, int j, int l, int r) {
	if (i > j || l > r || i > r || j < l) {
		return identity();
	}
	
	if (i >= l && j <= r) {
		return segtree[node];
	}
	int m = (i+j)/2;
	data a = query(2*node, i, m, l, r);
	data b = query(2*node + 1, m+1, j, l, r);
	data cur = merge(a, b);
	return cur;
	
}

int query(int i, int j, int n) {
	data x = query(1, 1, n, i, j);
	return x.ans;
}


int main() {
	
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i=0; i< n; i++) {
		cin >> arr[i];
	}
	buildTree(1, 1, n);
	int m;
	cin >> m;

	for (int i=0; i < m; i++) {
		int x, y;
		cin>>x>>y;

		cout << query(x, y, n) << endl;

	}

	return 0;
}
