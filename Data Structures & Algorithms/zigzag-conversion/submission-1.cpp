class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) {
            return s;
        }

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;

        for (char ch : s) {
            rows[row].push_back(ch);

            if (row == 0) {
                direction = 1;
            } else if (row == numRows - 1) {
                direction = -1;
            }

            row += direction;
        }

        string ans;
        for (const string& r : rows) {
            ans += r;
        }

        return ans;
    }
};