// https://leetcode.com/problems/data-stream-as-disjoint-intervals

class SummaryRanges {
public:

    SummaryRanges() {
        starts.clear();
        for (int i =0; i < 10005; i++) {
            nums[i] = 0;
        }
    }
    
    void addNum(int value) {
        if (nums[value] > 0) return;
        nums[value] = 1;
        bool p = false;
        bool n = false;
        if (value-1 >= 0 && nums[value-1] > 0) {
            p = true;   
        }

        if (value+1 < 10005 && nums[value+1] > 0) {
            n = true;
        }

        if (p && n) {
            starts.erase(value+1);
            next[value] = next[value+1];
            prev[value] = prev[value-1];
            next[value-1] = next[value];
            prev[value+1] = prev[value];
        } else if (p) {
            next[value-1] = value;
            prev[value] = prev[value-1];
            next[value] = value;
        } else if (n) {
            starts.erase(value+1);
            starts.insert(value);
            next[value] = next[value+1];
            prev[value+1] = value;
            prev[value] = value;
        } else {
            starts.insert(value);
            next[value] = value;
            prev[value] = value;
        } 
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (int x : starts) {
            vector<int> t;
            t.push_back(x);
            int temp = x;
            while (temp != next[temp]){
                temp = next[temp];
            }
            t.push_back(temp);
            ans.push_back(t);
        }
        return ans;
    }

private:
    int nums[10005];
    int next[10005];
    int prev[10005];
    set<int> starts;

};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */