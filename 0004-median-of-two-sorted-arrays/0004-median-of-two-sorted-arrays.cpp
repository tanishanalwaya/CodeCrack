class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2; // left partition size

        int lo = 0, hi = m;

        while (lo <= hi) {
            int i = (lo + hi) / 2;      // partition point in nums1
            int j = half - i;           // partition point in nums2

            int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i];
            int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];

            if (left1 <= right2 && left2 <= right1) {
                // Correct partition found
                if (total % 2 == 1) {
                    return max(left1, left2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            } else if (left1 > right2) {
                hi = i - 1; // move partition left in nums1
            } else {
                lo = i + 1; // move partition right in nums1
            }
        }

        return 0.0; // unreachable given valid inputs
    }
};