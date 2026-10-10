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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> col;
        queue<pair<TreeNode*,pair<int,int>>> q;
        if(!root) return{{}};
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto[node,rowcol] = q.front();
            q.pop();
            auto[r,c] = rowcol;
            col[c].push_back({r,node->val});
            if(node->left) q.push({node->left,{r+1,c-1}});
            if(node->right) q.push({node->right,{r+1,c+1}});
        }
        vector<vector<int>> fin;
        for(auto& [key,value] : col)
        {
            sort(value.begin(),value.end(),
                [](const pair<int,int>&a,const pair<int,int>&b)
                {
                    if(a.first == b.first) return a.second < b.second;
                    return a.first < b.first;
                }
            );
            vector<int> sorted;
            for(pair<int,int> k:value)
            {
                sorted.push_back(k.second);
            }
            fin.push_back(sorted);
        }

        return fin;
    }
};