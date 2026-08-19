class Solution {
    int MOD = 1e9 + 7;
public:

    int countGoodNumbers(long long n) {
        long long evencount = (n+1)/2;
        long long  oddcount = n/2;
        long long ew = xpow(5,evencount);
        long long ow = xpow(4,oddcount);
        return (ow *ew ) % MOD;
    }
    long long xpow(int x, long long n) 
    {
        long long N = n;
        if(N<0)
        {
            x = 1/x;
            N = -N;
        }
        return solve(x,N);
    }
    long long solve(int x,long long n)
    {
        if(n == 0) return 1;
        long long  half = solve(x,n/2);
        if(n%2 == 0)
        {
            return (half * half) % MOD;
        }
        else
        {
            return (half * half * x) % MOD;
        }
    }
};