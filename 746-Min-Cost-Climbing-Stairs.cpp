class Solution {
public:
    int dp[1005];
    vector<int> c;
    int mn(int idx)
    {
        if(idx >= c.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int ch1 = c[idx] + mn(idx + 1);
        int ch2 = c[idx] + mn(idx + 2);

        return dp[idx] = min(ch1, ch2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        c = cost;
        return min(mn(0), mn(1));
    }
};