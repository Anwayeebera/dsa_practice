class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash, hash + 256, -1); // Initialize all values to -1

        int l = 0, r = 0, maxlen = 0;
        int n = s.size();

        while (r < n) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
            maxlen = max(maxlen, r - l + 1);
            hash[s[r]] = r; // Update last seen index of s[r]
            r++;
        }

        return maxlen;
    }
};
