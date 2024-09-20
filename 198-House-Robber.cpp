class Solution {
public:
    vector<int> v;
    int dp[401];

    int fun(int idx)
    {
        if(idx >= v.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int ch1 = fun(idx+1);
        int ch2 = v[idx] + fun(idx+2);
        return dp[idx] = max(ch1, ch2);
    }
    int rob(vector<int>& nums) {
        v = nums;
        memset(dp, -1, sizeof(dp));
        return fun(0);
    }
};