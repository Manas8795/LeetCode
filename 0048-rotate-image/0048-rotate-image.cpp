class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      for(int i = 0;i<m;i++)
      {
        for(int j = i+1;j<n;j++)
        {
            int a = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = a;
        }
      }  
      for(int j = 0;j<=(n-1)/2;j++)
      {
        for(int i = 0;i<m;i++)
        {
            int a = matrix[i][j];
            matrix[i][j] = matrix[i][n-1-j];
            matrix[i][n-1-j] = a;
        }
      }
    }
};