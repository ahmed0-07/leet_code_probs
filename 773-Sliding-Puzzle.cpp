class Solution {
public:
    string ans = "123450";
    vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    int slidingPuzzle(vector<vector<int>>& board) {
        string s = "";
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                s += board[i][j] + '0';
            }
        }

        if(s == ans)
            return 0;
        queue<string> q;
        unordered_set<string> se;
        q.push(s);

        for(int level = 0, sz = q.size(); !q.empty(); level++, sz = q.size())
        {
            while(sz--)
            {
                string cur = q.front();
                q.pop();

                int idx = cur.find('0');

                for(int i : dir[idx])
                {
                    swap(cur[i], cur[idx]);

                    if(cur == ans)
                        return level + 1;

                    if(se.insert(cur).second)
                        q.push(cur);

                    swap(cur[i], cur[idx]);
                }
            }
        }
        return -1;
    }
};