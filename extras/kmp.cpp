#include <iostream>
#include <string>
using namespace std;

int lpt[100005];

void buildlpt(string& s) {
	int n = s.size();
	lpt[0] = 0;
	int index = 0;
	int i = 1;
	while(i < n) {
		if (s[i] == s[index]) {
			index++;
			lpt[i] = index;
			i++;
		} else {
			if (index == 0) {
				lpt[i] = 0;
				i++;
			} else {
				index = lpt[index-1];
			}
		}
	}
}

void search(string& haystack, string& pattern) {
	int i = 0;
	int j =0;

	while (i < haystack.size()) {
		if (haystack[i] == pattern[j]) {
			i++;
			j++;
			if (j == pattern.size()) {
				cout << "found at : " << i-j << endl;
				j = lpt[j-1];
			}
		} else {
			if (j != 0) {
				j = lpt[j-1];	
			} else {
				i++;
			}
		}
	}
}

int main() {
	
	string haystack;
	string pattern;

	cin >> haystack;
	cin >> pattern;

	buildlpt(pattern);

	search(haystack, pattern);

	return 0;
}

/**
Input 
ABABDABACDABABCABABABABCABAB
ABABCABAB

Output
found at : 10
found at : 19
*/