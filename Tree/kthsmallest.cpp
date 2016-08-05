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
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return NULL;
        vector<int> v;
        stack<TreeNode*> s;
        //int count = 0;
        
        while(1) {
            while(root) {
                s.push(root);
                root = root->left;
                //count++;
            }
            if(s.empty())
                break;
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
        return(v[k-1]);
    }
};
