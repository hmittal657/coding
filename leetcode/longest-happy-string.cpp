// https://leetcode.com/problems/longest-happy-string

class Solution {
public:

    string longestDiverseString(int a, int b, int c) {
        
        string ans = "";

        while (a > 0 || b > 0 || c > 0) {
            if (a >= b && a >= c) {
                if (ans.size() >= 2) {
                    if (ans[ans.size()-1] == 'a' && ans[ans.size()-2] == 'a') {
                        if (b >= c && b > 0) {
                            ans.push_back('b');
                            b--;
                        } else if (c >= b && c > 0) {
                            ans.push_back('c');
                            c--;
                        } else {
                            break;
                        }
                    } else {
                        ans.push_back('a');
                        a--;
                    }
                } else {
                    ans.push_back('a');
                    a--;
                } 
            } else if (b >= a && b >= c) {
                if (ans.size() >= 2) {
                    if (ans[ans.size()-1] == 'b' && ans[ans.size()-2] == 'b') {
                        if (a >= c && a > 0) {
                            ans.push_back('a');
                            a--;
                        } else if (c >= a && c > 0) {
                            ans.push_back('c');
                            c--;
                        } else {
                            break;
                        }
                    } else {
                        ans.push_back('b');
                        b--;
                    }
                } else {
                    ans.push_back('b');
                    b--;
                }
            } else {
                if (ans.size() >= 2) {
                    if (ans[ans.size()-1] == 'c' && ans[ans.size()-2] == 'c') {
                        if (a >= b && a > 0) {
                            ans.push_back('a');
                            a--;
                        } else if (b >= a && b > 0) {
                            ans.push_back('b');
                            b--;
                        } else {
                            break;
                        }
                    } else {
                        ans.push_back('c');
                        c--;
                    }
                } else {
                    ans.push_back('c');
                    c--;
                }
            }
        }

        return ans;        

    }
};