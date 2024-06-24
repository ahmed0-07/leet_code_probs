class Solution {
public:
    bool is = true;
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    int cnt = 0;

    void dfs(vector<vector<int>>& g, vector<vector<int>>& vis, int i, int j)
    {
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++)
        {
            int x = i + dr[k];
            int y = j + dc[k];

            if(x < 0 || y < 0 || x == g.size() || y == g[0].size())
            {
                is = false;
                continue;
            }

            if(g[x][y] == 1 || vis[x][y])
                continue;

            dfs(g, vis, x, y);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size()));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(!grid[i][j] && !vis[i][j])
                {
                    dfs(grid, vis, i, j);
                    if(is)
                        cnt++;
                    else
                        is = true;
                }
            }
        }
        return cnt;
    }
};