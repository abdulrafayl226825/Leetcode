class Solution {
public:
 class UnionFind {
  vector<int> parent, rank;

public:
  UnionFind(int size) {
    parent.assign(size + 1, 0);
    rank.assign(size + 1, 0);
    for (int i = 0; i < size; i++)
      parent[i] = i;
  }
  int find(int i) {
    if (parent[i] != i)
      parent[i] = find(parent[i]);
    return parent[i];
  }
  void Union(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    if (xroot == yroot)
      return;
    if (rank[xroot] < rank[yroot]) {
      parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
      parent[yroot] = xroot;
    } else {
      parent[xroot] = yroot;
      rank[yroot]++;
    }
  }
};

vector<int> findRedundantConnection(vector<vector<int>> &edges) {

  int n = edges.size();
  UnionFind dsu(n);
  for (auto &i : edges) {
    if (dsu.find(i[0]) == dsu.find(i[1]))
      return {i};
    dsu.Union(i[0], i[1]);
  }
  return {};
}

};