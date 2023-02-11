// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        
        if (b == "0") return a;
        if (a == "0") return b;

        int m = a.size();
        int n = b.size();

        string ans = "";
        for (int i = 0; i < max(m,n)+2; i++) {
            ans.push_back('0');
        }

        int carry = 0;

        for (int i = 0; i < min(m, n); i++) {

            int x = a[m-1-i] - '0';
            int y = b[n-1-i] - '0';

            int t = x + y + carry;

            if (t >= 2) {
                carry = 1;
                t = t-2;
            } else {
                carry = 0;
            }

            ans[ans.size()-1-i] = (char)(t + '0');

        }

        for (int i = m ; i < n; i++) {
            int y = b[n-1-i] - '0';

            int t = y + carry;

            if (t >= 2) {
                carry = 1;
                t = t-2;
            } else {
                carry = 0;
            }

            ans[ans.size()-1-i] = (char)(t + '0');
        }

        for (int i = n; i < m; i++) {
            int x = a[m-1-i] - '0';

            int t = x + carry;

            if (t >= 2) {
                carry = 1;
                t = t-2;
            } else {
                carry = 0;
            }

            ans[ans.size()-1-i] = (char)(t + '0');
        }

        if (carry == 1) {
            ans[ans.size()-1-max(m, n)] = '1';
        }

        int l = 0;
        while (l < ans.size() && ans[l] == '0') {
            l++;
        }

        return ans.substr(l, ans.size()-l);

    }
};