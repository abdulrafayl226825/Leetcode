class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
    sort(env.begin(),env.end(),[&](const vector<int> & a , const vector<int>& b) 
    {
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    });
        for(auto & i : env)
            cout << i[0]<<"  "<<i[1]<<endl;
        int n = env.size();
        vector<int> lis;
        for(int i=0;i<n;i++)
        {
            int idx = lower_bound(lis.begin(),lis.end(),env[i][1])-lis.begin();
            if(idx>=lis.size()) lis.push_back(env[i][1]);
            else
                lis[idx]=env[i][1];
        }


        return lis.size();
    }
};