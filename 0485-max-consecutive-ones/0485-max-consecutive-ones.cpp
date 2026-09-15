class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, current = 0;

        for (int num : nums) {
            if (num == 1) {
                current++;
                maxCount = max(maxCount, current);
            } else {
                current = 0;
            }
        }

        return maxCount;
    }
};