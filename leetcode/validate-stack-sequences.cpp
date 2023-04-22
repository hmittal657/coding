// https://leetcode.com/problems/validate-stack-sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int n  = pushed.size();

        int i = 0, j = 0;

        while (true) {
            if (st.empty()) {
                if (i == n && j == n) return true;
                if (i < n) {
                    st.push(pushed[i]);
                    i++;
                } else if (j < n) {
                    return false;
                }
            } else {
                if (j == n) return false;
                if (st.top() == popped[j]) {
                    st.pop();
                    j++;
                } else {
                    if (i == n) return false;
                    st.push(pushed[i]);
                    i++;
                }
            }
        }

        return false;

    }
};