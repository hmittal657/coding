// https://leetcode.com/problems/encode-and-decode-tinyurl

class Solution {
public:

    unordered_map<string, string> m1;
    unordered_map<string, string> m2;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (m1.find(longUrl) != m1.end()) {
            return m1[longUrl];
        }
        string tiny = to_string(rand() % 100005);
        m1[longUrl] = tiny;
        m2[tiny] = longUrl;
        return tiny;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m2[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));