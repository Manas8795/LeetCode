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
        TreeNode* x(int start,int end,vector<int>& p,vector<int>& in,int& index)
        {
            if(start > end) return NULL;
            TreeNode* node = new TreeNode();
            node->val = p[index++];
            int rpos = start;
            for(int i = start;i<=end;i++)
            {
                if(node->val == in[i])
                {
                    rpos = i;
                    break;
                }
            }
            int i = rpos;
            node->left = x(start,i-1,p,in,index);
            node->right = x(i+1,end,p,in,index);
            return node;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int index=0;
            return x(0,preorder.size()-1,preorder,inorder,index);
        }
    };