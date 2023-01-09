// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:

    int lpt[10001];

    void compute(string& needle) {
        int n = needle.size();
        lpt[0] = 0;
        int i = 1;
        int index = 0;
        while (i < needle.size()) {
            if (needle[i] == needle[index]) {
                index++;
                lpt[i] = index;
                i++;
            } else {
                if (index == 0) {
                    lpt[i] = 0;
                    i++;
                } else {
                    index = lpt[index-1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        if (haystack.size()  < needle.size()) return -1;
        compute(needle);

        int i =0; 
        int j = 0;

        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == needle.size()) {
                    return (i-j);
                }
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lpt[j-1];
                }
            }
        }

        return -1;
    }
};