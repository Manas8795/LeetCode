class Solution {
public:
    int missingInteger(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int> fre;
        for(int i : nums)
        {
            fre[i]++;
        }
        int sum = nums[0];
        for(int i = 1;i<n;i++)
        {
            if(nums[i] == 1 + nums[i-1])
            {
                sum += nums[i];
            }else break;
        }
        cout<<sum;
        int x = sum;
        while(true)
        {
            if(fre[x]>0)
            {
                x++;
            }
            else
            {
                return x;
            }
        }
       return 0;
         
    }
};