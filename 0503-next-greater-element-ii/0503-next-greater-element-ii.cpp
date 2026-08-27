class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> fin(nums.size());
        stack<int> s;
        for(int i = 2*nums.size()-1;i>=0;i--)
        {
            while(!s.empty() && nums[i%nums.size()]>=s.top())
            {
                s.pop();
            }
            if(i<nums.size())
            {
                if(s.empty()) fin[i] = -1;
                else
                {
                    fin[i] = s.top();
                }
            }
            s.push(nums[i%nums.size()]);
        }
        return fin;
    }
};