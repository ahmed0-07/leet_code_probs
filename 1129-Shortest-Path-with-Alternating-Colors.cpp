class Solution {
public:
struct edge{
    int to;
    int co;
};
    const int red = 0;
    const int blue = 1;
    const int oo = 10000000;
    vector<vector<edge>> adj;
    queue<edge> q;
    void bfs(vector<int>& ans, vector<vector<int>>& len)
    {
        q.push({0, red});
        q.push({0, blue});
        
        for(int level = 0, sz = q.size(); !q.empty(); level++, sz = q.size())
        {
            while(sz--)
            {
                int n = q.front().to;
                int c = q.front().co;
                q.pop();

                for(auto& e : adj[n])
                {
                    if(e.co != c && len[e.to][e.co] == oo)
                    {
                        q.push(e);
                        len[e.to][e.co] = level + 1;
                        if(ans[e.to] == -1)
                            ans[e.to] = level + 1;
                    }
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        vector<int> ans(n, -1);
        vector<vector<int>> len(n, vector<int> (2, oo));
        adj.resize(n);
        ans[0] = 0;

        for(int i = 0; i < r.size(); i++)
        {
            adj[r[i][0]].push_back({r[i][1], red});
        }

        for(int i = 0; i < b.size(); i++)
        {
            adj[b[i][0]].push_back({b[i][1], blue});
        }

        bfs(ans, len);
        return ans;
    }
};