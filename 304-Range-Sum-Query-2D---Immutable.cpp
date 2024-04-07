class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& m) {
        int r = m.size();
        int c = m[0].size();

        v.resize(r + 1, vector<int>(c + 1, 0));

        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++) 
            {
                v[i][j] = m[i - 1][j - 1] + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int i, int j, int k, int l) {
        return v[k+1][l+1] - v[k+1][j] - v[i][l+1] + v[i][j];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */