class Solution {
public:
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