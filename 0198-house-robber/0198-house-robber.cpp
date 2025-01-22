class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == 0) return nums[ind]; // base case
        if(ind < 0) return 0; // no house to rob

        if(dp[ind] != -1) return dp[ind]; // Avoiding recomputation

// Option 1: Rob the current house and add the result from the house two steps back
        int take = nums[ind] + f(ind-2,nums,dp);
// Option 2: Skip the current house and take the result from the previous house
        int notTake =  f(ind-1,nums,dp);

// Store the maximum of the two options in the dp array
        return dp[ind] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};