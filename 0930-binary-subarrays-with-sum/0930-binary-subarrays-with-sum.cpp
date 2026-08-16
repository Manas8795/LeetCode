class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefix_freq;
        prefix_freq[0] = 1;
        
        int current_sum = 0;
        int count = 0;
        
        for (int num : nums) {
            current_sum += num;
            
            int needed_prefix = current_sum - goal;
            if (prefix_freq.find(needed_prefix) != prefix_freq.end()) {
                count += prefix_freq[needed_prefix];
            }
            
            prefix_freq[current_sum]++;
        }
        
        return count;
    }
};