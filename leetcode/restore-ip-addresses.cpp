// https://leetcode.com/problems/restore-ip-addresses

class Solution {
public:


    vector<string> restoreIpAddresses(string s) {

        vector<string> ans;

        int n = s.size();

        for (int i = 0; i < min(n, 3); i++) {
            string a = s.substr(0, i+1);
            if (a.size() == 0) continue;
            int x = stoi(a);
            if (x > 255) continue;
            if (a.size() > 1 && a[0] =='0') continue;
            for (int j = i+1; j < min(n, i+4); j++) {
                string b = s.substr(i+1, j-i);
                if (b.size() == 0) continue;
                int y = stoi(b);
                if (y > 255) continue;
                if (b.size() > 1 && b[0] =='0') continue;
                
                for (int k = j+1; k < min(n, j+4); k++) {
                    string c = s.substr(j+1, k-j);
                    if (c.size() == 0) continue;
                    int z = stoi(c);
                    if (z > 255) continue;
                    if (c.size() > 1 && c[0] =='0') continue;

                    for (int l = k+1; l < min(n, k+4); l++) {
                        string d = s.substr(k+1, l-k);
                        if (d.size() == 0) continue;
                        int x = stoi(d);
                        if (x > 255) continue;
                        if (d.size() > 1 && d[0] =='0') continue;
                        if (a.size() + b.size() + c.size() + d.size() != n) continue;
                        string temp = a + "." + b + "." + c + "." + d;
                        ans.push_back(temp);
                    }
                }
            }
        }

        return ans;

    }
};