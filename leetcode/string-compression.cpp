// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        
        char c = chars[0];
        int count = 1;

        int l = 0;

        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == c) {
                count++;
            } else {

                if (l >= n) {
                    chars.push_back(c);
                    l++;
                } else {
                    chars[l] = c;
                    l++;
                }

                if (count > 1) {
                    string cnt = to_string(count);

                    for (int k = 0; k < cnt.size(); k++) {
                        if (l >= n) {
                            chars.push_back(cnt[k]);
                            l++;
                        } else {
                            chars[l] = cnt[k];
                            l++;
                        }
                    }

                }

                count = 1;
                c = chars[i];

            }
        }

        if (l >= n) {
            chars.push_back(c);
            l++;
        } else {
            chars[l] = c;
            l++;
        }

        if (count > 1) {
            string cnt = to_string(count);

            for (int k = 0; k < cnt.size(); k++) {
                if (l >= n) {
                    chars.push_back(cnt[k]);
                    l++;
                } else {
                    chars[l] = cnt[k];
                    l++;
                }
            }

        }
        
        return l;
    }
};