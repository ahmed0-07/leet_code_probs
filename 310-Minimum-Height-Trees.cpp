class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        if(n == 1)
            return {0};
        vector<int> ans;
        vector<int> indeg(n);
        vector<vector<int>> adj(n);
        for(int i = 0; i < e.size(); i++)
        {
            indeg[e[i][0]]++;
            indeg[e[i][1]]++;
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indeg[i] == 1)
            {
                q.push(i);
            }
        }

        while(n > 2)
        {
            int level_n = q.size();
            n -= level_n;

            while(level_n--)
            {
                int u = q.front();
                q.pop();

                for(int& x : adj[u])
                {
                    indeg[x]--;
                    if(indeg[x] == 1)
                        q.push(x);
                }
            }
        }

        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};