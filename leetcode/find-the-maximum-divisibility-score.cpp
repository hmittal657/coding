// https://leetcode.com/problems/find-the-maximum-divisibility-score/

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        
        int maxi = -1;
        int maxc = -1;
        
        for (int i = 0; i < divisors.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] % divisors[i] == 0) {
                    count++;
                }
            }
            if (count > maxc) {
                maxi = divisors[i];
                maxc = count;
            } else if (count == maxc) {
                maxi = min(divisors[i], maxi);
            }
        }
        
        if (maxi == -1) {
            int mini = divisors[0];
            for (int i =0; i < divisors.size(); i++) {
                mini = min(mini, divisors[i]);
            }
            return mini;
        }
        
        return maxi;
        
    }
};