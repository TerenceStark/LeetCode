/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *node = root;
        while (node)
        {
            if (node->val > p->val && node->val > q->val)
            {
                node = node->left;
            }
            else if (node->val < p->val && node->val < q->val)
            {
                node = node->right;
            }
            else
            {
                break;
            }
        }
        return node;
    }
};
// @lc code=end
