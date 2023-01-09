#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	
	set<int> pq;
	unordered_map<int, int> m;

	int n;
	scanf("%d", &n);

	for (int i =0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k-1; i++) {
		pq.insert(arr[i]);
		m[arr[i]]++;
	}

	for (int i = k-1; i < n-1; i++) {
		if (i - k >= 0) {
			m[arr[i-k]]--;
			if (m[arr[i-k]] == 0) {
				pq.erase(arr[i-k]);
			}
		}
		m[arr[i]]++;
		pq.insert(arr[i]);
		printf("%d ", pq.top());
	}

	if (n-1-k >= 0) {
		m[arr[n-1-k]]--;
			if (m[arr[n-1-k]] == 0) {
				pq.erase(arr[n-1-k]);
			}
	}
	pq.insert(arr[n-1]);
	m[arr[n-1]]++;
	printf("%d\n", pq.top());

	return 0;
}