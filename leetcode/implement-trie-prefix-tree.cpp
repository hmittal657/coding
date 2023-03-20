// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {

struct Node {
    char c;
    bool isEnd;
    vector<Node*> childs;
};

private:
    Node* root;

public:
    Trie() {
        root = new Node();
        root->c = '0';
        root->isEnd = false;
        root->childs = vector<Node*>(26, NULL);
    }
    
    void insert(string word) {
        Node* cur = root;
        for (int i = 0; i < word.size() ; i++) {
            if (cur->childs[word[i]-'a'] == NULL) {
                cur->childs[word[i]-'a'] = new Node();
                cur = cur->childs[word[i]-'a'];
                cur->c = word[i];
                cur->childs = vector<Node*>(26, NULL);
                if (i == word.size() - 1) {
                    cur->isEnd = true;
                }
            } else {
                cur = cur->childs[word[i]-'a'];
                if (i == word.size() - 1) {
                    cur->isEnd = true;
                }
            }
        }
    }
    
    bool search(string word) {
        Node* cur = root;
        for (int i = 0; i < word.size() ; i++) {
            if (cur->childs[word[i]-'a'] == NULL) {
                return false;
            }
            cur = cur->childs[word[i]-'a'];
            if (i == word.size()-1) {
                return (cur->isEnd);
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for (int i = 0; i < prefix.size() ; i++) {
            if (cur->childs[prefix[i]-'a'] == NULL) {
                return false;
            }
            cur = cur->childs[prefix[i]-'a'];
            if (i == prefix.size()-1) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */