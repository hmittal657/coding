// https://leetcode.com/problems/naming-a-company/

class Solution {
public:

#define ll long long

    long long distinctNames(vector<string>& ideas) {
        
        ll n = (ll)ideas.size();

        ll ans = 0;

        unordered_set<string> dict[26];

        for (int i=0; i < ideas.size(); i++) {
            dict[ideas[i][0]-'a'].insert(ideas[i].substr(1, ideas[i].size()-1));
        }

        for (int i =0; i < 26; i++) {
            for (int j = i+1 ; j < 26; j++) {
                ll num_common = 0L;

                for (auto x : dict[i]) {
                    if (dict[j].find(x) != dict[j].end()) {
                        num_common++;
                    }
                }

                ans += (2L) * (dict[i].size() - num_common) * (dict[j].size() - num_common);

            }
        }

        return ans;

    }
};