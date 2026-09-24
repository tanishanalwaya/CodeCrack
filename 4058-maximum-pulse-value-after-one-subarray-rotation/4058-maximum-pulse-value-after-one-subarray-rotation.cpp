class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> P(n + 1, 0);
        for (int j = 0; j < n; j++) {
            long long s = (j % 2 == 0) ? (long long)nums[j] : -(long long)nums[j];
            P[j + 1] = P[j] + s;
        }

        long long best = LLONG_MIN;

        // even-indexed P values: P[0], P[2], P[4], ...
        long long runMax = P[0];
        for (int idx = 2; idx <= n; idx += 2) {
            best = max(best, runMax - P[idx]);
            runMax = max(runMax, P[idx]);
        }

        // odd-indexed P values: P[1], P[3], ...
        if (n >= 1) {
            runMax = P[1];
            for (int idx = 3; idx <= n; idx += 2) {
                best = max(best, runMax - P[idx]);
                runMax = max(runMax, P[idx]);
            }
        }

        long long extra = (best == LLONG_MIN) ? 0 : max(0LL, 2 * best);
        return P[n] + extra;
    }
};