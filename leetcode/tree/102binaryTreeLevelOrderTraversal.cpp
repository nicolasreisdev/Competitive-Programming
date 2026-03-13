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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        priority_queue<pair<int, TreeNode*>, vector<pair<int, TreeNode*>>, greater<pair<int, TreeNode*>>> pq;
        pq.push({0, root});
        while(!pq.empty()){
            int level = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            if(!node) continue;
            if(level == ans.size()){
                vector<int> nodes;
                nodes.push_back(node->val);
                ans.push_back(nodes);
            }
            else ans[level].push_back(node->val);
            pq.push({level+1, node->left});
            pq.push({level+1, node->right});
        }
        return ans;
    }
};