// https://leetcode.com/problems/baseball-game

class Solution {
public:

#define ll long long

    ll getnum(string x) {
        int z = stoi(x);
        return (ll)(z);
    }

    int calPoints(vector<string>& operations) {
        
        stack<ll> st;

        for (int i=0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                ll a = st.top();
                st.pop();
                ll b = st.top();
                ll c = a + b;
                st.push(a);
                st.push(c);
            } else if (operations[i] == "D") {
                ll a = st.top();
                ll b = 2 * a;
                st.push(b);
            } else if (operations[i] == "C") {
                st.pop();
            } else {
                st.push(getnum(operations[i]));
            }
        }

        ll sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;

    }
};