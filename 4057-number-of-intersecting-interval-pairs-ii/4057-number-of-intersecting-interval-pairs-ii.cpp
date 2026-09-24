class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> sorted_intervals = intervals; // work on a copy, sorted by start
        sort(sorted_intervals.begin(), sorted_intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        // Coordinate-compress end values
        vector<int> ends;
        ends.reserve(n);
        for (auto& iv : sorted_intervals) ends.push_back(iv[1]);
        vector<int> sortedEnds = ends;
        sort(sortedEnds.begin(), sortedEnds.end());
        sortedEnds.erase(unique(sortedEnds.begin(), sortedEnds.end()), sortedEnds.end());
        int m = sortedEnds.size();

        vector<int> bit(m + 1, 0); // Fenwick tree, 1-indexed
        auto update = [&](int i) {
            for (; i <= m; i += i & (-i)) bit[i]++;
        };
        auto query = [&](int i) { // prefix count of first i compressed ends inserted
            int s = 0;
            for (; i > 0; i -= i & (-i)) s += bit[i];
            return s;
        };

        long long answer = 0;
        int inserted = 0;

        for (auto& iv : sorted_intervals) {
            int start = iv[0], end = iv[1];

            // Number of already-inserted intervals whose end < start
            int pos = lower_bound(sortedEnds.begin(), sortedEnds.end(), start) - sortedEnds.begin();
            int lessCount = query(pos); // ends strictly before "start" in sorted order
            long long geCount = inserted - lessCount; // ends >= start: these intersect
            answer += geCount;

            // Insert this interval's end
            int rank = lower_bound(sortedEnds.begin(), sortedEnds.end(), end) - sortedEnds.begin() + 1;
            update(rank);
            inserted++;
        }
        return answer;
    }
};