// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/

class Solution {
public:
    string removeDigit(string number, char digit) {
        
        int rem = -1;
        int n = number.size();
        for (int i =0; i  < number.size(); i++) {
            if (number[i] == digit) {
                if (i + 1 < n) {
                    if (number[i+1] - number[i] > 0) {
                        rem = i;
                        break;
                    }
                } 
            }
        }
        
        if (rem == -1) {
            for (int i  = number.size()-1 ; i >= 0; i--) {
                if (number[i] == digit) {
                    rem = i;
                    break;
                }
            }
        }
        
        string ans = "";
        for (int i =0; i < number.size(); i++) {
            if (i == rem) continue;
            ans.push_back(number[i]);
        }
        
        return ans;
        
    }
};