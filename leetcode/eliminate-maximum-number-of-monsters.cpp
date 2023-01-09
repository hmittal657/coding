// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n);
        for (int i =0; i < dist.size(); i++) {
           time[i] = dist[i]/speed[i];
           if (dist[i] % speed[i] > 0) {
               time[i]++;
           }
        }

        for (int i =0; i < n; i++) {
            cout << time[i] << "\t";
        }

        sort(time.begin(), time.end());

        for (int i = 1; i <= n; i++) {
            time[i-1] -= (i-1);
            if (time[i-1] <= 0) {
                return (i-1);
            }
        }

        return n;

    }
};