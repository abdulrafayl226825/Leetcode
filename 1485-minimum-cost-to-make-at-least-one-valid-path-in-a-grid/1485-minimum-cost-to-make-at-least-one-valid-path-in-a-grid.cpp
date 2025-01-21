class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
        int i = 0 , j =0 ;
        queue<vector<int>> q;
        q.push({0,0,0});
        while(!q.empty())
        {
            auto k = q.size();

            while(k--)
            {
                auto x = q.front();q.pop();
                int i = x[0] , j = x[1] , c = x[2];
                if(i < 0 || i>=n || j < 0 || j >=m) continue;
                int dir = grid[i][j];
                if(visited[i][j]==true && cost[i][j] <= c ) continue; 
                visited[i][j]=true;

                    int a = c , b = c , e = c , f= c;
                    if(dir == 1) b++,e++,f++;
                    else if(dir == 2)
                    a++,b++,e++;
                    else if(dir ==3)
                    a++,b++,f++;
                    else
                    a++,e++,f++;
                    if(j != m-1)
                    if(!visited[i][j+1] || (a < cost[i][j+1])  )
                    {
                        q.push({i,j+1,a});
                    }
                    if(i>0)
                    {
                        if(!visited[i-1][j] || ( b <cost[i-1][j]) )
                            q.push({i-1,j,b});
                    }
                    if(i<n-1)
                    {
                        if(!visited[i+1][j] || ( e <cost[i+1][j]) )
                            q.push({i+1,j,e});
                    }
                    if(j>0)
                    {
                        if(!visited[i][j-1] || ( f <cost[i][j-1]) )
                            q.push({i,j-1,f});
                       
                    }
                cost[i][j]=min(cost[i][j],c);
            }
                
        }
        
        return cost[n-1][m-1];
    }
};