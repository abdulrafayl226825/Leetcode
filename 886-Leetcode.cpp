#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
bool function(int n, vector<vector<int>> dislikes) {
  unordered_set<int> a;
  unordered_set<int> b;
  for (auto &i : dislikes) {
    if ((a.find(i[0]) != a.end()) && a.find(i[1]) != a.end())
      return false;
    if ((b.find(i[0]) != b.end()) && b.find(i[1]) != b.end())
      return false;
    if (a.find(i[0]) != a.end())
      b.insert(i[1]);
    else if (b.find(i[0]) != b.end())
      a.insert(i[1]);
    else if (a.find(i[1]) != a.end())
      b.insert(i[0]);
    else if (b.find(i[1]) != b.end())
      a.insert(i[0]);
  }
  return true;
}

int main() {}
