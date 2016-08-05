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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> p, q;
        
        if(root) {
            p.push(root);
            TreeNode *temp;
            while(1) {
                while(!p.empty()) {
                    temp = p.front();
                    p.pop();
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }
                result.push_back(temp->val);
                p = q;
                while(!q.empty()) {
                    q.pop();
                }
                if(p.empty())
                    return result;
            }
        }
        return result;
    }
};
