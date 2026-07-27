class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> nums(n);
        for(int i = 0;i<n;i++)
        {
            nums[i].resize(i+1);
            for(int j = 0;j<=i;j++)
            {
                if(j>0 && j<i)nums[i][j] = nums[i-1][j] + nums[i-1][j-1];
                else nums[i][j] = 1;
            }
        }
        return nums;
    }
};