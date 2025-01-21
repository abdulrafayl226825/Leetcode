class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& a) {
        unordered_map<int,pair<int,int>> mp;
        int n = a.size();
        int m = a[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mp[a[i][j]]={i,j};
        auto chkrow =[&](int i)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(a[i][j]!=-1) return false;
                // cout << a[i][j] << " | ";
            }
            
            return true;
        };
        auto chkcol =[&](int j)
        {
            for(int i = 0 ; i < n ; i++)
            {
                if(a[i][j]!=-1) return false;
                // cout << a[i][j] << " , ";
            
            }

            return true;
        };
        vector<int> row(n,m);
        vector<int> col(m,n);
        for(int i=0;i<arr.size();i++)
        {
            if(mp.find(arr[i])!=mp.end())
            {
                a[mp[arr[i]].first][mp[arr[i]].second] = -1;
                int x = mp[arr[i]].first;
                int y = mp[arr[i]].second;
                row[x]--;
                col[y]--;
                if(row[x]<=0) return i;
                if(col[y]<=0) return i;
            }
            
        }
       
        // int k = min(n,m);
        // for(int i=0;i < k ; i++)
        // {
        //     if(chkrow(i) || chkcol(i))
        //     return i+1;
        // }
        // if(n>m)
        // {
        //     for(int i=m;i<n;i++)
        //     {
        //         if(chkrow(i)) return i+1;
        //     }
        // }
        // else
        //     for(int i=n;i<n;i++)
        //     {
        //         if(chkcol(i)) return i+1;
        //     }
        return -1;
    }
};