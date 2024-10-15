class Solution {
public:
    int dp[10005];
    unordered_set<long long> s;
    int f(int n)
    {
        if(n <= 0)
            return 0;

        if(dp[n] != -1)
            return dp[n];

        int mn = INT_MAX;
        for(int i = 1; i * i <= n; i++)
        {
            mn = min(mn, 1 + f(n - (i * i)));
        }

        return dp[n] = mn;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n);
    }
};