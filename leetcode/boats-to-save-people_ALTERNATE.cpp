// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;

        int n = people.size();

        sort(people.begin(), people.end());

        int i = 0;
        int j = n-1;

        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                boats++;
                i++;
                j--;
            } else {
                j--;
                boats++;
            }
        }

        return boats;
    }
};