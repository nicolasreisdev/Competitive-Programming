/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void search(TreeNode* root, int &k, int &level, TreeNode* ans){
        if(!root or ans->val >= 0)return;
        search(root->left, k, level, ans);
        level++;
        if(level == k){
            ans->val = root->val;
            return;
        }
        search(root->right, k, level, ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans = new TreeNode(-1);
        int level = 0;
        search(root, k, level, ans);
        return ans->val;
    }
};