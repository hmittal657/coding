#include <iostream>
#include <string>
#include <vector>
using namespace std;

// https://www.spoj.com/problems/NHAY/

int main() {
	std::ios::sync_with_stdio(false);

	int m;

	while (cin>>m) {
		string needle;
		cin >> needle;

		vector<int> lps(m);

		lps[0] = 0;

		int index = 0;
		int i = 1;

		while (i < m) {
			if (needle[i] == needle[index]) {
				index++;
				lps[i] = index;
				i++;
			} else {
				if (index == 0) {
					lps[i] = 0;
					i++;
				} else {
					index = lps[index-1];
				}
			}
		}

		string haystack;
		cin>>haystack;

		i = 0;
		int j = 0;
		if (haystack.size() < needle.size()) {
			continue;
		}
		if (haystack == needle) {
			printf("1\n\n");
			continue;
		}
		bool found = false;

		while (i < haystack.size()) {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
				if (j == needle.size()) {
					printf("%d\n", i-j);
					found = true;
					j = lps[j-1];
				}
			} else {
				if (j == 0) {
					i++;
				} else {
					j = lps[j-1];
				}
			}
		}
		if (found) printf("\n");
	}


	return 0;
}