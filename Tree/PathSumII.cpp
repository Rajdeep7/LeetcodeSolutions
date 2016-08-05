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
    void helper(TreeNode *root, int sum, vector<int> path, vector<vector<int>> &result) {
        if(!root)
            return;
        else {
            path.push_back(root->val);
            if(sum==root->val && !root->left && !root->right) {
                result.push_back(path);
                path.clear();
            }
                helper(root->left, sum-root->val, path, result);
                helper(root->right, sum-root->val, path, result);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        helper(root, sum, path, result);
        return result;
    }
};
