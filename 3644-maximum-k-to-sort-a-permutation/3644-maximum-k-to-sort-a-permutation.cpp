class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        int k = INT_MAX;

        for(int i = 0;i<n;i++)
        {
            if(sorted[i]!=nums[i]) k = k & nums[i];
        }
        if(k == INT_MAX) return 0;
        return k;
    }
};