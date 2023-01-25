// https://leetcode.com/problems/maximum-frequency-stack

class FreqStack {
public:

unordered_map<int, int> freq;
unordered_map<int, stack<int>> s;
int maxfreq = 0;

    FreqStack() {
        freq.clear();
        s.clear();
        maxfreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        int f = freq[val];
        if (f > maxfreq) {
            maxfreq = f;
        }
        s[f].push(val);
    }
    
    int pop() {
        int ret = s[maxfreq].top();
        freq[ret]--;
        s[maxfreq].pop();
        if (s[maxfreq].empty()) {
            maxfreq--;
        }
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */