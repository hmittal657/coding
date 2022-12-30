// https://leetcode.com/problems/hand-of-straights/solutions

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();
        unordered_map<int, int> m;

        for (int i=0; i  < n; i++) {
           m[hand[i]]++;
        }

        sort(hand.begin(), hand.end());

        for (int i =0; i < hand.size(); i++) {
            if (m[hand[i]] == 0) continue;

            int start = hand[i];
            int end = hand[i] + groupSize - 1;

            for (int j = start; j<= end; j++) {
                if (m[j] == 0) return false;
                m[j]--;
            }
        }

        return true;

    }
};