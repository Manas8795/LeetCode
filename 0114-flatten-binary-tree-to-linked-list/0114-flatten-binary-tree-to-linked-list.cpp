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
    void preorder(TreeNode* root,vector<TreeNode*>& x)
    {
        if(!root) return;
        x.push_back(root);
        preorder(root->left,x);
        preorder(root->right,x);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> x;
        preorder(root,x);
        root = x[0];
        for(TreeNode* k : x)
        {
            if(root == k)continue;
            root->right = k;
            root->left = NULL;
            root = root->right;
        }
    }
};