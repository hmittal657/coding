#include <iostream>
using namespace std;

// https://www.spoj.com/problems/GSS3/

struct data {
	int ans;
	int preMax;
	int sufMax;
	int sum;
};

int n;

int arr[50001];

data segtree[200001];

data merge(data left, data right) {
	data cur;
	cur.sum = left.sum + right.sum;
	cur.ans = max(max(left.ans, right.ans), left.sufMax + right.preMax);
	cur.preMax = max(left.preMax, left.sum + right.preMax);
	cur.sufMax = max(right.sufMax, right.sum + left.sufMax);
	return cur;
}

data identity() {
	data cur;
	cur.sum = 0;
	cur.ans = -1000000000;
	cur.preMax = -1000000000;
	cur.sufMax = -1000000000;
	return cur;
}

data getData(int val) {
	data res;
	res.ans = val;
	res.sum = val;
	res.sufMax = val;
	res.preMax = val;
	return res;
}

void update(int node, int i, int j, int ind, int val) {
	if (ind < i || ind > j) return;
	if (i == j) {
		segtree[node] = getData(val);
		return;
	}
	int m = (i+j)/2;
	update(2*node, i, m, ind, val);
	update(2*node + 1, m+1, j, ind, val);
	segtree[node] = merge(segtree[2*node], segtree[2*node + 1]);
}

void buildTree(int node, int i, int j) {
	if (i > j) return;
	if (i == j) {
		segtree[node] = getData(arr[i]);
		return;
	}

	int m = (i+j)/2;
	buildTree(2*node, i, m);
	buildTree(2*node + 1, m+1, j);

	segtree[node] = merge(segtree[2*node], segtree[2*node + 1]);

}

data query(int node, int i, int j, int l, int r) {
	if (i > j || l > r || i > r || l > j) {
		return identity();
	}

	if (i >= l && j <= r) {
		return segtree[node];
	}
	int m = (i+j)/2;
	data a = query(2*node, i, m, l, r);
	data b = query(2*node + 1, m+1, j, l, r);

	return merge(a, b);
}

void query(int l, int r) {
	data res = query(1, 1, n, l, r);
	cout << res.ans << endl;
}

int main() {

	cin >> n;

	for (int i =1; i <= n; i++) {
		cin>>arr[i];
	}

	int m;
	cin>>m;

	buildTree(1, 1, n);

	for (int i =0; i < m; i++) {
		int x, y, z;

		cin>>x>>y>>z;

		if (x == 0) {
			update(1, 1, n, y, z);
		} else {
			query(y, z);
		}
	}


	return 0;
}