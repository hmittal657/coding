// https://leetcode.com/problems/successful-pairs-of-spells-and-potions

class Solution {
public:

#define ll long long

    vector<int> successfulPairs(vector<int>& spells, vector<int>& p,
        long long success) {
        
        int n = spells.size();

        vector<int> ans(n);

        sort(p.begin(), p.end());

        for (int i = 0; i < n; i++) {

            int l = 0; 
            int h = p.size()-1;

            ll b = (ll)(p[h]);
            ll a = (ll)(spells[i]);

            if (a * b < success) {
                ans[i] = 0;
                continue;
            }

            b = (ll)(p[l]);

            if (a * b >= success) {
                ans[i] = p.size();
            }

            int res = h;

            while (l <= h) {
                int mid = (l+h)/2;
                b = (ll)(p[mid]);
                if (a * b >= success) {
                    res = min(res, mid);
                    h = mid-1;
                } else {
                    l = mid + 1;
                }
            }

            ans[i] = p.size() - res;
        }

        return ans;

    }
};