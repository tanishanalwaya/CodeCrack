class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[nums[i]].push_back(i);

        vector<long long> res(n, 0);

        for (auto& [val, idx] : groups) {
            int m = idx.size();
            long long total = 0;
            for (int x : idx) total += x;

            long long prefix = 0; // sum of idx[0..k-1]
            for (int k = 0; k < m; k++) {
                long long cur = idx[k];
                long long left  = cur * k - prefix;
                long long right = (total - prefix - cur) - cur * (m - k - 1);
                res[idx[k]] = left + right;
                prefix += cur;
            }
        }
        return res;
    }
};