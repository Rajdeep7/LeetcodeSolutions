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
    int sumNumbers(TreeNode* root) {
        int result = 0;
        int cur = 0;
        
        if(!root)
            return 0;
        helper(root, cur, result);    
        return result;
    }
    
    void helper(TreeNode* root, int cur, int &result) {
        if(!root->left && !root->right) {
             cur = cur*10 + root->val;
             result += cur;
        }
        else {
            cur = cur*10 + root->val;
            if(root->left) {
                helper(root->left, cur, result);
            }
            if(root->right) {
                helper(root->right, cur, result);
            }    
        }
    }
    
};
