/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode *root)
    {
        return helper(root, root);
    }

    bool helper(TreeNode *a, TreeNode *b)
    {
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(a);
        nodeQueue.push(b);

        while (!nodeQueue.empty())
        {
            TreeNode *node1 = nodeQueue.front();
            nodeQueue.pop();
            TreeNode *node2 = nodeQueue.front();
            nodeQueue.pop();

            if (!node1 && !node2)
            {
                continue;
            }

            if ((!node1 || !node2) || (node1->val != node2->val))
            {
                return false;
            }

            nodeQueue.push(node1->left);
            nodeQueue.push(node2->right);
            nodeQueue.push(node1->right);
            nodeQueue.push(node2->left);
        }
        return true;
    }
};

/* class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return helper(root, root);
    }

    bool helper(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
        {
            return true;
        }
        if (!a || !b)
        {
            return false;   
        }
        return a->val == b->val && helper(a->left, b->right) && helper(a->right, b->left);
    }
}; */
// @lc code=end
