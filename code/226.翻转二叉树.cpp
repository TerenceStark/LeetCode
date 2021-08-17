/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return nullptr;
        }

        queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            TreeNode *temp = queue.front();
            queue.pop();
            TreeNode *left = temp->left;
            temp->left = temp->right;
            temp->right = left;

            if (temp->left)
            {
                queue.push(temp->left);
            }

            if (temp->right)
            {
                queue.push(temp->right);
            }
        }

        return root;
    }
};

/* 
recursion
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return nullptr;
        }

        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
}; 
*/
// @lc code=end
