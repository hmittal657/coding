#include <iostream>
#include <vector>
using namespace std;

// https://www.spoj.com/problems/PERMUT2/

#define ll long long

int main() {
	int n;

	while (true) {
		
		scanf("%d", &n);

		if (n == 0) break;

		vector<int> nums(n+1);
		vector<int> indices(n+1);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &nums[i]);
			indices[nums[i]] = i;
		}

		bool amb = true;
		for (int i = 1; i <= n; i++) {
			if (indices[i] != nums[i]) {
				amb = false;
				break;
			}
		}

		if (amb) {
			printf("ambiguous\n");
		} else {
			printf("not ambiguous\n");
		}

	}

	return 0;
}