class Solution {
public:
    int maxArea(vector<int>& a) {
        auto n = a.size();
        int l = 0 , r= n-1;
        int mx=0;
        while(l<r)
        {
            mx=max(mx,(r-l)*min(a[r],a[l]));
            if(a[r]>a[l]) l++;
            else r--;
        }
        return mx;
    }
};