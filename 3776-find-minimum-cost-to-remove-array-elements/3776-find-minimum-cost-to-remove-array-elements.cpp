class Solution {
public:
    int dfs(vector<int>& nums , int i , int prev , int n ,vector<vector<int>> & dp)
    {
        if(i+2 > n)
        {
            auto num = INT_MIN;
            if(i+2 < n)
                num = max(nums[i+2],num);
            if(i+1 < n)
                num = max(nums[i+1],num);
            if(i < n)
                num = max(nums[i],num);
            
            return dp[i][prev] = max(num,nums[prev]);
        }
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        auto num1 = max(nums[i],nums[i+1])+ dfs(nums,i+2,prev,n, dp);
        auto num2 = max(nums[i],nums[prev]) +     dfs(nums,i+2,i+1,n, dp);
        auto num3 = max(nums[i+1],nums[prev]) +   dfs(nums , i+2 , i,n ,dp );
        return dp[i][prev] =  min({num1,num2,num3});
    }
    int minCost(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
        {
            auto ans = -1 ;
            ans = max(ans , (n>=1)?nums[0]:-1);
            ans = max(ans , (n>=2)?nums[1]:-1);
            return ans;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        auto c1 = max(nums[0],nums[1]) + dfs(nums , 3 , 2 , n,dp);
        auto c2 = max(nums[0],nums[2]) + dfs(nums , 3 , 1 , n,dp);
        auto c3 = max(nums[2],nums[1]) + dfs(nums , 3 , 0 , n,dp);
        return min({c1,c2,c3});
    }
};