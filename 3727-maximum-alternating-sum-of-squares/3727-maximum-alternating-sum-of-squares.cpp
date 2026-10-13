class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long sum = 0;
        for(int i = 0;i<=(n-1)/2;i++)
        {
            if((n-i-1) == i)
            {
                sum += 1LL * nums[i]*nums[i];
            }
            else
            {
                sum += (1LL * nums[n-1-i]*nums[n-1-i] - 1LL * nums[i] * nums[i]);
            }
        }
        return sum;
    }
};