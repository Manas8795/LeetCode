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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> fin;
        queue<TreeNode*> q;
        if(root == NULL ) return {};
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> x(n);
            for(int i = 0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                int index = i;
                x[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            fin.push_back(x);
        }
        vector<int> result;
        for(vector<int> k:fin)
        {
            result.push_back(k[k.size()-1]);
        }
        return result;
    }
};