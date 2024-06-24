class Solution {
public:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    bool dfs(vector<vector<char>>& g, vector<vector<int>>& vis, int i, int j, int pi, int pj)
    {
        vis[i][j] = 1;
        bool res = false;

        for(int k = 0; k < 4; k++)
        {
            int x = i + dr[k];
            int y = j + dc[k];

            if(x < 0 || y < 0 || x == g.size() || y == g[0].size() || (x == pi && y == pj) || g[x][y] != g[i][j])
                continue;

            if(vis[x][y])
                return true;

            res |= dfs(g, vis, x, y, i, j);
        }

        return res;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size()));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(!vis[i][j])
                {
                    if(dfs(grid, vis, i, j, -1, -1))
                        return true;
                }
            }
        }
        return false;
    }
};