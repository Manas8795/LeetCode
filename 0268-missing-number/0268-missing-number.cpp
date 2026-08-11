class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> fre;
        for(int i : nums)
        {
            fre[i]++;
        }
        int i = 0;
        while(true)
        {
            if(fre[i]>0)
            {
                i++;
            }
            else
            {
                return i;
            }
        }
        return 0;
    }
};