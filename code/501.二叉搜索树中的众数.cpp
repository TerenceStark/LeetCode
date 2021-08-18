/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int base, count, max;
    vector<int> ans;

    vector<int> findMode(TreeNode *root)
    {
        TreeNode *pre;
        while (root)
        {
            if (root->left)
            {
                pre = root->left;
                while (pre->right && pre->right != root)
                {
                    pre = pre->right;
                }
                if (!pre->right)
                {
                    pre->right = root;
                    root = root->left;
                }
                else
                {
                    update(root->val);
                    root = root->right;
                    pre->right = nullptr;
                }
            }
            else
            {
                update(root->val);
                root = root->right;
            }
        }
        return ans;
    }

    void update(int val)
    {
        if (val == base)
        {
            count++;
        }
        else
        {
            base = val;
            count = 1;
        }
        if (count == max)
        {
            ans.push_back(base);
        }
        else if (count > max)
        {
            max = count;
            ans = vector<int> {base};
        }
    }
};
// @lc code=end
