// https://leetcode.com/problems/design-hashmap/

class MyHashMap {
public:

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        if (data[h] == NULL) {
            Node* x = new Node();
            x->val = value;
            x->key = key;
            x->next = NULL;
            data[h] = x;
        } else {
            Node* cur = data[h];
            while (cur) {
                if (cur->next == NULL) {
                    Node* x = new Node();
                    x->val = value;
                    x->key = key;
                    x->next = NULL;
                    cur->next = x;
                    break;
                } else {
                    cur = cur->next;
                }
            }
        }
    }
    
    int get(int key) {
        int h = hash(key);
        Node* cur = data[h];
        while (cur) {
            if (cur->key == key) return cur->val;
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        Node* cur = data[h];
        if (cur == NULL) return;

        if (cur->key == key) {
            data[h] = cur->next;
        } else {
            Node* prev = NULL;
            while (cur) {
                if (cur->key == key) {
                    prev->next = cur->next;
                    return;
                } else {
                    prev = cur;
                    cur = cur->next;
                }
            }
        }
    }

private:

    static const int size = 10005;
    static const int multiplier = 10247693;

    struct Node {
        int key;
        int val;
        Node* next;
    };

    Node* data[size] = {};

    int hash(int key) {
        int h = (int)((long long)(key) * (long long)(multiplier) % size);
        return h;
    }

};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */