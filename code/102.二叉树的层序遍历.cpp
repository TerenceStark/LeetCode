/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> nodeQueue;
        int size = 0;
        if (!root)
        {
            return ans;
        }

        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            size = nodeQueue.size();
            ans.push_back(vector<int>());
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = nodeQueue.front();
                nodeQueue.pop();
                ans.back().push_back(temp->val);
                if (temp->left)
                {
                    nodeQueue.push(temp->left);
                }
                if (temp->right)
                {
                    nodeQueue.push(temp->right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
