class Solution {
public:
    /*initially we open initial boxes and take all keys
    mark all boxes with keys as can be opend
    take candies
    then we open all boxes inside initail boxes
    take the keys and mark
    */

    int maxCandies(vector<int>& has_key, vector<int>& c, vector<vector<int>>& k, vector<vector<int>>& cb, vector<int>& ib) {
        queue<int> q;
        vector<int> vis(k.size(), 0);
        int candies = 0;
        for(int box : ib)
        {
            for(int key : k[box])
                has_key[key] = 1;
        }

        for(int box : ib)
        {
            if(!vis[box] && has_key[box])
            {
                q.push(box);
                vis[box] = 1;
                candies += c[box];
            }
        }

        while(!q.empty())
        {
            int b = q.front();
            q.pop();

            for(int box : cb[b])
            {
                for(int key : k[box])
                    has_key[key] = 1;
            }

            for(int box : cb[b])
            {
                if(!vis[box] && has_key[box])
                {
                    q.push(box);
                    vis[box] = 1;
                    candies += c[box];
                }
            }
        }

        return candies;
    }
};