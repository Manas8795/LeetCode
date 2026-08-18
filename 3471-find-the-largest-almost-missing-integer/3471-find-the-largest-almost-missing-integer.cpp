class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == nums.size())
        {
            int maxi = nums[0];
            for(int n : nums) maxi = max(n,maxi);
            return maxi;
        }
        int x = k;
        unordered_map<int,int> freq;
        for(int i = 0;i<nums.size()-k+1;i++)
        {
            unordered_set<int> window;
            for (int j = i; j < i + k; j++) {
                window.insert(nums[j]);
            }
            for (int val : window) {
                freq[val]++;
            }
        }
        int maxi = -1;
        for(auto& [key,value] : freq)
        {
            if(value == 1)
            {
                maxi = max(maxi,key);
            }
        }
        return maxi;
    }
};