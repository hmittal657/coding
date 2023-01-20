// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int piv = -1;
        int n = arr.size();
        vector<int> ans;
        if (x < arr[0]) {
            for (int i=0; i < k; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }

        if (x > arr[n-1]) {
            for (int i = n-k; i < n; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }

        int l = 0;
        int h = n-1;

        while (l <= h) {
            int mid = (l+h)/2;
            if (arr[mid] <= x) {
                piv = mid;
                l = mid+1;
            } else {
                h = mid-1;
            }
        }

        l = piv;
        h = piv+1;

        vector<int> f(k, -1);

        int start = 0;
        int e = k-1;

        while (l >= 0 && h  < n) {
            if (start > e) break; 
            if (abs(arr[l]-x) <= abs(arr[h]-x)) {
                f[start] = arr[l];
                l--;
                start++;
            } else {
                f[e] = arr[h];
                h++;
                e--;
            }
        }

        while (l >= 0) {
            if (start > e) {
                break;
            }
            f[start] = arr[l];
            l--;
            start++;
        }

        while (h < n) {
            if (start > e) break;
            f[e] = arr[h];
            h++;
            e--;
        }

        l = 0;
        h = start-1;

        while (l <= h) {
            swap(f[l], f[h]);
            l++;
            h--;
        }

        l = start;
        h = k-1;

        while (l <= h) {
            swap(f[l], f[h]);
            l++;
            h--;
        }
        return f;

    }
};