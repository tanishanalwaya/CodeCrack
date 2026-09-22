class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st; // indices waiting for a warmer day

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int j = st.top(); st.pop();
                res[j] = i - j;
            }
            st.push(i);
        }
        return res;
    }
};