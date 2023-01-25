#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/SBANK/

struct A {
	int arr[6];
};

A nums[100001];

static bool comp(A a, A b) {
	for (int j =0 ; j < 6; j++) {
		if (a.arr[j] != b.arr[j]) {
			return (a.arr[j] < b.arr[j]);
		}
	}
	return a.arr[0] < b.arr[0];
}

void fun(A x, int f) {
	string temp = to_string(x.arr[0]);
	int l = 2 - temp.size();
	for (int k = 0; k < l; k++) {
		cout << '0';
	}
	cout << temp << " ";


	temp = to_string(x.arr[1]);
	l = 8 - temp.size();
	for (int k = 0; k < l; k++) {
		cout << '0';
	}
	cout << temp << " ";

	for (int j = 2; j < 6; j++) {
		temp = to_string(x.arr[j]);
		l = 4 - temp.size();
		for (int k = 0; k < l; k++) {
		cout << '0';
		}
		cout << temp << " ";
	}
	cout << f << endl;

}

int main() {

	int t;
	scanf("%d", &t);

	while (t > 0) {

		int n;
		scanf("%d", &n);

		for (int i =0; i < n; i++) {
			for (int j = 0; j < 6; j++) {
				scanf("%d", &(nums[i].arr[j]));
			}
		}

		sort(nums, nums+n, comp);

		A cur = nums[0];
		int f = 1;

		for (int i = 1; i < n; i++) {
			bool equal = true;
			for (int j = 0; j < 6; j++) {
				if (cur.arr[j] != nums[i].arr[j]) {
					equal = false;
					break;
				}
			}
			if (equal) {
				f++;
			} else {
				fun(cur, f);
				cur = nums[i];
				f = 1;
			}
		}

		fun(cur, f);
		cout << endl;

		t--;
	}

	// your code goes here
	return 0;
}