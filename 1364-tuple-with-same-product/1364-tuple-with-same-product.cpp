class Solution {
public:
    int tupleSameProduct(vector<int>& a) {
        int n = a.size();

        unordered_map<int,int> mp;
        long long sc = 0;
       for(int i = 0; i<n;i++)
           for(int j= i+1;j<n;j++)
               {
               mp[a[i]*a[j]]++;
               

                   
             
           }
       for(auto [i,j] : mp)
           if(j>1)
               sc+=(j*(j-1))/2;
     return sc*8;
    }
};