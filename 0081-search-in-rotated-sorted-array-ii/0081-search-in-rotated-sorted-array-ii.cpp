class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int x = 0;
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                x = i+1;
                break;
            }
        }
        cout<<x;
        // return true;
        int l1 = 0;
        int r1 = x-1;
        int l2 = x;
        int r2 = nums.size() - 1;
        while(l1<=r1)
        {
            int mid = l1 + (r1-l1)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid]>target) r1 = mid - 1;
            else l1 = mid + 1;
        }
        while(l2<=r2)
        {
            int mid = l2 + (r2-l2)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid]>target) r2 = mid - 1;
            else l2 = mid + 1;
        }
        return false;
    }
};