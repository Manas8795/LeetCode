class Solution {
public:
    void x(int index,vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp,int target)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i = index;i<nums.size();i++)
        {
            if(i>index && nums[i] == nums[i-1])
                continue;
            if(nums[i]>target) break;
            
            temp.push_back(nums[i]);
            x(i+1,nums,ans,temp,target-nums[i]);
            temp.pop_back();    
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        x(0,nums,ans,temp,target);
        return ans;
    }
};