class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int prev = 0;

        for (const string& log : logs) {
            int p1 = log.find(':');
            int p2 = log.find(':', p1 + 1);
            int id = stoi(log.substr(0, p1));
            string type = log.substr(p1 + 1, p2 - p1 - 1);
            int ts = stoi(log.substr(p2 + 1));

            if (type == "start") {
                // The function on top was running until just before ts
                if (!st.empty()) res[st.top()] += ts - prev;
                st.push(id);
                prev = ts;
            } else {
                // "end" is inclusive of ts, so add 1
                res[st.top()] += ts - prev + 1;
                st.pop();
                prev = ts + 1; // the caller resumes at the next tick
            }
        }
        return res;
    }
};