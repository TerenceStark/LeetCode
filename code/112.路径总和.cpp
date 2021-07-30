/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
//BFS Time:O(n) Space:O(Height)
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }

        queue<TreeNode *> nodeQueue;
        queue<int> valQueue;
        nodeQueue.push(root);
        valQueue.push(root->val);

        while (!nodeQueue.empty())
        {
            TreeNode *cur = nodeQueue.front();
            int temp = valQueue.front();
            nodeQueue.pop();
            valQueue.pop();
            if (!cur->left && !cur->right)
            {
                if (temp == targetSum)
                {
                    return true;
                }
                continue;
            }

            if (cur->left)
            {
                nodeQueue.push(cur->left);
                valQueue.push(cur->left->val + temp);
            }

            if (cur->right)
            {
                nodeQueue.push(cur->right);
                valQueue.push(cur->right->val + temp);
            }
        }

        return false;
    }
};

/* 
recursion Time:O(n) Space:O(Height)
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }

        if (!root->left && !root->right)
        {
            return targetSum == root->val;
        }

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
}; 
*/
// @lc code=end
