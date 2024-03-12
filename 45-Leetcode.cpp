#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
int jump(vector<int> &nums) {
  int n = nums.size();
  vector<int> dp(n, -1);
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (nums[i] > 0) {
      if ((nums[i] + i) >= n - 1)
        dp[i] = 1;
      else {
        int Min = INT_MAX;
        int x = nums[i];
        int h = i + 1;
        while (x > 0 && h < n - 1) {
          if (dp[h] != -1)
            Min = min(dp[h], Min);
          x--;
          h++;
        }
        if (Min > -1 && Min != INT_MAX)
          dp[i] = 1 + Min;
      }
    }
  }
  return dp[0];
}
int main() {

  vector<int> nums{5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
  cout << jump(nums) << endl;
}
