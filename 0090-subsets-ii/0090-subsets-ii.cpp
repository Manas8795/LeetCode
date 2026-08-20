class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> l;
        sort(nums.begin(),nums.end());
        x(0,nums,ans,l);
        map<vector<int>,int> freq;
        vector<vector<int>> fin;
        for(vector<int> i:ans)
        {
            if(freq[i]>0) continue;
            else
            {
                freq[i]++;
                fin.push_back(i);
            }
        }
        return fin;
        
    }
    void x(int i,vector<int>& nums,vector<vector<int>>& ans,vector<int>& l)
    {
        if(i == nums.size())
        {
            ans.push_back(l);
            return;
        }
        l.push_back(nums[i]);
        x(i+1,nums,ans,l);
        l.pop_back();
        x(i+1,nums,ans,l);
    }
};