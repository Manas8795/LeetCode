/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool x = true;
    void c(TreeNode* p,TreeNode* q)
    {
        if(p == NULL && q == NULL) return;
        else if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
        {
            x = false;
            return;
        }
        else
        {
            if(p->val != q->val) 
            {
                x = false;
                return;
            }
            c(p->left,q->left);
            c(p->right,q->right);

        }

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        c(p,q);
        return x;
    }
};