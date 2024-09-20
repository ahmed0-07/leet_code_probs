class Solution {
public:
    vector<int> v;
    int dp[5002][2][3];
    int fun(int idx, int have, int to)
    {
        if(idx >= v.size())
            return 0;

        if(dp[idx][have][to] != -1)
            return dp[idx][have][to];

        int ch1 = 0, ch2 = 0, ch3 = 0;
        ch1 = fun(idx+1, have, 0);
        if(have)
            ch2 = v[idx] + fun(idx+1, 0, 2);
        else if(to != 2)
            ch3 = -v[idx] + fun(idx+1, 1, 1);

        return dp[idx][have][to] = max(ch1, max(ch2, ch3));
    }
    int maxProfit(vector<int>& prices) {
        v = prices;
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, 0);
    }
};