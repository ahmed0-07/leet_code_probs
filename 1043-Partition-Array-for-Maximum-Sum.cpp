class Solution {
public:
    int dp[505];
    vector<int> v;
    int n;
    int f(int idx)
    {
        if(idx >= v.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int k = 0;
        int sum = 0;
        int mx = 0;
        for(int i = idx; i < v.size(); i++)
        {
            k++;
            mx = max(mx, v[i]);
            if(k > n)
                break;

            dp[idx] = max(dp[idx], (mx * k) + f(i+1));
        }

        return dp[idx];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        n = k;
        v = arr;
        return f(0);
    }
};