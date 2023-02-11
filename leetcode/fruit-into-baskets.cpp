// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 1;

        int a, b;

        a = fruits[0];

        b = fruits[0];

        int start = 0;
        int cur_num = fruits[0];
        int cur_start = 0;

        for (int i = 1 ; i < n; i++) {
            int x = fruits[i];
            if (x == a || x == b) {
                ans = max(ans, i - start + 1);
                if (x != cur_num) {
                    cur_num = x;
                    cur_start = i;
                }
            } else {
                a = x;
                b = cur_num;
                start = cur_start;
                cur_num = x;
                cur_start = i;
                ans = max(ans, i - start + 1);
            }
        }   

        return ans;
    }
};