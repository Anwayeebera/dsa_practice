class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;  // If only 1 row, return the string itself

        vector<string> rows(min(numRows, int(s.size()))); // Create a vector of strings for rows
        int currentRow = 0;
        bool goingDown = false;  // Flag to determine direction (down or up)

        // Traverse through the string and place characters in respective rows
        for (char c : s) {
            rows[currentRow] += c;  // Append character to the current row
            if (currentRow == 0 || currentRow == numRows - 1) goingDown = !goingDown;  // Reverse direction
            currentRow += goingDown ? 1 : -1;  // Move to next row accordingly
        }

        // Concatenate all rows into the final result
        string result;
        for (string row : rows) result += row;
        return result;
    }
};