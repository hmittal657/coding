// https://leetcode.com/problems/maximum-population-year

class Solution {
public:

    int nums[2500];

    int maximumPopulation(vector<vector<int>>& logs) {
        
        for (int i = 1950; i <= 2050; i++) {
            nums[i] = 0;
        }

        for (int i =0; i < logs.size(); i++) {
            nums[logs[i][0]]++;
            nums[logs[i][1]]--;
        }

        for (int i = 1951; i <= 2050; i++) {
            nums[i] += nums[i-1];
        }

        int maxv = nums[1950];
        int maxi = 1950;

        for (int i = 1951; i <= 2050; i++) {
            if (nums[i] > maxv) {
                maxv = nums[i];
                maxi = i;
            }
        }

        return maxi;

    }
};