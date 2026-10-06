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
int x = 1;
bool fin = true;
    void height(TreeNode* root,int h)
    {
        if(root == NULL) return;
        x = max(x,h);
        height(root->left,h+1);
        height(root->right,h+1);
    }
    void check(TreeNode* root)
    {
        if(root == NULL) return;
        int a = 0;
        if(root->left!=NULL)
        {
            x = 0;
            height(root->left,1);
            a = x;
        }
        int b = 0;
        if(root->right!=NULL)
        {
            x = 0;
            height(root->right,1);
            b = x;
        }
        if(abs(a-b)>1) fin = false;
    }
    void repeat(TreeNode* root)
    {
        if(root == NULL) return;
        check(root);
        repeat(root->left);
        repeat(root->right);
    }
    bool isBalanced(TreeNode* root) {
        fin = true;
        x = 1;
        repeat(root);
        cout<<x;
        return fin;
    }
};