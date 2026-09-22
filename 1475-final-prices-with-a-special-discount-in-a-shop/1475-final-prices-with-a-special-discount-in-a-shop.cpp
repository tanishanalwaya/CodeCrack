class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res = prices;
        stack<int> st; // indices waiting for a discount

        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                int j = st.top(); st.pop();
                res[j] = prices[j] - prices[i];
            }
            st.push(i);
        }
        return res;
    }
};