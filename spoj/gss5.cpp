#include <iostream>
using namespace std;

// https://www.spoj.com/problems/GSS5/

struct data {
	int ans;
	int preMax;
	int sufMax;
	int sum;
};

int n;
int arr[10001];

data segtree[40005];

data getData(int x) {
	data res;
	res.ans = x;
	res.preMax = x;
	res.sufMax = x;
	res.sum = x;
	return res;
}

data merge(data left, data right) {
	data res;
	res.sum = left.sum + right.sum;
	res.preMax = max(left.preMax, left.sum + right.preMax);
	res.sufMax = max(right.sufMax, right.sum + left.sufMax);
	res.ans = max(max(left.ans, right.ans), left.sufMax + right.preMax);
	return res;
}

void buildTree(int node, int i, int j) {
	if (i > j) {
		return;
	}

	if (i == j) {
		segtree[node] = getData(arr[i]);
		return;
	}

	int m = (i+j)/2;
	buildTree(2*node, i, m);
	buildTree(2*node + 1, m+1, j);
	segtree[node] = merge(segtree[2*node], segtree[2*node + 1]);
}

data identity() {
	data cur;
	cur.sum = 0;
	cur.ans = -1000000000;
	cur.preMax = -1000000000;
	cur.sufMax = -1000000000;
	return cur;
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


void solve(int x1, int y1, int x2, int y2) {
	int res;

	if (x1 == x2 && y1 == y2) {
		data temp = query(1, 1, n, x1, y1);
		res = temp.ans;
		cout << res << endl;
		return;
	}

	if (x2 > y1) {
		data lefty = query(1, 1, n, x1, y1);
		data righty = query(1, 1, n, x2, y2);
		data sumy = query(1, 1, n, y1 + 1, x2 - 1);
		res = sumy.sum + lefty.sufMax + righty.preMax;
	} else if (x2 == y1) {
		data lefty = query(1, 1, n, x1, y1);
		data righty = query(1, 1, n, x2+1, y2);
		res = lefty.sufMax;
		res = max(res, lefty.sufMax + righty.preMax);
	} else if (x2 > x1 && y2 > y1) {
		data temp = query(1, 1, n, x2, y1);
		res = temp.ans;

		data lefty = query(1, 1, n, x1, y1);
		res = max(res, lefty.sufMax);
		
		data righty = query(1, 1, n, x2, y2);
		res = max(res, righty.preMax);

		data left1 = query(1, 1, n, x1, x2-1);
		res = max(res, left1.sufMax + temp.preMax);

		data right1 = query(1, 1, n, y1+1, y2);
		res = max(res, right1.preMax + temp.sufMax);

		temp = query(1, 1, n, x2+1, y1-1);
		lefty = query(1,1, n, x1, x2);
		righty = query(1, 1, n, y1, y2);

		res = max(res, temp.sum + lefty.sufMax + righty.preMax);
	} else if (x2 > x1 && y1 == y2) {
		data temp = query(1,1, n, x2, y1);
		res = temp.ans;
		data lefty = query(1, 1, n, x1, x2-1);
		res = max(res, lefty.sufMax + temp.preMax);
	} else if (x2 == x1 && y2 > y1) {
		data temp = query(1, 1, n, x1, y1);
		res = temp.ans;
		data righty = query(1, 1, n, y1 + 1, y2);
		res = max(res, righty.preMax + temp.sufMax);
	} else {
		data temp = query(1, 1, n, x1, y1);
		res = temp.ans;
	}

	cout << res << endl;
}

int main() {

	std::ios::sync_with_stdio(false);

	int t;

	cin >> t;

	while (t > 0) {

		cin>>n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		buildTree(1, 1, n);
		int m;
		cin>>m;

		for (int i=0; i < m; i++) {
			int x1, x2, y1, y2;
			cin>>x1>>y1>>x2>>y2;
			solve(x1, y1, x2, y2);
		}


		t--;
	}

	return 0;
}
