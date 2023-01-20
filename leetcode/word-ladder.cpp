// https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> m;

        for (int i=0; i < wordList.size(); i++) {
            m.insert(wordList[i]);
        }
        if (m.find(endWord) == m.end()) return 0;

        unordered_map<string, int> visited;

        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        visited[beginWord] = 1;

        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            string x = p.first;
            int level = p.second;
            if (x == endWord) {
                return (level + 1);
            }
            for (int i =0; i < x.size(); i++) {
                int orig = x[i]-'a';
                for (int j = 0; j < 26; j++) {
                    if (orig == j) continue;
                    x[i] = (char)(j + 'a');
                    if (visited.find(x) == visited.end() && m.find(x) != m.end()) {
                        visited[x] = 1;
                        q.push({x,level+1});
                    }
                }
                x[i] = (char)(orig + 'a');
            }
        }
        return 0;
    }

    
};