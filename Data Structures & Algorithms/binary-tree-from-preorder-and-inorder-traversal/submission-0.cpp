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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;

        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int preorderIndex = 0;

        function<TreeNode*(int, int)> build = [&](int left, int right) -> TreeNode* {
            if (left > right) {
                return nullptr;
            }

            int rootValue = preorder[preorderIndex];
            preorderIndex++;

            TreeNode* root = new TreeNode(rootValue);
            int mid = inorderIndex[rootValue];

            root->left = build(left, mid - 1);
            root->right = build(mid + 1, right);

            return root;
        };

        return build(0, inorder.size() - 1);
    }
};
