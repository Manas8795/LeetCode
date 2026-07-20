class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // cout<<n;
        // cout<<m;
        vector<int> i1;
        vector<int> j1;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    i1.push_back(i);
                    j1.push_back(j);
                }
            }
        }
        for(int i = 0;i<i1.size();i++)
        {
            for(int j = 0;j<n;j++)
            {
                matrix[i1[i]][j]=0;
            }
        }
        for(int j = 0;j<j1.size();j++)
        {
            for(int i = 0;i<m;i++)
            {
                matrix[i][j1[j]]=0;
            }
        }
        
    }
};