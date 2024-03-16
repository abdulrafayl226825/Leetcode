#include "bits/stdc++.h"
using namespace std;
int findMaxLength(std::vector<int> &nums) {
  unordered_map<int, int> sumMap;
  int maxLength = 0;
  int sum = 0;

  sumMap[0] = -1;

  for (int i = 0; i < nums.size(); ++i) {
    sum += (nums[i] == 1) ? 1 : -1;
    if (sumMap.find(sum) != sumMap.end()) {
      maxLength = max(maxLength, i - sumMap[sum]);
    } else {
      sumMap[sum] = i;
    }
  }
  return maxLength;
}
int main() {
  vector<int> nums{0, 0, 1, 0, 0, 0, 1, 1};
  cout << findMaxLength(nums) << endl;
}
