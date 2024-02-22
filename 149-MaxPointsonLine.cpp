   int maxPoints(vector<vector<int>>& points) {
    int n=points.size();
        if(n<=2) return n;
        int ans = 0;
   
    for(auto& i:points)
    {
        unordered_map<double,int>mp;
        double x1=i[0],y1=i[1];
        for(auto &j:points)
        {   if(i==j) continue;
            double x2=j[0],y2=j[1];
            double slope;
            if(x2-x1==0)
            {
                slope=INT_MAX;
            }
            else
            {
                slope=(y2-y1)/(x2-x1);
            }
                mp[slope]++;
                ans=max(ans,mp[slope]);
        }
    }
    return ans+1;
    }
