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
    void dfs(TreeNode* root,TreeNode* an,unordered_map<TreeNode*,TreeNode*>& parent)
    {   
        if(root == NULL) return;
        parent[root] = an;
        dfs(root->left,root,parent);
        dfs(root->right,root,parent);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root] = NULL;
        dfs(root,NULL,parent);
        unordered_set<TreeNode*> ancestors;
        while (p != NULL) {
            ancestors.insert(p);
            p = parent[p];
        }
        while (q != NULL) {
            if (ancestors.find(q) != ancestors.end()) {
                return q;
            }
            q = parent[q];
        }
        return NULL;
    }
};