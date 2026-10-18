#include <vector>

using namespace std;

class Solution 
{
private:
    long long MOD = 1e9 + 7;
    vector<vector<long long>> c;

    void build(int n) 
    {
        c.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) 
        {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) 
            {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
            }
        }
    }

    long long dfs(const vector<int>& v) 
    {
        int sz = v.size();
        if (sz <= 2) return 1;

        vector<int> l, r;
        for (int i = 1; i < sz; ++i) 
        {
            if (v[i] < v[0]) 
            {
                l.push_back(v[i]);
            } 
            else 
            {
                r.push_back(v[i]);
            }
        }

        long long lw = dfs(l);
        long long rw = dfs(r);

        long long ans = (c[l.size() + r.size()][l.size()] * lw) % MOD;
        ans = (ans * rw) % MOD;

        return ans;
    }

public:
    int numOfWays(vector<int>& v) 
    {
        int n = v.size();
        build(n);
        return (dfs(v) - 1 + MOD) % MOD;
    }
};