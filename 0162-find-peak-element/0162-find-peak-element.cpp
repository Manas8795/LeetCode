class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        int x = INT_MIN;
        int l = 1;
        int r = nums.size()-2;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid]<nums[mid+1])
            {
                l = mid+1;
            }
            else if(nums[mid]<nums[mid-1])
            {
                r = mid-1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};