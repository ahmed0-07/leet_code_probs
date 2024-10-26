class Solution {
public:
    int n, m;
    int dp[205][205];
    vector<vector<int>> v;
    int f(int i, int j)
    {
        if(i >= n || j >= m)
            return 1e8;

        if(i == n - 1 && j == m - 1)
        {
            if(v[i][j] < 0)
                return 1 - v[i][j];
            return 1;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int mn = min(f(i+1, j), f(i, j+1));

        if(v[i][j] >= mn)
            return dp[i][j] = 1;

        return dp[i][j] = mn - v[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& d) {
        n = d.size(), m = d[0].size();
        memset(dp, -1, sizeof(dp));
        v = d;
        return f(0, 0);
    }
};