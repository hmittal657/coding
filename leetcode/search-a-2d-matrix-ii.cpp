// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n-1;

        while (row >= 0 && row < m && col >= 0 && col < n) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }

        return false;

    }
};