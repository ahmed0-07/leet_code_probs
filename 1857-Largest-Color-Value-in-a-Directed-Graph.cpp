class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& e) {
        int n = colors.size();
        vector<int> indeg(n);
        vector<vector<int>> adj(n);
        for(int i = 0; i < e.size(); i++)
        {
            adj[e[i][0]].push_back(e[i][1]);
            indeg[e[i][1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(!indeg[i])
                q.push(i);

        vector<vector<int>> co(n, vector<int> (26));
        int poped = 0;
        int ans = 0;
        while(!q.empty())
        {
            int u = q.front();
            int color = colors[u] - 'a';
            q.pop();
            poped++;
            co[u][color]++;
            ans = max(ans, co[u][color]);

            for(auto& x : adj[u])
            {
                indeg[x]--;
                if(!indeg[x])
                    q.push(x);

                for(int j = 0; j < 26; j++)
                {
                    //we max because we need the max color from each path leading to the current node
                    co[x][j] = max(co[x][j], co[u][j]);
                }
            }
        }

        if(poped != n)
            return -1;
        return ans;
    }
};
