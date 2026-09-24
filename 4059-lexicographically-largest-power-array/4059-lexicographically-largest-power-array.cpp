class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        vector<pair<int,int>> groups = {{0, n}};
        vector<int> power(15, 0);

        for (int bit = 14; bit >= 0; bit--) {
            vector<pair<int,int>> newGroups;
            newGroups.reserve(groups.size() + 1);
            bool extending = true;
            long long runLength = 0;

            for (auto& g : groups) {
                int s = g.first, e = g.second;
                if (extending) {
                    auto boundary = partition(arr.begin() + s, arr.begin() + e,
                                               [bit](int v) { return (v >> bit) & 1; });
                    int setCount = boundary - (arr.begin() + s);
                    runLength += setCount;
                    if (setCount == e - s) {
                        newGroups.push_back({s, e}); // entirely passes, keep extending
                    } else {
                        if (setCount > 0) newGroups.push_back({s, s + setCount});
                        newGroups.push_back({s + setCount, e});
                        extending = false;
                    }
                } else {
                    newGroups.push_back({s, e}); // carried over unchanged
                }
            }
            power[14 - bit] = (int)runLength;
            groups = move(newGroups);
        }
        return power;
    }
};