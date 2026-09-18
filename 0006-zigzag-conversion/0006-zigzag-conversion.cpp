class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.size()) return s;

        vector<string> rows(numRows);
        int cur = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[cur] += c;
            if (cur == 0 || cur == numRows - 1) goingDown = !goingDown;
            cur += goingDown ? 1 : -1;
        }

        string result;
        for (auto& row : rows) result += row;
        return result;
    }
};