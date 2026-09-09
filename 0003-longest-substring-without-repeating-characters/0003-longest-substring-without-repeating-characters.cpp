class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(128, -1); // ASCII index -> last seen position
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }
            lastSeen[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};