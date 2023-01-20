// https://leetcode.com/problems/largest-number

class Solution {
public:

#define ll long long

    static bool comp(int x, int y) {
        if (x == 0) return false;
        if (y == 0) return true;
        int a = x;
        int b = y;
        int sz1 = 0;
        while (a > 0) {
            sz1++;
            a = a/10;
        }

        int sz2 = 0;
        while (b > 0) {
            sz2++;
            b = b/10;
        }

        ll first = pow(10, (ll)sz2) * (ll)(x) + (ll)y;
        ll second = pow(10, (ll)(sz1)) * (ll)(y) + (ll)x;

        return first >= second;
    }

    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), comp);

        string ans = "";

        for (int i =0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }

        int l = 0;
        while (l < ans.size() && ans[l] == '0') {
            l++;
        }

        ans = ans.substr(l, ans.size()-l);
        if (ans.size() == 0) return "0";
        return ans;

    }
};