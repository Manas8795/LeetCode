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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0){
            return nullptr;
        }
        return bst(preorder, INT_MAX);
    }
    int i = 0;
    TreeNode *bst(vector<int> &preorder, int range){
        if(i >= preorder.size() || preorder[i] > range){
            return nullptr;
        }
        TreeNode *node = new TreeNode(preorder[i]);
        i++;

        node->left = bst(preorder, node->val);
        node->right = bst(preorder, range);

        return node;
    }
};