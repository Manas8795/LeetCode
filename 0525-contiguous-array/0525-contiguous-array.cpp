class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> first_index;
        first_index[0] = -1;
        
        int sum = 0;
        int max_len = 0;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            sum += (nums[i] == 1) ? 1 : -1;
            
            if (first_index.find(sum) != first_index.end()) 
            {
                max_len = max(max_len, i - first_index[sum]);
            } 
            else 
            {
                first_index[sum] = i;
            }
        }
        
        return max_len;
    }
};