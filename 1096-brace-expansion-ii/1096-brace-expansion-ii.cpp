class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = parseExpr(expression, i);
        return vector<string>(result.begin(), result.end());
    }

private:
    set<string> parseExpr(const string& s, int& i) {
        set<string> result = parseTerm(s, i);
        while (i < (int)s.size() && s[i] == ',') {
            i++; // skip ','
            set<string> next = parseTerm(s, i);
            result.insert(next.begin(), next.end());
        }
        return result;
    }

    set<string> parseTerm(const string& s, int& i) {
        set<string> result = parseFactor(s, i);
        while (i < (int)s.size() && s[i] != ',' && s[i] != '}') {
            set<string> next = parseFactor(s, i);
            result = cartesianConcat(result, next);
        }
        return result;
    }

    set<string> parseFactor(const string& s, int& i) {
        if (s[i] == '{') {
            i++; // skip '{'
            set<string> inner = parseExpr(s, i);
            i++; // skip '}'
            return inner;
        } else {
            int start = i;
            while (i < (int)s.size() && islower(s[i])) i++;
            return {s.substr(start, i - start)};
        }
    }

    set<string> cartesianConcat(const set<string>& a, const set<string>& b) {
        set<string> res;
        for (const string& x : a)
            for (const string& y : b)
                res.insert(x + y);
        return res;
    }
};