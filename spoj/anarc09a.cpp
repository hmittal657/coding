#include <iostream>
#include <stack>
#include <string>
using namespace std;

// https://www.spoj.com/problems/ANARC09A/

int main() {

	std::ios::sync_with_stdio(false);

	string a;
	int index = 1;

	while (true) {
		cin>>a;
		if (a[0]  == '-') break;

		stack<char> s;

		int ops = 0;

		
		for (int i =0; i < a.size(); i++) {
			if (a[i] == '{') {
				s.push(a[i]);
			} else {
				if (s.empty()) {
					ops++;
					s.push(a[i]);
				} else {
					s.pop();
				}
			}
		}

		ops += s.size()/2;

		printf("%d. %d\n", index, ops);
		index++;
	}

	// your code goes here
	return 0;
}