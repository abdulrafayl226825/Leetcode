class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        auto dfs = [&](this auto && dfs , int i, int j) -> int {
            if (i < 0 || i >= n || j < 0 || j >= m)
                return 0;
            if (visited[i][j])
                return 0;
            visited[i][j] = true;
            if (grid[i][j] == 0)
                return 0;
            vector<pair<int, int>> dirs{
                {i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
            int my_score =0;
            for(auto & [x,y] : dirs)
            {
                my_score +=dfs(x,y);
            }
            return my_score+grid[i][j];
        };
        int mx =0;
       for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j])
                mx = max(mx , dfs(i,j));
        }
       return mx;
    }
};