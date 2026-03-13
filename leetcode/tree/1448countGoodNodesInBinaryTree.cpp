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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        queue<pair<int, TreeNode*>> pq;
        pq.push({root->val, root});
        while(!pq.empty()){
            int maxValuePath = pq.front().first;
            auto node = pq.front().second;
            pq.pop();
            if(!node)continue;
            if(node->val >= maxValuePath) ans++;
            pq.push({max(maxValuePath, node->val), node->left});
            pq.push({max(maxValuePath, node->val), node->right});
        }
        return ans;
    }
};