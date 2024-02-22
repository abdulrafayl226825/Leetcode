#include <bits/stdc++.h>
using namespace std;
 bool canJump(vector<int>& nums) {
  int n=nums.size();
    vecor<bool> dp(n,false);
    dp[n-1]=true;
    for(int i=n-2;i>=0;i--)
    {
      if(i+nums[i]>=n-1) dp[i]=true;
        else 
        {
          for(int j=nums[i]+i;j>=i;j--)
          {
             if(dp[j]==true)
            {
              dp[i]==true; 
              break;
            } 
          }          
        }
    }

  }
int main()
{

}
