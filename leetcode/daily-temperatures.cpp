// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> nex(n, -1);
        nex[n-1] = 0;
        for (int i = n-2 ;i >= 0 ; i--) {
            int h = i+1;
            while (h < n) {     
                if (t[h] > t[i]) {
                    nex[i] = h-i;
                    break;
                } else if (nex[h] == 0) {
                    nex[i] = 0;
                    break;
                } else {
                    h = h + nex[h];
                }
            }
            if (h >= n) {
                nex[i] = 0;
            }
        }

        return nex;

    }
};