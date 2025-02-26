class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int best_p = 0 ,  best_neg = 0;
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            best_p +=nums[i];
            best_neg+=nums[i];
            if(best_neg>0)
                best_neg = 0 ;
            if(best_p<0)
                best_p = 0 ;
            ans = max(ans , max(best_p,-best_neg));
        }
        return ans;
    }
};