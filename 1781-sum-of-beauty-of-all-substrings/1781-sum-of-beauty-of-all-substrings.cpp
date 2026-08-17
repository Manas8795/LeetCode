class Solution {
public:
    int beautySum(string s) {
        int count = 0;
        for(int i = 0;i<s.size();i++)
        {
            unordered_map<char,int> freq;
            for(int j = i;j<s.size();j++)
            {
                freq[s[j]]++;
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(const auto& [key,value] : freq)
                {
                    if(value > maxi) maxi = value;
                    if(value < mini) mini = value;
                }
                count += (maxi-mini);
            }
            
           
        }
        return count;
    }
};