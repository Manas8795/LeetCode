class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1 || nums[0] < nums[n - 1]) {
            return nums[0];
        }

        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }

            if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            if (nums[l] <= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return nums[0];
    }
};