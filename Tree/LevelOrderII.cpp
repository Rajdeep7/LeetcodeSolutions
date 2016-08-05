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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> p;
        if(!root)
            return res;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        TreeNode* tmp;
        while(1) {
            while(!q1.empty()) {
                tmp = q1.front();
                q1.pop();
                if(tmp->left)
                    q2.push(tmp->left);
                if(tmp->right)
                    q2.push(tmp->right);
                p.push_back(tmp->val);
            }
            res.push_back(p);
            p.clear();
            q1 = q2;
            if(q1.empty())
                break;
            while(!q2.empty()) {
                q2.pop();
            }
        }
        vector<vector<int>> revRes;
        for(int i = res.size()-1; i >= 0; i--) {
            revRes.push_back(res[i]);
        }
        
        return revRes;
        //return res;
    }
};
