// https://leetcode.com/problems/find-unique-binary-string

class Solution {
public:

    int convert(string& x) {
        int ans = 0;

        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '0') {
                ans = 2*ans;
            } else {
                ans = 2*ans + 1;
            }
        }

        return ans;

    }

    string fun(int num, int n) {
        vector<int> digits;
        for (int i=0; i < n; i++) {
            digits.push_back((num>>i) & (1));
        }
        string ans = "";
        for (int i = n-1; i >= 0; i--) {
            ans.push_back((char)(digits[i] + '0'));
        }
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {

       int n = nums.size();

       unordered_map<int, int> m;

       for (int i =0; i < nums.size(); i++) {
           m[convert(nums[i])] = 1;
       }
        int res;

        for (int i = 0; i <= n; i++) {
            if (m.find(i) == m.end()) {
                res = i;
                break;
            }
        }
       
        return fun(res, n);

    }
};