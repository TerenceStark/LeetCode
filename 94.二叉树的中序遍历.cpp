/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

//morris
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *predecessor;

        while (root)
        {
            if (root->left) //root->left!=nullptr
            {
                predecessor = root->left;
                while (predecessor->right && predecessor->right != root)
                {
                    predecessor = predecessor->right; //find predecessor
                }

                if (!predecessor->right) //predecessor->right==nullptr
                {
                    predecessor->right = root;
                    root = root->left;
                }

                else
                {
                    ans.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }

            else //root->left==nullptr
            {
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};

/*
using iteration
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> stack;

        while (root || !stack.empty())
        {
            while (root)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
}; */

/*  
using recursion
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

    void inorder(TreeNode *Tnode, vector<int> &ans)
    {
        if (!Tnode)
        {
            return;
        }
        inorder(Tnode->left, ans);
        ans.push_back(Tnode->val);
        inorder(Tnode->right, ans);
    }
}; 
*/

// @lc code=end
