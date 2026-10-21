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
    void inorder(TreeNode* root, vector<int>& in)
    {
        if(root == NULL ) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    void dfs(TreeNode* root,TreeNode*& p,TreeNode*& q,vector<int> & errors)
    {
        if(root == NULL) return;
        if(root->val == errors[0]) p = root;
        if(root->val == errors[1]) q = root;
        dfs(root->left,p,q,errors);
        dfs(root->right,p,q,errors);
    }
    void recoverTree(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        vector<int> sorted = in;
        sort(sorted.begin(),sorted.end());
        vector<int> errors;
        for(int i = 0;i<in.size();i++)
        {
            if(sorted[i] != in[i]) errors.push_back(in[i]);
            // cout<<in[i]<<":"<<sorted[i]<<endl;
        }
        TreeNode* p = new TreeNode();
        TreeNode* q = new TreeNode();
        dfs(root,p,q,errors);
        if(p && q) swap(p->val , q->val);
    }
};