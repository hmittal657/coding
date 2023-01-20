// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n = arr.size();
        int maxi = -1;
        for (int i = n-1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = maxi;
            maxi = max(temp, maxi);
        }

        return arr;

    }
};