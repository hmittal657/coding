// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution {
public:
    double average(vector<int>& salary) {
        int high = salary[0];
        int low = salary[0];
        double sum = 0;
        for (int i = 0; i < salary.size(); i++) {
            high = max(salary[i], high);
            low = min(salary[i], low);
            sum += (double)(salary[i]);
        }

        sum -= (double)(high);

        sum -= (double)(low);

        double denom = (double)(salary.size() - 2);

        return (sum/denom);

    }
};