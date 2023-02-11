// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        vector<int> v;
        int n = num.size();

        int m = 0;

        while (k > 0) {
            v.push_back(k%10);
            k = k/10;
            m++;
        }

        int l = 0; 
        int h = m-1;

        while (l < h) {
            swap(v[l], v[h]);
            l++;
            h--;
        }


        vector<int> ans(max(m, n) + 2, 0);

        int carry = 0;
        
        for (int i = 0; i < min(m, n); i++) {
            int x = num[n-1-i];
            int y = v[m-1-i];

            int t = x+y+carry;
            if (t >= 10) {
                carry = t/10;
                t = t%10;
            } else {
                carry = 0;
            }

            ans[ans.size()-1-i] = t;
        }

        for (int i = m; i < n; i++) {
            int x = num[n-1-i];
            int t = x+carry;
            if (t >= 10) {
                carry = t/10;
                t = t%10;
            } else {
                carry = 0;
            }
            ans[ans.size()-1-i] = t;
        }

        for (int i = n; i < m; i++) {
            
            int y = v[m-1-i];

            int t = y+carry;
            if (t >= 10) {
                carry = t/10;
                t = t%10;
            } else {
                carry = 0;
            }

            ans[ans.size()-1-i] = t;
        }

        if (carry > 0) {
            ans[ans.size() - 1 -max(m, n)] = 1;
            carry = 0;
        }

        int start = 0;
        while (start < ans.size() && ans[start] == 0) {
            start++;
        }

        vector<int> finalans;
        for (int i = start; i < ans.size(); i++) {
            finalans.push_back(ans[i]);
        }

        return finalans;


    }
};