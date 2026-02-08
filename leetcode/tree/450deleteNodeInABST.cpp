// My Solution

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
    void deletNode(TreeNode* root, TreeNode* prev, int key){
        if(!root) return;
        if(root->val > key) deletNode(root->left, root, key);
        else if(root->val < key) deletNode(root->right, root, key);
        else{
            if(prev and root == prev->left){
                prev->left = root->right;
                TreeNode* prevSubstitute = root->right;
                TreeNode* substituteNode = root->right->left;
                while(substituteNode){
                    prevSubstitute = substituteNode;
                    substituteNode = substituteNode->left;
                }
                prevSubstitute->left = root->left;
                delete root;
            }
            else if(prev and root == prev->right){
                prev->right = root->left;
                TreeNode* prevSubstitute = root->left;
                TreeNode* substituteNode = root->left->right;
                while(substituteNode){
                    prevSubstitute = substituteNode;
                    substituteNode = substituteNode->right;
                }
                prevSubstitute->right = root->right;
                delete root;
            }
            else{
                if(!prev){
                    TreeNode* prevSubstitute = root->left;
                    TreeNode* substituteNode = root->left->right;
                    while(substituteNode){
                        prevSubstitute = substituteNode;
                        substituteNode = substituteNode->right;
                    }
                    prevSubstitute->right = root->right;
                    delete root;
                    return;
                }
                prev->left = root->left;
                prev->right = root->right;
                delete root;
            }
        }
        return;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(root->val == key and !root->left and !root->right) return nullptr;
        deletNode(root, nullptr, key);
        return root;
    }
};


// Best Solution

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            TreeNode* cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            root->val = cur->val;
            root->right = deleteNode(root->right, root->val);
        }

        return root;
    }
};