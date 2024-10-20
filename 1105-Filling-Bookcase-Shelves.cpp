class Solution {
public:
    int dp[1005];
    int shelf;
    vector<vector<int>> b;
    int f(int idx)
    {
        if(idx >= b.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];
        
        int wid = 0;
        int max_h = 0;
        dp[idx] = INT_MAX;
        for(int i = idx; i < b.size(); i++)
        {
            wid += b[i][0];
            max_h = max(max_h, b[i][1]);
            if(wid > shelf)
                break;

            dp[idx] = min(dp[idx], max_h + f(i+1));
        }

        return dp[idx];
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        b = books;
        shelf = shelfWidth;
        return f(0);
    }
};