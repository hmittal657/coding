// https://leetcode.com/problems/car-fleet/

class Solution {
public:

    struct Car {
        int pos;
        int sp;
        double time;
    };

    static bool comp(Car a, Car b) {
        return a.pos < b.pos; 
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<Car> v;
        for (int i =0; i < position.size(); i++) {
            Car a;
            a.pos = position[i];
            a.sp = speed[i];
            a.time = (double)(target - position[i])/(double)(speed[i]);
            v.push_back(a);
        }

        sort(v.begin(), v.end(), comp);

        stack<double> st;

        for (int i=0; i  < v.size(); i++) {
            double s = v[i].time;
            while (!st.empty() && s >= st.top()) {
                st.pop();
            }
            st.push(s);
        }

        return st.size();

    }
};