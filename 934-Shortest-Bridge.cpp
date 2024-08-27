class Solution {
public:
    int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    int dy[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    queue<pair<int, int>> q;

    void dfs(vector<vector<int>>& arr, int i, int j, int old = 1, int new_color = 2)
    {
        arr[i][j] = new_color;
        q.push({i, j});
        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if(x < 0 || x >= arr.size() || y < 0 || y >= arr[0].size() || arr[x][y] != old)
                continue;

            dfs(arr, x, y);
        }
    }

    int bfs(vector<vector<int>>& arr)
    {
        for(int level = 0, sz = q.size(); !q.empty(); level++, sz = q.size())
        {
            while(sz--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x < 0 || x >= arr.size() || y < 0 || y >= arr[0].size() || arr[x][y] == 2 || arr[x][y] == 3)
                        continue;

                    if(arr[x][y] == 1)
                        return level;

                    arr[x][y] = 3;
                    q.push({x, y});
                }
            }
        }
        return 0;
    }

    int shortestBridge(vector<vector<int>>& g) {
        bool is = true;
        for(int i = 0; i < g.size(); i++)
        {
            for(int j = 0; j < g[i].size(); j++)
            {
                if(g[i][j] == 1)
                {
                    dfs(g, i, j);
                    is = false;
                    break;
                }
            }
            if(!is)
                break;
        }

        return bfs(g);
    }
};