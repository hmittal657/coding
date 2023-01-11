// https://leetcode.com/problems/maximum-number-of-removable-characters

class Solution {
public:

    bool isSub(string& temp, string& p) {
        int i = 0;
        int j = 0;
        while (i < temp.size() && j < p.size()) {
            if (temp[i] == p[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return (j == p.size());
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        string temp = s;

        int l = 0;
        int h = removable.size();
        int res = 0;

        while (l <= h) {
            int mid = (l+h)/2;
            for (int i =0; i < mid; i++) {
                temp[removable[i]] = '#';
            }
            if (isSub(temp, p)) {
                res = mid;
                l = mid+1;
            } else {
                h = mid-1;
            }
            for (int i =0; i < mid; i++) {
                temp[removable[i]] = s[removable[i]];
            }
        }

        return res;
    }
};