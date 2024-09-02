class Solution {
public:
    //its about longest path 
    //which path will take the longest time to finish all courses
    //you need to push time taken by a node to the next node
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indeg(n+1);
        queue<int> q;

        for(int i = 0; i < r.size(); i++)
        {
            adj[r[i][0]].push_back(r[i][1]);
            indeg[r[i][1]]++;
        }

        for(int i = 1; i <= n; i++)
        {
            if(!indeg[i])
                q.push(i);
        }

        vector<int> comptime(n+1);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            comptime[u] += time[u-1];

            for(auto& x : adj[u])
            {
                indeg[x]--;
                if(!indeg[x])
                    q.push(x);

                comptime[x] = max(comptime[x], comptime[u]);
            }
        }

        return *max_element(comptime.begin(), comptime.end());
    }
};