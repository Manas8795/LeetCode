class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        int k = INT_MAX;
        bool f = false;
        for(int i = 0;i<n;i++)
        {   
            if(nums[i]!= i) 
            {
                k = k & nums[i];
            }            
        }
        if(k == INT_MAX) return 0;
        return k;
    }
};