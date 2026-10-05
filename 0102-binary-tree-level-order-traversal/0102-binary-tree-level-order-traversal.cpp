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
vector<pair<int,int>> x;
    void t1(int l,TreeNode* root)
    {
        if(root == NULL) return;
        x.push_back({root->val,l});
        t1(l+1,root->left);
        t1(l+1,root->right);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
       t1(1,root);
       int maxi = 0;
       for(pair<int,int> k : x)
       {
        maxi = max(maxi,k.second);
        cout<<k.first<<" "<<k.second<<endl;
       }
       vector<vector<int>> m(maxi);
       for(pair<int,int> k : x)
       {
        m[k.second-1].push_back(k.first);
        cout<<k.first<<" "<<k.second<<endl;
       }
       return m;
    }
};