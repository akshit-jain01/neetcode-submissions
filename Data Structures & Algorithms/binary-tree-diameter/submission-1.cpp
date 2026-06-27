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
    int ans = 0;
    int maxdepth(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);

        ans = max(ans, left+right);

        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root);
        return ans;
    }
};
