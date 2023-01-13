// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

class Solution {
public:

    int parent[26];

     int find(int x) {
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }

    void merge(int x, int y) {
        int a = find(x);
        int b = find(y);

        if (a == b) return;
        if (a < b) {
            parent[b] = a;
            return;
        }

        parent[a] = b;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        for (int i =0; i < 26; i++) {
            parent[i] = i;
        }

        for (int i =0; i < s1.size(); i++) {
            merge(s1[i]-'a', s2[i]-'a');
        }

        string ans = "";

        for (int i =0; i  <baseStr.size(); i++) {
            int x = baseStr[i] - 'a';
            x = find(x);
            ans.push_back((char)(x + 'a'));
        }

        return ans;

    }
};