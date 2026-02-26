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
    void dfs(TreeNode* p, TreeNode* q, bool &flag){
        if(!p and !q) return;
        if(!p or !q or p->val != q->val){
            flag = false;
            return;
        }
        dfs(p->right, q->right, flag);
        dfs(p->left, q->left, flag);
    }
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        dfs(p, q, ans);
        return ans;
    }
};