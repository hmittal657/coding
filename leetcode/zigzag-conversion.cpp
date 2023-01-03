// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int m) {
        if (m == 1) return s;

        string ans = "";

        for (int j =0; j < m; j++) {
            int i = j;
            int sz = 2*m - 2;
            int mid = (sz/2);
            while (true) {
                if (i >= s.size() || ans.size() == s.size()) break;
                ans.push_back(s[i]);
                int previ = i;
                int block = (i)/sz;
                int r = (i)%sz;
                if (r < mid) {
                    i = (i + sz - 2*r);
                } else {
                    i = i + 2*((block+1)*sz - i);
                }
                
            }
        }

        return ans;
    }
};