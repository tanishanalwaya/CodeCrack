class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int n1 = word1.size(), n2 = word2.size();
        int i = 0;

        while (i < n1 || i < n2) {
            if (i < n1) res += word1[i];
            if (i < n2) res += word2[i];
            i++;
        }
        return res;
    }
};