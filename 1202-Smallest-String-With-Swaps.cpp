class Solution {
public:
    vector<int> idx;
    vector<vector<int>> adj;
    void dfs(int n, vector<int>& vis)
    {
        vis[n] = 1;
        idx.push_back(n);
        for(auto x : adj[n])
        {
            if(!vis[x])
                dfs(x, vis);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> vis(n);
        adj.resize(n);
        for(int i = 0; i < pairs.size(); i++)
        {
            adj[pairs[i][0]].push_back(pairs[i][1]);
            adj[pairs[i][1]].push_back(pairs[i][0]);
        }

        for(int i = 0; i < s.size(); i++)
        {
            if(!vis[i])
            {
                dfs(i, vis);
                string str;

                for(int id : idx)
                    str += s[id];

                sort(idx.begin(), idx.end());
                sort(str.begin(), str.end());

                for(int j = 0; j < idx.size(); j++)
                    s[idx[j]] = str[j];

                idx.clear();
            }
        }
        return s;
    }
};