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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root == p or root == q) return root;
        else if(root->val < p->val and root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if(root->val > p->val and root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if(root->val <= p->val and root->val >= q->val) {
            return root;
        } else if(root->val <= q->val and root->val >= p->val) {
            return root;
        }
        return root;
    }
};