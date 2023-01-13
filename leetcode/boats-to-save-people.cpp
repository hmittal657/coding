// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;

        int n = people.size();

        sort(people.begin(), people.end());

        vector<bool> taken(n, false);

        int temp = -1;

        for (int i = 0; i < n; i++) {
            if (taken[i]) continue;

            int l = i+1;
            int h = n-1;
            if (temp != -1) {
                h = temp;
            }
            int res = -1;

            while (l <= h) {
                int mid = (l+h)/2;
                if (people[i] + people[mid] <= limit) {
                    res = mid;
                    l = mid+1;
                } else {
                    h = mid-1;
                }
            }

            if (res == -1) {
                taken[i] = true;
                boats++;
            } else {
                int k = res;
                while (k > i && taken[k]) {
                    k--;
                }
                taken[k] = true;
                temp = k-1;
                taken[i] = true;
                boats++;
            }
        }

        return boats;
    }
};