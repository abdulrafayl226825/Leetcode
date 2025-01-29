class Solution {
public:
   class UnionFind {
   vector<int> rank, parent;

public:
  
    // Constructor to initialize sets
    UnionFind(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);

        // Initially, each element is in its own set
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the representative of the set that x belongs to
    int find(int x) {
        if (parent[x] != x) {
          
            // Path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union of sets containing x and y
    void Union(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        // If they are in the same set, no need to union
        if (xRoot == yRoot) return;

        // Union by rank
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[yRoot] < rank[xRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
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