#include <iostream>
#include <vector>
using namespace std;

// https://www.spoj.com/problems/KQUERY/

struct data {
	vector<int> nums;
};

int n;

int arr[30001];

data segtree[120004];

data merge(data a, data b) {
	data c;
	vector<int> t;
	vector<int> v1 = a.nums;
	vector<int> v2 = b.nums;

	int i = 0; int j = 0;

	while (i < v1.size() && j < v2.size()) {
		if (v1[i] < v2[j]) {
			t.push_back(v1[i]);
			i++;
		} else {
			t.push_back(v2[j]);
			j++;
		}
	}

	while (i < v1.size()) {
		t.push_back(v1[i]);
		i++;
	}

	while (j < v2.size()) {
		t.push_back(v2[j]);
		j++;
	}
	c.nums  = t;
	return c;
}

void buildTree(int node, int i, int j) {
	if (i > j) return;
	if (i == j) {
		data cur;
		cur.nums = vector<int>(1, arr[i]);
		segtree[node] = cur;
		return;
	}

	int m = (i+j)/2;
	buildTree(2*node, i, m);
	buildTree(2*node + 1, m+1, j);

	segtree[node] = merge(segtree[2*node], segtree[2*node + 1]);
}

int query(int node, int i, int j, int l, int r, int k) {
	if (i > j || l > r || j < l || i > r) return 0;
	
	if (i >= l && j <= r) {
		vector<int> cur = segtree[node].nums;
		int low = 0;
		int high = cur.size() - 1;

		if (k < cur[0]) {
			return cur.size();
		}
		if (k > cur[high]) {
			return 0;
		}

		int res = cur.size();

		while (low <= high) {
			int mid = (low + high)/2;
			if (cur[mid] <= k) {
				low = mid+1;
			} else {
				res = min(mid, res);
				high = mid-1;
			}
		}

		return (cur.size() - res);
	}

	int m = (i + j)/2;
	int x = query(2*node, i, m, l, r, k);
	int y = query(2*node + 1, m+1, j, l, r, k);

	return (x+y);

}

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	buildTree(1, 1, n);

	int q;
	scanf("%d", &q);

	for (int i=0; i < q; i++) {
		int x, y, z;
		scanf("%d", &x);
		scanf("%d", &y);
		scanf("%d", &z);
		printf("%d\n", query(1, 1, n, x, y, z));
	}


	return 0;
}