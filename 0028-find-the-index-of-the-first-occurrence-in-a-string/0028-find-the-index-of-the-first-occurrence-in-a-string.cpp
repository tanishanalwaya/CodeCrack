class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;

        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (needle[i] == needle[len]) {
                lps[i] = ++len;
                i++;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }

        int hIdx = 0, nIdx = 0;
        while (hIdx < n) {
            if (haystack[hIdx] == needle[nIdx]) {
                hIdx++;
                nIdx++;
                if (nIdx == m) return hIdx - m;
            } else if (nIdx > 0) {
                nIdx = lps[nIdx - 1];
            } else {
                hIdx++;
            }
        }
        return -1;
    }
};