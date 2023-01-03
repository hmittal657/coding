// https://leetcode.com/problems/gas-station

/**
The key idea is if we start from A, if we reach B but not able to go further, 
We can't start from any element A <= element <= B and reach B+1.
So we can discard those and go next starting point as B+1
*/

class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        if (n == 1) {
            if (gas[0] >= cost[0]) {
                return 0;
            } else {
                return -1;
            }
        }

        int start = 0;

        int total = 0;
        int cur = 0;
        for (int i =0; i < n; i++) {
            total += gas[i];
            total -= cost[i];
            cur += gas[i];
            cur -= cost[i];
            if (cur < 0) {
                start = i+1;
                cur = 0;
            }
        }
        
        if (total < 0) return -1;
        return start;

    }
};