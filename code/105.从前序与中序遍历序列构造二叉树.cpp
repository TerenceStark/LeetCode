/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int size = inorder.size();
        for (int i = 0; i < size; i++)
        {
            index[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, size - 1, 0, size - 1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pre_left, int pre_right, int in_left, int in_right)
    {
        if (pre_left > pre_right)
        {
            return nullptr;
        }

        int pre_root = pre_left;
        int in_root = index[preorder[pre_root]];
        TreeNode *root = new TreeNode(preorder[pre_root]);
        int leftSize = in_root - in_left;

        root->left = build(preorder, inorder, pre_left + 1, pre_left + leftSize, in_left, in_root - 1);
        root->right = build(preorder, inorder, pre_left + leftSize + 1, pre_right, in_root + 1, in_right);
        return root;
    }
};
// @lc code=end