class Solution {
public:
    vector<int> v;
    int dp[305][5005];

    int f(int idx, int a)
    {
        if(a < 0)
            return 0;

        if(a == 0)
            return 1;

        if(idx == v.size())
            return 0;

        if(dp[idx][a] != -1)
            return dp[idx][a];

        int leave = f(idx+1, a);
        int take = f(idx, a - v[idx]); // take this value again

        return dp[idx][a] = leave + take;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        v = coins;
        return f(0, amount);
    }
};