class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        long long maxi = 1;
        long long first = 0,last = 0;
        while(!q.empty())
        {
            int n = q.size();
            long long min_index = q.front().second;
            for(int i = 0;i<n;i++)
            {
                pair<TreeNode*,long long> node = q.front();
                q.pop();
                long long curr_index = node.second - min_index;
                if(i == 0) first = curr_index;
                if(i == n - 1) last = curr_index;
                if(node.first->left) q.push({node.first->left,2*curr_index});
                if(node.first->right) q.push({node.first->right,2*curr_index+1});
            }
            maxi = max(maxi,last-first+1);
        }
        return maxi;
    }
};