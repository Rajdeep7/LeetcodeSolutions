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
   TreeNode* sortedArrayToBST(vector<int> &a) {
        if(a.size()==0)
            return NULL;
        return helper(a, 0, a.size()-1);
    }
    
    TreeNode* helper(vector<int> &a, int st, int ed) {
        if(st>ed)
            return NULL;
        else {
            int mid = st+(ed-st)/2;
            TreeNode *node = new TreeNode(a[mid]);
            node->left = helper(a, st, mid-1);
            node->right = helper(a, mid+1, ed);
            return node;
        }
    }
};
