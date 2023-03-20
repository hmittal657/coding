// https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary {

struct Node {
    char c;
    bool isEnd;
    Node* childs[26];
};

private:
    Node* root;

    bool search(string& word, Node* x,  int j) {
        Node* cur = x;
        for (int i = j; i < word.size() ; i++) {
            if (word[i] == '.') {
                for (int k = 0; k < 26; k++) {
                    if (cur->childs[k] != NULL) {
                        if (i == word.size()-1) {
                            if (cur->childs[k]->isEnd) {
                                return true;
                            }
                        } else {
                            if (search(word, cur->childs[k],
                                i+1)) {
                                return true;
                            }
                        }
                    }
                }
                return false;
            } else {
                int ind = word[i]-'a';
                if (cur->childs[ind] == NULL) {
                    return false;
                }
                cur = cur->childs[ind];
                if (i == word.size()-1) {
                    return (cur->isEnd);
                }
            }
        }
        return false;
    }

public:
    WordDictionary() {
        root = new Node();
        root->c = '0';
        root->isEnd = false;
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (int i =0 ; i<word.size() ; i++) {
            int ind = word[i]-'a';
            if (cur->childs[ind] == NULL) {
                cur->childs[ind] = new Node();
                cur = cur->childs[ind];
                cur->c = word[i];
                
            } else {
                cur = cur->childs[ind];
            }
            if (i == word.size() - 1 ) {
                cur->isEnd = true;
            }
        }
    }
    
    bool search(string word) {
        Node* cur = root;
        return search(word, cur, 0);        
    }

    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */