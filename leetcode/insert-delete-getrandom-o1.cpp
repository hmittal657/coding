// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
public:

    vector<int> nums;
    unordered_map<int, int> m;

    RandomizedSet() {
        m.clear();
        nums.clear();
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false;
        }
        nums.push_back(val);
        m[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }
        int ind = m[val];
        if (ind == nums.size()-1) {
            m.erase(val);
            nums.pop_back();
        } else {
            int x = nums[nums.size()-1];
            swap(nums[nums.size()-1], nums[ind]);
            m[x] = ind;
            m.erase(val);
            nums.pop_back();
        }
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */