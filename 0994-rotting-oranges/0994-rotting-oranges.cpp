class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<bool> visited(n * m, false);
        int ncount = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i * m + j] = true;
                }
                if(grid[i][j] == 1) ncount++;
            }
        }
        
        if (ncount == 0) return 0;

        int iter = 0;
        
        while(!q.empty() && ncount > 0)
        {
            int sz = q.size();
            for(int s = 0; s < sz; s++) {
                pair<int,int> x = q.front();
                q.pop();
                int i = x.first;
                int j = x.second;
                
                if(i + 1 < n && grid[i+1][j] == 1 && !visited[(i+1) * m + j]) 
                {
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                    visited[(i+1) * m + j] = true;
                    ncount--;
                }
                if(i - 1 >= 0 && grid[i-1][j] == 1 && !visited[(i-1) * m + j])
                {
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                    visited[(i-1) * m + j] = true;
                    ncount--;
                }
                if(j + 1 < m && grid[i][j+1] == 1 && !visited[i * m + (j+1)]) 
                {
                    q.push({i, j+1});
                    grid[i][j+1] = 2;
                    visited[i * m + (j+1)] = true;
                    ncount--;
                }
                if(j - 1 >= 0 && grid[i][j-1] == 1 && !visited[i * m + (j-1)])
                {
                    q.push({i, j-1});
                    grid[i][j-1] = 2;
                    visited[i * m + (j-1)] = true;
                    ncount--;
                }
            }
            iter++;
        }
        return (ncount == 0) ? iter : -1;
    }
};