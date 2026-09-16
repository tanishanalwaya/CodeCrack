class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);

        // Count occurrences of each value
        for (int num : nums) {
            count[num]++;
        }

        // Prefix sum: count[v] becomes "how many numbers are < v"
        for (int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = (nums[i] == 0) ? 0 : count[nums[i] - 1];
        }

        return ans;
    }
};