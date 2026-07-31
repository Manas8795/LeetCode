    class Solution {
    public:
        int minDays(vector<int>& b, int m, int k) {
            long long total = (long long)m * k;
            if (total > b.size()) return -1;
            int max= b[0];
            for(int n : b)
            {
                if(max < n)
                {
                    max = n;
                }
            }
            int h = max;
            int l = 1;
            while(l<=h)
            {
                int mid = l + (h-l)/2;
                cout<<mid<<" ";
                int x = 0;
                int y = 0;
                for(int n:b)
                {
                    if(n<=mid)
                    {
                        x+=1;
                        if(x==k)
                        {
                            y++;
                            x = 0;
                        }
                    }
                    else
                    {
                        x= 0;
                    }
                }
                cout<<","<<y<<" ";
                if(y<m) l = mid+1;
                else h = mid-1;
            }
            return l;
        }
    };