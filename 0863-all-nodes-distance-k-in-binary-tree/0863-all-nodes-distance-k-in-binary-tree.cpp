/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> t;
    int count = 0;
    void x(TreeNode* target,TreeNode* node,unordered_map<TreeNode*,TreeNode*> parent,int k,int t_k)
    {
        // if(node == NULL) return;
        if(k == t_k)
        {
            t.push_back(node);
            count++;
            return;
        }
        if(parent[node] && parent[node] != target) 
        {
            x(node,parent[node],parent,k+1,t_k);
        }
        if(node->left && node->left != target)
        {
            x(node,node->left,parent,k+1,t_k);
        }
        if(node->right && node->right != target)
        {
            x(node,node->right,parent,k+1,t_k);
        }        
    }
    void dfs(TreeNode* root,TreeNode* an,unordered_map<TreeNode*,TreeNode*>& parent)
    {   
        if(root == NULL) return;
        parent[root] = an;
        dfs(root->left,root,parent);
        dfs(root->right,root,parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        if(k == 0) return {target->val};
        dfs(root,NULL,parent);
        if(parent[target]) x(target,parent[target],parent,1,k);
        if(target->right) x(target,target->right,parent,1,k);
        if(target->left) x(target,target->left,parent,1,k);
        cout<<count<<endl;
        vector<int> result;
        for(TreeNode* node : t)
        {
            result.push_back(node->val);
            cout<<node->val<<" ";
        }
        return result;
    }
};