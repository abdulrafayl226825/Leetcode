class Solution {
public:
    int countArrays(vector<int>& orignal, vector<vector<int>>& bounds) {
        int l = bounds[0][0],r = bounds[0][1];
        int n = orignal.size();
        for(int i=1;i<n;i++)
        {
            auto diff = orignal[i]-orignal[i-1];
            auto nl =l+ diff ;
            auto nr =r+ diff ;
            l = max(nl,bounds[i][0]);
            r = min(nr , bounds[i][1]);
            if(l>r) return 0;
        }
        return r-l+1;
    }
};