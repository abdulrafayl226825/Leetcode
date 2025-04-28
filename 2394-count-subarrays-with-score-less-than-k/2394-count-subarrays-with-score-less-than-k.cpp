class Solution {
public:
    long long countSubarrays(vector<int>& a, long long k) {
        long long ans =0;
        int l = 0 , r =1;
        auto n= a.size();// 2 1 4 3 5
        if(n==1)
            return a[0]<k;
        long long sum =a[0];
        while(l<r && l < n && r < n+1 )
        {
            if((sum*(r-l))<k)
            {
                // cout << l << " " << r << "  sum : " << sum <<  endl;
                ans+=r-l;
                if(r<n)
                sum+=a[r];
                else
                    break;
                r++;
                
            }
            else
            {
                sum-=a[l];
                l++;
            }
            if(l>=r)
            {
                if(l<n)
                sum=a[l];
                else
                    break;
                r++;
            }
        }
        return ans;
    }
};