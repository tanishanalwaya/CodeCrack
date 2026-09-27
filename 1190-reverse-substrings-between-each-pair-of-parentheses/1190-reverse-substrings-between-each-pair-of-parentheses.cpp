class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> pair_(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top(); st.pop();
                pair_[i] = j;
                pair_[j] = i;
            }
        }

        string result;
        for (int i = 0, dir = 1; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair_[i];
                dir = -dir;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};