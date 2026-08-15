class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int size = nums.size();
        int low = nums[0];
        int high = 0;
        for(int i : nums)
        {
            low = max(low,i);
            high += i;
        }
        while(low <= high)
        {
            int M = (low + high)/2;
            int sum = 0;
            int count = 0;
            for(int i : nums)
            {
                if(sum + i > M)
                {
                    count++;
                    sum = 0;
                }
                sum +=i;
            }
            if(count+1<=k) high = M-1;
            else
            {
                low = M+1;
            }

        }
        return low;
    }
};