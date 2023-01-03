// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        vector<int> dict(26, 0);

        for (int i=0; i < text.size(); i++) {
            dict[text[i] - 'a']++;
        }

        string b = "balloon";

        vector<int> m(26, 0);

        for (int i=0; i < b.size(); i++) {
            m[b[i] - 'a']++;
        }

        int ans = INT_MAX;

        for (int i=0; i < 26; i++) {
            if (m[i] > 0) {
                int t = dict[i]/m[i];
                ans = min(ans, t);
            }
        }

        return ans;
    }
};