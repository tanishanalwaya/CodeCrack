class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1, missing = -1;

        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1; // map value to 0-indexed position
            if (nums[idx] < 0) {
                duplicate = abs(nums[i]); // already negated -> this value is the duplicate
            } else {
                nums[idx] = -nums[idx]; // mark as seen
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missing = i + 1; // this position was never marked negative
            } else {
                nums[i] = -nums[i]; // restore original array (good practice)
            }
        }

        return {duplicate, missing};
    }
};