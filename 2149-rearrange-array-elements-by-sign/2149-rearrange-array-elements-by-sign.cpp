class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int s = nums.size();
       vector<int> n1;
       vector<int> n2;
       for(int i = 0;i<s;i++)
       {
            if(nums[i]>0) n1.push_back(nums[i]);
            else n2.push_back(nums[i]);
       } cout<<n1[0];
       int j= 0;
       for(int i=0;i<s/2;i++)
       {
        nums[j++] = n1[i];
        nums[j++] = n2[i];
       }
       return nums;
    }
};