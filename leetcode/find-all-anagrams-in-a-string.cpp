// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:

    bool isEqual(vector<int>& a, vector<int>& b) {
        for (int i =0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        
        int n = s.size();

        if (n < p.size()) return vector<int>(0);

        vector<int> pdict(26, 0);

        for (int i=0; i < p.size(); i++) {
            pdict[p[i] - 'a']++;
        }

        int l = 0; 
        int h = p.size()-1;

        vector<int> cur(26, 0);

        for (int i = l; i <= h; i++) {
            cur[s[i] - 'a']++;
        }

        vector<int> ans;

        while (true) {
            if (isEqual(cur, pdict)) {
                ans.push_back(l);
            }
            if (h + 1 < n) {
                cur[s[l] - 'a']--;
                cur[s[h+1] - 'a']++;
                l++;
                h++;
            } else {
                break;
            }
        }

        return ans;
    }
};