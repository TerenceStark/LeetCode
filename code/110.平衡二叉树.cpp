/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
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

//bottom up
//time O(n)
//space O(n)
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) >= 0;
    }

    int height(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }
        else
        {
            return max(leftHeight, rightHeight) + 1;
        }
    }
};

/* 
Top down
time O(n^2)
space O(n)
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return max(height(root->left), height(root->right)) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
}; 
*/
// @lc code=end
