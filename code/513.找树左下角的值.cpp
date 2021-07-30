/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int ans;
    int maxHeight;

    int findBottomLeftValue(TreeNode *root)
    {

        dfs(root, 1);
        return ans;
    }

    void dfs(TreeNode *cur, int height)
    {

        if (!cur->left && !cur->right && height > maxHeight)
        {

            maxHeight = height;
            ans = cur->val;
            return;
        }

        if (cur->left)
        {
            dfs(cur->left,height+1);
        }

        if (cur->right)
        {
            dfs(cur->right,height+1);
        }
        
    }
};
// @lc code=end
