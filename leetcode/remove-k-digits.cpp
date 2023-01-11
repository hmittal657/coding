// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k) return "0";

        string ans = "";

        stack<int> s;

        for (int i =0; i < num.size(); i++) {
            if (s.empty()) {
                s.push(num[i] - '0');
            } else {
                int t = num[i] - '0';
                while (!s.empty() && k > 0 && t < s.top()) {
                    s.pop();
                    k--;
                }
                s.push(t);
            }
        }

        while (k > 0) {
            s.pop();
            k--;
        }

        if (s.empty()) return "0";

        while (!s.empty()) {
            ans.push_back((char)(s.top() + '0'));
            s.pop();
        }
        int l = 0;
        int h = ans.size()-1;
        cout << ans << endl;
        while (l <= h) {
            swap(ans[l], ans[h]);
            l++;
            h--;
        }
        cout << ans;
        l = 0;
        while (l < ans.size() && ans[l] == '0') {
            l++;
        }

        if (l == ans.size()) return "0";

        return ans.substr(l, ans.size()-l);

    }
};