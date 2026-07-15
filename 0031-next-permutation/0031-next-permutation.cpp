class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int s = nums.size();
        int  i = 0;
        for(i = s-1;i>0;i--)
        {
            if(nums[i-1]<nums[i]) break;
        }if(i!=0)i--;
        else{
            reverse(nums.begin(),nums.end());
            return;
        }
        int j = s-1;
        for(j = s-1;j>=0;j--)
        {
            if(nums[j]>nums[i]) break;
         }if(j==-1) j = 0;
        cout<<nums[j];
        int a = nums[i];
        nums[i] = nums[j];
        nums[j] = a;
        reverse(nums.begin()+i+1,nums.end());
            }
};