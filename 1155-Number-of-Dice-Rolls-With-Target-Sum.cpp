class Solution {
public:
    int dp[31][1001];
    int w;
    long long f(int n, int t)
    {
        if(!n)
        {
            if(!t)
                return 1;
            else
                return 0;
        }

        if(dp[n][t] != -1)
            return dp[n][t];

        int c = 0;
        for(int i = 1; i <= w; i++)
        {
            if(i > t)
                break;

            c = (c + f(n - 1, t - i)) % 1000000007;
        }

        return dp[n][t] = c;
    }
    int numRollsToTarget(int n, int k, int target) {
        if(n == 1)
            return target >= 1 && target <= k? 1 : 0;

        memset(dp, -1, sizeof(dp));
        w = k;
        return f(n, target);
    }
};