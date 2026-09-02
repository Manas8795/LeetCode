class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> x(m,vector<int>(n));
        for(int j = 0;j<n;j++)
        {
            int count = 0;
            for(int i =0;i<m;i++)
            {
                if(matrix[i][j] == '1')count++;
                else count = 0;
                x[i][j] = count;
            }
        }
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<x[i][j]<<" ";
            }
            cout<<endl;
        }
        int area = 0;
        for(vector<int> i:x)
        {
            area = max(area,largestRectangleArea(i));
        }
        return area;
    }
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int maxa = 0;

        for(int i = 0; i <= h.size(); i++)
        {
            if(i == h.size())
            {
                while(!s.empty())
                {
                    int idx = s.top();
                    s.pop();

                    int left;
                    if(s.empty()) left = -1;
                    else left = s.top();

                    int width = i - left - 1;

                    maxa = max(maxa, width * h[idx]);
                }
            }
            else
            {
                while(!s.empty() && h[s.top()] > h[i])
                {
                    int idx = s.top();
                    s.pop();

                    int left;
                    if(s.empty()) left = -1;
                    else left = s.top();

                    int width = i - left - 1;

                    maxa = max(maxa, width * h[idx]);
                }

                s.push(i);
            }
        }
        return maxa;
    }
};