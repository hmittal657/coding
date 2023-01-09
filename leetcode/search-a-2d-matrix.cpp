// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (target < matrix[0][0]) return false;
        if (target > matrix[m-1][n-1]) return false;

        int r = 0;

        int l = 0;
        int h = m-1;

        while (l <= h) {
            int mid = (l+h)/2;
            if (matrix[mid][0] <= target) {
                r = mid;
                l = mid+1;
            } else {
                h = mid-1;
            }
        }

        l = 0;
        h = n-1;
        while (l <= h) {
            int mid = (l+h)/2;
            if (matrix[r][mid] == target) {
                return true;
            } else if (matrix[r][mid] > target) {
                h = mid-1;
            } else {
                l = mid+1;
            }
        }

        return false;
    }
};