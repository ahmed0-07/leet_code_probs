class Solution {
public:
    map<int, vector<int>> adj;
    map<int, int> vis;
    vector<int> res;
    void dfs(int n)
    {
        vis[n] = 1;
        res.push_back(n);
        for(auto& x : adj[n])
        {
            if(!vis[x])
                dfs(x);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& a) {
        for(int i = 0; i < a.size(); i++)
        {
            adj[a[i][0]].push_back(a[i][1]);
            adj[a[i][1]].push_back(a[i][0]);
        }

        for(auto& j : adj)
        {
            if(j.second.size() == 1)
            {
                dfs(j.first);
                break;
            }
        }

        return res;
    }
};