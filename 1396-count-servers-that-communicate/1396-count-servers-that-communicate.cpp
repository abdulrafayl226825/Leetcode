class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        auto check_row = [&](int i )
        {
            int cnt =0;
            int cmp =0;
            
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) cmp++;
            }
            if(cmp <= 1) return 0;
            for(int j=0;j<m;j++)
            {
                if(visited[i][j] && grid[i][j]==1) cmp--;
                visited[i][j]=true;
            }
            return cmp;
        };
        auto check_col = [&]( int j )
        {
            int cnt =0;
            int cmp =0;
            int i ;
            for( i=0;i<n;i++)
            {
                if(grid[i][j]==1) cmp++;
            }
            if(cmp <= 1) return 0;
            for(int i=0;i<n;i++)
            {
                if(visited[i][j] && grid[i][j]==1) cmp--;
                visited[i][j]=true;
            }
            return cmp;
        };
        int x=min(n,m);
        int score =0;
        for(int i=0;i<x;i++)
        {
            score+=check_row(i)+check_col(i);
        }
        if(n>m)
        {
            for(int i=m;i<n;i++)
            {
                score+=check_row(i);
            }
        }
        else
            for(int i=n;i<m;i++)
            {
               score+= check_col(i);
            }
        return score;
    }
};