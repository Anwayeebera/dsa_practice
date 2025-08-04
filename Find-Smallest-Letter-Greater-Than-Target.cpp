class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n - 1;
        int pos = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] > target) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // If no character greater than target is found, then return first one from letters
        if (pos == -1) {
            return letters[0];
        }
        return letters[pos];
    }
};