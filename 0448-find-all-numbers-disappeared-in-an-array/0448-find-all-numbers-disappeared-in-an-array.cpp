class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1; // map value to 0-indexed position
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx]; // mark as seen
            }
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1); // never marked -> this number is missing
            }
        }

        return ans;
    }
};