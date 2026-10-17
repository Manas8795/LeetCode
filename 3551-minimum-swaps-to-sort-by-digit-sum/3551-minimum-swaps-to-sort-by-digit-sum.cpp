class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> digitsum(n);
        int count = 0;
        for (int k = 0; k < n; ++k) 
        {
            int num = nums[k];
            int sum = 0;
            while (num > 0) 
            {
                sum += num % 10;
                num /= 10;
            }
            digitsum[k] = sum;
        }
        vector<int> p(n);
        for(int i = 0;i<n;i++) p[i] = i;
        sort(p.begin(), p.end(), [&](int a, int b) {
            if (digitsum[a] != digitsum[b]) {
                return digitsum[a] < digitsum[b];
            }
            return nums[a] < nums[b];
        });
        vector<bool> vis(n,false);
        int swaps = 0;
        for(int i = 0;i<n;i++)
        {
            if(vis[i] || p[i] == i) continue;
            int cycle_size = 0;
            int curr = i;
            while(!vis[curr])
            {
                vis[curr] = true;
                curr = p[curr];
                cycle_size++;
            }
            swaps += (cycle_size - 1 );
        }
        return swaps;
    }
};
