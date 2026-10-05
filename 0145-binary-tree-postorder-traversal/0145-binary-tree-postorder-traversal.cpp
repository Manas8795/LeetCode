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
    void tr(vector<int>& a,TreeNode* root)
    {
        if(root == NULL) return;
        tr(a,root->left);
        tr(a,root->right);
        a.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> a;
        tr(a,root);
        return a;
    }
};