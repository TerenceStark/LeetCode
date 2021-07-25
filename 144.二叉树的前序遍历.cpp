/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> stack;

        while (root || !stack.empty())
        {
            while (root)
            {
                stack.push(root);
                ans.push_back(root->val);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            root = root->right;
        }
        return ans;
    }
}; 


/* 
using recursion:
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }

    void preorder(TreeNode *Tnode, vector<int> &ans)
    {
        if (!Tnode)
        {
            return;
        }

        ans.push_back(Tnode->val);
        preorder(Tnode->left, ans);
        preorder(Tnode->right, ans);
    }
}; 
*/

// @lc code=end
