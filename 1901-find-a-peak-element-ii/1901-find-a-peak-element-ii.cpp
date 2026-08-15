class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int max_col = mat[0][0];
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = (low) + (high-low)/2;
            int max_row = 0;
            for(int i =0;i<m;i++)
            {
                if(mat[max_row][mid]<mat[i][mid])
                {
                    max_row = i;
                }
            }
            int left = (mid > 0) ? mat[max_row][mid - 1] : -1;
            int right = (mid < n - 1) ? mat[max_row][mid + 1] : -1;
            if (mat[max_row][mid] > left && mat[max_row][mid] > right)
            {
                return {max_row, mid}; 
            }
            else if (right > mat[max_row][mid]) 
            {
                low = mid + 1;         
            }
            else 
            {
                high = mid - 1;        
            }
        }
        return {-1,-1};
    }
};