class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> d;
        for (auto& kv : knowledge) d[kv[0]] = kv[1];

        string result;
        int n = s.size();
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                int j = s.find(')', i);
                string key = s.substr(i + 1, j - i - 1);
                auto it = d.find(key);
                result += (it != d.end()) ? it->second : "?";
                i = j + 1;
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};