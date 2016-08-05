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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        deque<TreeNode*> q1, q2;
        vector<int> level;
        level.push_back(root->val);
        res.push_back(level);
        level.clear();
        q1.push_back(root);
        TreeNode* tmp;
        bool flag = false;
        while(1) {
            while(!q1.empty()) {
                tmp = q1.front();
                q1.pop_front();
                if(tmp->left)
                    q2.push_back(tmp->left);
                if(tmp->right)
                    q2.push_back(tmp->right);
            }
            q1 = q2;
            if(q2.empty())
                return res;
            while(!q2.empty()) {
                if(flag) {
                    level.push_back(q2.front()->val);
                    q2.pop_front();
                }
                else {
                    level.push_back(q2.back()->val);
                    q2.pop_back();
                }
            }
            flag = !flag;
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};
