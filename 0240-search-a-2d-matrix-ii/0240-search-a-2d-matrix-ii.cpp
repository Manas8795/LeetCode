class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n-1;
        while(i>=0 && i<m && j>=0 && j<n)
        {
            int current = matrix[i][j];
            if(target == current ) return true;
            else if(target > current)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};