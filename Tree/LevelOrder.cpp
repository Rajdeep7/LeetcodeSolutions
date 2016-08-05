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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q1, q2;
        
        if(root!=NULL) {
            q1.push(root);
            vector<int> b;
            TreeNode *temp;
            while(1) {
                while(!q1.empty()) {
                    temp = q1.front();
                    q1.pop();
                    if(temp->left)
                        q2.push(temp->left);
                    if(temp->right)
                        q2.push(temp->right);
                    b.push_back(temp->val);
                }
                result.push_back(b);
                b.clear();
                q1 = q2;
                while(!q2.empty()) {
                    q2.pop();
                }
                if(q1.empty())
                    return result;
            }
        }
        return result;
    }
};
