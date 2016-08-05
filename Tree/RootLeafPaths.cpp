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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        helper(root, "", path);
        
        return path;
    }
    
    void helper(TreeNode* root, string s, vector<string> &path) {
        if(!root)
            return;
        
        if(!root->left && !root->right) {
            path.push_back(s + to_string(root->val));
            return;
        }
        
        string head = s + to_string(root->val) + "->";
          
        helper(root->left, head, path);
        helper(root->right, head, path);

        return;
    }
};
