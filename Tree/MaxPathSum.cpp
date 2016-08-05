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
    
    int helper(TreeNode* root, int &result) {
        if(!root)
            return 0;
        else {
            int left = helper(root->left, result);
            int right = helper(root->right, result);
            
            int max_single = max(max(left+root->val, right+root->val), root->val);
            result = max(result, max(max_single, left+root->val+right));
            
            return max_single;
        }
    }
    
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        int mx = helper(root, result);
        return result;
    }
};
