class Solution {
public:
   vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
  int n = nums.size();
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < nums.size(); i++) {
    mp[nums[i]].push_back(i);
  }
  sort(nums.begin(), nums.end());
  int i = 0, j = 1;
  vector<int> ans(n);
  auto fun = [&](int i, int j) {
    if(i==j)
    {
        ans[mp[nums[i]][0]] = nums[i];
        return;
    }
    // cout << i << " " << j << endl;
    int k = i;
    set<int> indices;
    for (int l = i; l < j; l++) {
      if (  nums[l] != nums[l + 1]) {
        for (auto &x : mp[nums[l]]) {
          // cout << x << " ";
          indices.insert(x);
        }
      }
    }
    for (auto &x : mp[nums[j]]) {
          // cout << x << " ";
          indices.insert(x);
    }
      
    // sort(indices.begin(), indices.end());

    for (auto &x : indices) {
      ans[x] = nums[k++];
    }
  };
  int st = 0;
  while (j < n) {
    if ((nums[j] - nums[i]) <= limit) {
      j++;
      i++;
    } else {
      fun(st, j - 1);
      st = j;
      i = j++;
    }
  }
  fun(st, j - 1);
  return ans;
}


};