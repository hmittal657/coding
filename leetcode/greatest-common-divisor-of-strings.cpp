// https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:

    string gcd(string& str1, string& str2) {
        
        
        if (str2 == "") return str1;
        if (str1 == "") return str2;

        if (str1 == str2) return str1;

        int m = str1.size();
        int n = str2.size();

        if (m == n) {
            return "";
        }

        if (m < n) {
            string temp = str1;
            str1 = str2;
            str2 = temp;
            swap(m, n);
        }
        string cur = "";
        for (int i = 0; i < m; i++) {
            if (str1[i] != str2[i%n]) return "";
            if (cur.size() == n) {
                cur = "";
            }
            cur.push_back(str1[i]);
            cout << cur << endl;
        }

        if (cur == str2) {
            cur = "";
        }
        return gcd(str2, cur);

    }

    string gcdOfStrings(string str1, string str2) {
        return gcd(str1, str2);
    }
};