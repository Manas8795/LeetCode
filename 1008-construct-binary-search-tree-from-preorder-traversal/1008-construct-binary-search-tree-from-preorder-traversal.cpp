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
    TreeNode* x(int &index,int i,int j,vector<int> inorder,vector<int> preorder)
    {
    
        if(i>j) return NULL;
        int rval = preorder[index++];
        TreeNode* node = new TreeNode();
        node->val = rval;
        int rpos = -1;
        for(int p = i;p<=j;p++)
        {
            if(inorder[p] == rval) 
            {
                rpos = p;
                break;
            }
        }
        node->left = x(index,i,rpos-1,inorder,preorder);
        node->right = x(index,rpos+1,j,inorder,preorder);
        return node;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;
        vector<int> in = preorder;
        sort(in.begin(),in.end());
        int rval = preorder[0];
        for(int i = 0;i<preorder.size();i++)
        {
            if(rval == in[i])
            {
                rval = i;
                break;
            }
        }
        int i = 1;
        TreeNode* root = new TreeNode();
        root->val = preorder[0];
        root->left = x(i,0,rval-1,in,preorder);
        root->right = x(i,rval+1,preorder.size()-1,in,preorder);
        return root;
    }
};