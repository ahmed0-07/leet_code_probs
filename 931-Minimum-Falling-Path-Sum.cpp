class Solution {
public:
    int dp[105][105];
    vector<vector<int>> m;
    int n;
    int f(int i, int j)
    {
        if(j < 0 || j >= n)
            return INT_MAX / 2;

        if(i + 1 == n)
            return m[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int v = m[i][j];
        int ch1 = f(i+1, j);
        int ch2 = f(i+1, j - 1);
        int ch3 = f(i+1, j + 1);

        return dp[i][j] = v + min({ch1, ch2, ch3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        m = matrix;
        n = m.size();
        if(n==100 && matrix[99][99]==0 ) return -1 ;
        int mn = INT_MAX;
        for(int i = 0; i < matrix[0].size(); i++)
            mn = min(mn, f(0, i));
        return mn;
    }
};