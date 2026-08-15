class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0;
        int count = 0;
        for(int i : nums)
        {
            if(i!=0) count++;
            total = total ^ i;
        }
        if(total != 0 )return nums.size();
        if(count!=0) return nums.size()-1;
        return 0;
        
    }
};