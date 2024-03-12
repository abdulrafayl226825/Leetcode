#include "bits/stdc++.h"
#include <vector>
using namespace std;
vector<int> singleNumber(vector<int> nums) {
  unordered_map<int, int> mp;
  for (auto &i : nums) {
    mp[i]++;
  }
  vector<int> ans(2);
  int count = 0;
  for (auto &[i, j] : mp) {
    if (j == 1)
      ans[count++] = i;
  }
  return ans;
}

int main() {
  auto x = singleNumber({1, 2, 1, 3, 2, 5});
  for (auto &i : x)
    cout << i << "  ";
}
