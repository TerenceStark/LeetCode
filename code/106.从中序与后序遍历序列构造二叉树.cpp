/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> index;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int size = inorder.size();
        for (int i = 0; i < size; i++)
        {
            index[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, size - 1, 0, size - 1);
    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int in_left, int in_right, int post_left, int post_right)
    {
        if (post_left > post_right)
        {
            return nullptr;
        }

        int post_root = post_right;
        int in_root = index[postorder[post_root]];
        TreeNode *root = new TreeNode(postorder[post_root]);
        int leftSize = in_root - in_left;

        root->left = build(inorder, postorder, in_left, in_root - 1, post_left, post_left + leftSize - 1);
        root->right = build(inorder, postorder, in_root + 1, in_right, post_left + leftSize, post_right - 1);
        return root;
    }
};
// @lc code=end
