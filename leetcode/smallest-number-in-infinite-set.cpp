// https://leetcode.com/problems/smallest-number-in-infinite-set

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        s.clear();
        for (int i = 1; i <= 1005; i++) {
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int x = *(s.begin());
        s.erase(x);
        return x;
    }
    
    void addBack(int num) {
        s.insert(num);
    }

    private:
        set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */