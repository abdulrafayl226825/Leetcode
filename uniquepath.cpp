#include <bits/stdc++.h>
using namespace  std;
   int dp[101][101]{};
    int recursive(vector<vector<int>>& nums,int i,int j ,int m, int n)
    {
        if(i>=m || j >= n) return 0;
        if(nums[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j]=recursive(nums,i+1,j,m,n)+recursive(nums,i,j+1,m,n);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        return recursive(nums,0,0,nums.size(),nums[0].size());
    }
int main()
{
  vector<vector<int>> dp{{0,0,0},{0,1,0},{0,0,0}};
  cout<<uniquePathsWithObstacles(dp)<<endl;
}
