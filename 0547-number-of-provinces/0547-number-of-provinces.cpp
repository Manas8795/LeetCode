class Solution {
public:
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();
        int count = 0;
        vector<int> vis(n,0);

        for(int i = 0;i<n;i++)
        {
            if(vis[i]!=1)
            {
                count++;
                x(vis,nums,i);
            }
        }
        return count;
    }
    void x(vector<int>& vis,const vector<vector<int>> &nums,int i)
    {
        vis[i] = 1;
        for(int j = 0;j<nums[i].size();j++)
        {
            if(nums[i][j] ==1 && vis[j]!=1 )
            {
                x(vis,nums,j);
            }
        }
    }
};