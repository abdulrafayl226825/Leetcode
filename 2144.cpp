#include "bits/stdc++.h"
#include <algorithm>
using namespace std;
int minimumCost(vector<int> &cost) {

  sort(cost.begin(), cost.end(),
       [](const int a, const int b) { return a > b; });
  // reverse(cost.begin(),cost.end());
  int price = 0;
  for (int i = 0, n = cost.size(); i < n; i++) {
    price = cost[i++] + cost[i++];
  }
  return price;
}
int main() {
  vector<int> m{6, 5, 7, 9, 2, 2};
  cout << minimumCost(m);
}
