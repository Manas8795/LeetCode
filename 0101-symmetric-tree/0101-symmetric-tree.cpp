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
    void symcheck(TreeNode* x,TreeNode* y,bool &fin)
    {
        if(x == NULL && y == NULL) return;
        if((x == NULL && y!=NULL) || (y==NULL && x!=NULL))
        {
            fin = false;
            return;
        }
        if(x->val != y-> val)
        {
            fin = false;
            return;
        }
        symcheck(x->left,y->right,fin);
        symcheck(x->right,y->left,fin);
    }
    bool isSymmetric(TreeNode* root) {
        bool fin = true;
        symcheck(root->left,root->right,fin);
        return fin;
    }   
};