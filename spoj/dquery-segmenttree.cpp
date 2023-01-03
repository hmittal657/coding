#include <iostream>
#include <algorithm>
 
using namespace std;
 
struct  query {
	int index;
	int left;
	int right;
};
 
int segtree[240005];
 
query proc[200001];
 
int ans[200001];
 
int arr[30001];
 
int last[1000001];
 
static bool comp(query x, query y) {
	return x.right < y.right;
}
 
void buildTree(int node, int i, int j) {
	if (i > j) return;
	if (i == j) {
		segtree[node] = 0;
		return;
	}
	int mid = (i+j)/2;
	buildTree(2*node, i, mid);
	buildTree(2*node + 1, mid+1, j);
	segtree[node] = 0;
}
 
void update(int node, int i, int j, int ind, int val) {
	if (i  > j) return;
	if (i > ind || ind > j) return;
	if (i == j) {
		segtree[node] += val;
		return;
	}
	int mid = (i+j)/2;
	update(2*node, i, mid, ind, val);
	update(2*node + 1, mid+1, j, ind, val);
	segtree[node] = segtree[2*node] + segtree[2*node + 1];
}
 
int search(int node, int i, int j, int l, int r) {
	if (i > j || l > r || r < i || l > j) {
		return 0;
	}
	if (i >= l && j <= r) {
		return segtree[node];
	}
	int mid = (i+j)/2;
	int x = search(2*node, i, mid, l, r);
	int y = search(2*node + 1, mid + 1, j, l, r);
	return (x+y);
}
 
int main() {
 
	int n;
 
	scanf("%d", &n);
 
	for (int i = 1; i<=n ; i++) {
		scanf("%d", &arr[i]);
		last[arr[i]] = -1;
	}
 
	int q;
	scanf("%d", &q);
 
	for (int i=0; i < q; i++) {
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);
		query t;
		t.left = x;
		t.right = y;
		t.index = i;
		proc[i] = t;
	}
 
	sort(proc, proc + q, comp);
 
 
	buildTree(1, 1, n);
	int processed = 0;
 
	for (int i = 1; i <= n; i++) {
		if (processed == q) break;
		if (last[arr[i]] != -1) {
			int l = last[arr[i]];
			update(1, 1, n, l, -1);
		}
 
		update(1, 1, n, i, 1);
		last[arr[i]] = i;
 
		while (processed < q && proc[processed].right == i) {
			int x = search(1, 1, n, proc[processed].left, proc[processed].right);
			ans[proc[processed].index] = x;
			processed++;
		}
 
	}
 
	for (int i =0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
 
	return 0;
}