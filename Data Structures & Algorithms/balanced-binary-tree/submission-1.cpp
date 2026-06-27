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
    int depth(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);

        return 1 + max(left, right);
    }
    bool bal(TreeNode* root)
    {
        if(root == nullptr)
        {
            return true;
        }
        if(!bal(root->left)) return false;
        if(!bal(root->right)) return false;
        int left = depth(root->left);
        int right = depth(root->right);

        if(abs(left-right)>1)
        {
            return false;
        }

        return true;
    }
    bool isBalanced(TreeNode* root) {
        return bal(root);
    }
};
