// https://leetcode.com/problems/lfu-cache

class LFUCache {
public:
    LFUCache(int capacity) {
        size = 0;
        MAX = capacity;
        mp.clear();
        freq.clear();
        nums.clear();
    }
    
    int get(int key) {
        if (MAX == 0) return -1;
        int ret;
        if (nums.find(key) != nums.end()) {
            ret = nums[key];
        } else {
            return -1;
        }
        freq[key]++;
        int f = freq[key];
        mp[f].push(key);
        return ret;
    }
    
    void put(int key, int value) {
        if (MAX == 0) return;
        if (nums.find(key) != nums.end()) {
            nums[key] = value;
            freq[key]++;
            int f = freq[key];
            mp[f].push(key);
        } else {
            if (size < MAX) {
                nums[key] = value;
                freq[key]++;
                int f = freq[key];
                mp[f].push(key);
                size++;
            } else {
                bool rem = false;
                int keyremoved = -1;
                int minfreq = -1;
                while (!rem) {
                    if (minfreq == -1) {
                        minfreq = mp.begin()->first;
                    } else if (mp[minfreq].empty()) {
                        mp.erase(minfreq);
                        minfreq = mp.begin()->first;
                    } else if (mp.empty()) {
                        break;
                    }
                   
                    keyremoved = mp[minfreq].front();
                    if (freq[keyremoved] == minfreq && nums.find(keyremoved) != nums.end()) {
                        rem = true;
                        nums.erase(keyremoved);
                        freq.erase(keyremoved);
                        mp[minfreq].pop();
                        size--;
                        break;
                    } else {
                        mp[minfreq].pop();
                    }
                }
                nums[key] = value;
                freq[key] = 1;
                size++;
                int f = freq[key];
                mp[f].push(key);
            }
        }
    }

    private:
    map<int, queue<int>> mp;
    unordered_map<int, int> freq;
    unordered_map<int, int> nums;
    int size;
    int MAX;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */