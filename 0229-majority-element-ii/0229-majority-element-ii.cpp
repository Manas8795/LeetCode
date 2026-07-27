class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> M;
        vector<int> fin;
        for(int num : nums)
        {
            M[num]++;
        }
        for(auto& [key,value] : M )
        {
            if(value>nums.size()/3) fin.push_back(key);
        }
        return fin;
    }
};