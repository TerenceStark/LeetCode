/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int depth = 0;
        TreeNode *node = root;
        while (node->left)
        {
            depth++;
            node = node->left;
        }

        int low = 1 << depth;
        int high = (1 << (depth + 1)) - 1;
        int mid;
        while (low < high)
        {
            mid = (low + high + 1) / 2;
            if (exsit(root, depth, mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }

    bool exsit(TreeNode *root, int depth, int index)
    {
        int bit = 1 << (depth - 1);
        TreeNode *temp = root;

        while (temp && bit > 0)
        {
            if (bit & index)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
            bit >>= 1;
        }
        return temp != nullptr;
    } // eg: 010 & 110 = 010 move right, 001 & 110 = 000  move left
};
// @lc code=end