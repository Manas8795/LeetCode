class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int maxsum = INT_MIN;
        if(k == nums.size())
        {
            int sum = 0;
            for(int i : nums) sum += i;
            return sum;
        }
        int rsum = 0,lsum = 0,rindex = 0;
        for(int i = 0;i<k;i++) 
        {
            lsum += nums[i];
        }
        maxsum = max(maxsum,lsum);
        rindex = nums.size()-1;
        for(int i = k-1;i>=0;i--)
        {
            lsum = lsum - nums[i];
            rsum = rsum + nums[rindex--];
            maxsum = max(maxsum,lsum + rsum);
        }
        return maxsum;
    }
};