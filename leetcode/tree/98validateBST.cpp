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
private:
    long long maxVal = 1LL << 32;
    bool search(TreeNode* root, long long minVal, long long maxVal){
        if(!root) return true;
        if(minVal >= root->val or maxVal <= root->val)return false;
        return search(root->left, minVal, root->val) && search(root->right, root->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return search(root, -maxVal, maxVal);
    }
};