#include <iostream>
#include <algorithm>
using namespace std;

// https://www.spoj.com/problems/BUSYMAN/

struct Task {
	int x;
	int y;
};

int n;
Task arr[100005];

static bool comp(Task a, Task b) {
	if (b.y != a.y) {
		return a.y < b.y;
	}
	return ((a.y-a.x) < (b.y-b.x));
}


int main() {

	int t;
	scanf("%d", &t);

	while (t > 0) {
		scanf("%d", &n);

		int x, y;

		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			arr[i] = {x, y};
		}

		sort(arr, arr+n, comp);

		int tasks = 0;

		int furthest = -1;

		for (int i =0; i < n; i++) {
			if (arr[i].x >= furthest) {
				tasks++;
				furthest = arr[i].y;
			}
		}

		printf("%d\n", tasks);

		t--;
	}

	return 0;
}