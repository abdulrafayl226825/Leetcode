/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
            if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            while(s-->0)
            {
                auto x=q.front();
                q.pop();
                if(s==0)
                    x->next=nullptr;
                else
                {
                    auto y=q.front();
                    x->next=y;
                }            
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                
            }
        }
    return root;
    }
};