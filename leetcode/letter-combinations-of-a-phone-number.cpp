// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:

    void dfs(int i, string& digits, string& cur, vector<string>& ans) {
        if (i == digits.size()) {
            if (cur.size() > 0) {
                ans.push_back(cur);
            }
            return;
        }

        if (digits[i] == '2') {
            cur.push_back('a');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('b');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('c');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();
        } else if (digits[i] == '3') {
            cur.push_back('d');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('e');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('f');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();
        } else if (digits[i] == '4') {
             cur.push_back('g');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('h');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('i');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();
        } else if (digits[i] == '5') {
             cur.push_back('j');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('k');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('l');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();
        } else if (digits[i] == '6') {
             cur.push_back('m');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('n');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('o');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();
        } else if (digits[i] == '7') {
             cur.push_back('p');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('q');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('r');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

            cur.push_back('s');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();
        } else if (digits[i] == '8') {
             cur.push_back('t');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('u');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('v');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();
        } else if (digits[i] == '9') {
            cur.push_back('w');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('x');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

             cur.push_back('y');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();

            cur.push_back('z');
            dfs(i+1, digits, cur, ans);
            cur.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        string cur = "";

        dfs(0, digits, cur, ans);

        return ans;

    }
};