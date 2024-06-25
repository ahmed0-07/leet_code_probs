class Solution {
public:
    vector<vector<pair<int, bool>>> adj;
    vector<int> vis;
    int cnt = 0;

    void dfs(int n)
    {
        vis[n] = 1;
        for(auto x : adj[n])
        {
            if(!vis[x.first])
            {
                cnt += x.second;
                dfs(x.first);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& c) {
        int s = c.size();
        adj.resize(n);
        vis.resize(n);

        for(int i = 0; i < s; i++)
        {
            adj[c[i][0]].push_back({c[i][1], true});
            adj[c[i][1]].push_back({c[i][0], false});
        }

        dfs(0);
        return cnt;
    }
};