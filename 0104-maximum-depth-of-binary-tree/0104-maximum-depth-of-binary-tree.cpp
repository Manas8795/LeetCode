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
int count = 0;
    void x(TreeNode* root , int c)
    {
        
        if(root == NULL) return;
        count = max(count,c);
        x(root->left , c+1);
        x(root->right, c+1);
    }
    int maxDepth(TreeNode* root) {
        x(root,1);
        return count;
    }
};