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
vector<int> a;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root)
            helper(root);
        
        return a;
    }
    
    void helper(TreeNode* p) {
        if(p->left)
            helper(p->left);
            
        if(p->right)
            helper(p->right);
            
        a.push_back(p->val);
    }
};
