#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/ABSYS/

bool isNum(string& s) {
	for (int i =0; i < s.size(); i++) {
		if (s[i] == 'm') {
			return false;
		}
	}
	return true;
}

void solve(vector<string>& nums) {

	int x, y, z;
	if (!isNum(nums[0])) {
		z = stoi(nums[4]);
		y  = stoi(nums[2]);
		x = z - y; 
	} else if (!isNum(nums[2])) {
		z = stoi(nums[4]);
		x = stoi(nums[0]);
		y = z- x;
	} else if (!isNum(nums[4])) {
		x = stoi(nums[0]);
		y = stoi(nums[2]);
		z = x + y;
	} else {
		x = stoi(nums[0]);
		y = stoi(nums[2]);
		z = stoi(nums[4]);
	}

	cout << x <<" + " << y << " = " << z <<endl;


}

int main() {

	std::ios::sync_with_stdio(false);

	int t;
	cin>>t;

	int count = 0;

	while(count < t) {
		
		vector<string> nums(5);
		for (int i =0; i < 5; i++) {
			cin>>nums[i];
		}
		solve(nums);

		count++;
	}

	return 0;
}
