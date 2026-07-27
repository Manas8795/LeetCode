class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int> fMap;
            fMap[0] = 1;
            int currentsum = 0;
            int count = 0;
            for(int i = 0;i<nums.size();i++)
            {
                currentsum += nums[i];
                int target = currentsum - k;
                if(fMap.find(target)!=fMap.end())
                {
                    count+=fMap[target];
                }
                fMap[currentsum]++;
            }
            return count;
    }
};