#include <bits/stdc++.h>
using namespace std;

#define ll long long

// best to keep it 4*n + 1
int segtree[200002];

// used upto n
int arr[50001];

int n;

void buildTree(int node, int i, int j) {
	if (i > j || i < 1 || j > n) return;
	if (i == j) {
		segtree[node] = arr[i-1];
		return;
	}
	int mid = (i+j)/2;
	buildTree(2*node, i, mid);
	buildTree(2*node + 1, mid+1, j);

	segtree[node] = segtree[2*node] + segtree[2*node + 1];

}

void update(int node, int i, int j, int ind, int val) {
	if (i > ind || j < ind) {
		return;
	}
	if (i == j) {
		segtree[node] = val;
		return;
	}
	int mid = (i+j)/2;
	update(2*node, i, mid, ind, val);
	update(2*node + 1, mid+1, j, ind, val);
	segtree[node] = segtree[2*node] + segtree[2*node + 1];
}

int query(int node, int i, int j, int l, int r) {
	if (i > j || l > r || r < i || l > j) {
		return 0;
	}
	if (i >= l && j <= r) {
		return segtree[node];
	}
	int mid = (i+j)/2;
	int a = query(2*node, i, mid, l, r);
	int b = query(2*node + 1, mid+1, j, l, r);

	return (a+b);
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


	for (int i =0; i < m; i++) {
		int x, y;
		cin>>x>>y;
		cout << query(1, 1, n, x, y) << endl;
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int ind, val;
		cin>>ind>>val;
		update(1, 1, n, ind, val);
	}
	
	cin >> m;


	for (int i =0; i < m; i++) {
		int x, y;
		cin>>x>>y;
		cout << query(1, 1, n, x, y) << endl;
	}
	
	return 0;
}


// Test case
/**

Input:
10
-1 2 3 21 -12 2344 23 92 13 19
3
1 2
1 10
3 3
2
1 100
6 -10
3
1 2
1 10
3 3

Output:
1
2504
3
102
251
3

*/