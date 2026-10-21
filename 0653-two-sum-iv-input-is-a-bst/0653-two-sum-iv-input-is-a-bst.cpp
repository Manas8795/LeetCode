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
    void inorder(TreeNode* root,vector<int>& in)
    {
        if(root == NULL) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    bool findTarget(TreeNode* root, int target) 
    {
        vector<int> nums;
        inorder(root,nums);
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) 
        {
            int x = target - nums[i];
            if (mp.find(x) != mp.end() && mp[x] != i) {
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};