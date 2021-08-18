/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *pre;

        while (root)
        {
            if (root->right)
            {
                pre = root->right;
                while (pre->left && pre->left != root)
                {
                    pre = pre->left;
                }
                if (!pre->left)
                {
                     ans.push_back(root->val);
                    pre->left = root;
                    root = root->right;
                }
                else
                {
                    pre->left = nullptr;
                    root = root->left;
                }
            }

            else
            {
                ans.push_back(root->val);
                root = root->left;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/* 
itereation
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> stack;
        TreeNode *pre = nullptr;

        while (root || !stack.empty())
        {
            while (root)
            {
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();
            if (!root->right || root->right == pre) //TreeNode pre used representing right child has been visited
            {
                ans.push_back(root->val);
                pre = root;
                root = nullptr;
            }
            else
            {
                stack.push(root);
                root = root->right;
            }
        }
        return ans;
    }
}; 
*/

/* 
using recursion:
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }

    void postorder(TreeNode *Tnode, vector<int> &ans)
    {
        if (!Tnode)
        {
            return;
        }

        postorder(Tnode->left, ans);
        postorder(Tnode->right, ans);
        ans.push_back(Tnode->val);
    }
}; 
*/
// @lc code=end
