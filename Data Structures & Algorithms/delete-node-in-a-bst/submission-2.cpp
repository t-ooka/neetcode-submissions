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
        if (!root) {
            return NULL;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) {
                return root->right;
            } else if (!root->right) {
                return root->left;
            } else {
                TreeNode* min_value_node = findMinValueNode(root->right);
                root->val = min_value_node->val;
                root->right = deleteNode(root->right, min_value_node->val);
            }
        }
        return root;
    }

    TreeNode* findMinValueNode(TreeNode* root) {
        TreeNode* current_node = root;
        while (current_node && current_node->left) {
            current_node = current_node->left;
        }
        return current_node;
    }
};
