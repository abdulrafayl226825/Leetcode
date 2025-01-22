class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>> q;
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1)
                  q.push({i,j});
            }
        }
        int x = 0;
        while(!q.empty())
        {
            auto k = q.size();
            while(k--)
            {
                auto [i,j] = q.front();q.pop();
                if(ans[i][j]!=-1) continue;
                ans[i][j]=x;
                if(i>0)
                q.push({i-1,j});
                if(j>0)
                q.push({i,j-1});
                if(i<n-1 && i >= 0)
                q.push({i+1,j});
                if(j<m-1 && j >=0)
                q.push({i,j+1});

            }
            x++;
        }
        return ans;
    }
};