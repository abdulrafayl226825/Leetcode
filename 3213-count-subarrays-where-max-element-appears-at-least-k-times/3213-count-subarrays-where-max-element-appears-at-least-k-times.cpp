class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans =0;
        auto elem = *max_element(nums.begin(),nums.end());
        int cnt =0;
        int n = nums.size();
        int l =0,r = 0;
        while(l<=r && l < n && r < n+1)
        {
            if(l==r)
            {
                if(nums[l]==elem) cnt++;
                r++;
            }
            if(cnt>=k)
            {
                // cout << l << " " << r <<"  " << cnt<< endl;
                ans+=n-r+1;
                if(nums[l]==elem) 
                    cnt--;
                l++;
            }
            else
            {
                if(r>=n) break;
                if(nums[r]==elem)
                    cnt++;
                // cout << l << " " << r <<"  " << cnt<< endl;
                r++;
            }
           
        } 
        return ans;
    }
};