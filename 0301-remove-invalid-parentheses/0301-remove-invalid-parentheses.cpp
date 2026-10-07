class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        visited.insert(s);
        q.push(s);
        bool found = false;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int k = 0; k < levelSize; k++) {
                string cur = q.front(); q.pop();

                if (isValid(cur)) {
                    result.push_back(cur);
                    found = true;
                }

                if (found) continue; // don't expand further once we've found valid strings at this level

                for (int i = 0; i < (int)cur.size(); i++) {
                    if (cur[i] != '(' && cur[i] != ')') continue;
                    string next = cur.substr(0, i) + cur.substr(i + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            if (found) break;
        }

        return result;
    }

private:
    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }
};