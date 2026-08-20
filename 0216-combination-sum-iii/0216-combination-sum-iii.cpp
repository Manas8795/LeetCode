class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> l;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        int sum = 0;
        x(0,k,n,nums,l,ans,0,0);
        return ans;

    }
    void x(int i,int k,int n,vector<int>& nums,vector<int>& l,vector<vector<int>>& ans,int sum,int count)
    {
        if(sum == n && count == k )
        {
            ans.push_back(l);
            return;
        }
        if(sum == n && count!=k) return;
        if(i == nums.size()) return;
        l.push_back(nums[i]);
        count++;
        sum += nums[i];
        x(i+1,k,n,nums,l,ans,sum,count);
        l.pop_back();
        count--;
        sum-=nums[i];
        x(i+1,k,n,nums,l,ans,sum,count);
    }
};