#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
void sum(TreeNode* root, int & count)
    {
        if(!root) return;
        sum(root->left,count++);
        sum(root->right,count++);
    }
int diameterOfBinaryTree(TreeNode* root) {
        int count=0; 
        sum(root,count);
        return count;
    }

void print(TreeNode* & r)
{
  if(!r) return;
  print(r->left);
  cout<<r->val<<endl;
  print(r->right);
}
int main()
{
  TreeNode* num=new TreeNode(1,TreeNode(2),TreeNode(3));
  num->left->left=TreeNode(4,TreeNode(5));
  print(num);
}
