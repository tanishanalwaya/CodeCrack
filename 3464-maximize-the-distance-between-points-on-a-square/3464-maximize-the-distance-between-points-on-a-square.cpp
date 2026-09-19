class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        long long S = side, P = 4 * S;
        vector<long long> pos;
        pos.reserve(points.size());

        for (auto& p : points) {
            long long x = p[0], y = p[1];
            if (y == 0)         pos.push_back(x);          // bottom edge
            else if (x == S)    pos.push_back(S + y);      // right edge
            else if (y == S)    pos.push_back(3 * S - x);  // top edge
            else                pos.push_back(4 * S - y);  // left edge (x == 0)
        }
        sort(pos.begin(), pos.end());
        int n = pos.size();

        auto check = [&](long long d) -> bool {
            for (int i = 0; i < n; i++) {
                int cur = i;
                bool ok = true;
                for (int c = 1; c < k; c++) {
                    auto it = lower_bound(pos.begin() + cur + 1, pos.end(), pos[cur] + d);
                    if (it == pos.end()) { ok = false; break; }
                    cur = it - pos.begin();
                }
                if (ok && pos[cur] + d <= pos[i] + P) return true;
            }
            return false;
        };

        long long lo = 1, hi = S, ans = 1;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (check(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return (int)ans;
    }
};