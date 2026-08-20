class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> fin;
        vector<int> l;  
        solve(nums,0,l,fin);
        return fin;
    }
    void solve(vector<int>& nums,int n,vector<int>& l,vector<vector<int>>& fin)
    {
        if(n == nums.size())
        { 
            fin.push_back(l); 
            return;
        }
        l.push_back(nums[n]);
        solve(nums,n+1,l,fin);
        l.pop_back();
        solve(nums,n+1,l,fin);
    }
};