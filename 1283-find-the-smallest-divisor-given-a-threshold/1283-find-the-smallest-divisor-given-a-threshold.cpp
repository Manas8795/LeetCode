class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int max = nums[0];
        for(int n : nums)
        {
            if(n>max) max = n;
        }
        // cout<<max;
        int h = max + 1;
        int l = 1;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            long long x= 0;
            cout<<mid<<",";
            for(int n:nums)
            {
                x += (n+mid-1)/mid;
            }
            cout<<x<<" ";
            if(x>t) l = mid+1;
            else h = mid-1;
        }
        return l;
    }
};