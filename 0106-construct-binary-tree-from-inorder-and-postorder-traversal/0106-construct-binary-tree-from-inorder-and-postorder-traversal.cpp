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
    TreeNode* x(vector<int> &in,vector<int> &post,int& index,int start,int end)
    {
        if(start>end) return NULL;
        TreeNode* node = new TreeNode();
        node->val = post[post.size()-1-index++];
        int rpos = start;
        for(int i = start;i<=end;i++)
        {
            if(node->val == in[i])
            {
                rpos = i;
                break;
            }
        }
        node->right = x(in,post,index,rpos+1,end);
        node->left = x(in,post,index,start,rpos-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = 0;
        return x(inorder,postorder,index,0,postorder.size()-1);
    }
};