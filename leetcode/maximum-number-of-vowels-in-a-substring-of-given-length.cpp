// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<int, int> m;
        m['a'] = 0;
        m['e'] = 0;
        m['i'] = 0;
        m['o'] = 0;
        m['u'] = 0;


        for (int i =0; i < k; i++) {
            if (m.find(s[i]) != m.end()) {
                m[s[i]]++;
            }
        }

        int ans = 0;
        for (auto& it : m) {
            ans += it.second;
        }

        for (int i = k ; i < s.size(); i++) {
            if (m.find(s[i]) != m.end()) {
                m[s[i]]++;
            }
            if (m.find(s[i-k]) != m.end()) {
                m[s[i-k]]--;
            }

            int cur = 0; 
            for (auto& it : m) {
                cur += it.second;
            }

            ans = max(ans, cur);
        }

        return ans;

    }
};