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
   bool minmax(TreeNode* root, long max, long min){
        if (!root){return true;}
        
        if (root->val>=max || root->val <=min){
            return false;
        }else{
            return minmax(root->left,root->val,min) && minmax(root->right, max, root->val);
        }
    }
 
    bool isValidBST(TreeNode *root) {
        if (!root){return true;}
        return minmax(root,LONG_MAX,LONG_MIN);
    }
};
