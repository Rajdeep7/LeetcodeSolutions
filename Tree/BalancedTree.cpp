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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return 1;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
            return 1;
            
        return 0;
    }
    int height(TreeNode* root) {
        if(!root)
            return 0;

        return(max(height(root->left), (height(root->right))) + 1);
    }
};
