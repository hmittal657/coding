// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int maxCount = pow(2, k);
        if ((n-k+1) < maxCount) return false;
        int cur = 0;
        for (int i=0; i < k; i++) {
            cur = 2 * cur + (s[i]-'0');
        }

        unordered_set<int> st;
        st.insert(cur);
        int f = pow(2, k-1)-1;

        for (int i = 1; i < n; i++) {
            if (st.size() == maxCount) return true;
            if (st.size() + (n-k+1-i) < maxCount) {
                return false;
            }
            cur = cur & f;
            cur = (cur<<1);
            cur += (s[i+k-1]-'0');
            st.insert(cur);
            if (st.size() == maxCount) return true;
        }

        return (st.size() == maxCount);
    }
};