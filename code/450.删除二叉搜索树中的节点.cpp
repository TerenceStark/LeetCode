/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
        {
            return nullptr;
        }

        if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }

        else
        {
            if (!root->left)
            {
                return root->right;
            }
            if (!root->right)
            {
                return root->left;
            }

            TreeNode *node = root->right;
            while (node->left)
            {
                node = node->left;
            }
            node->left = root->left;
            root = root->right;
        }
        return root;    
    }
};
// @lc code=end
/* 
如果目标节点大于当前节点值，则去右子树中删除；
如果目标节点小于当前节点值，则去左子树中删除；
如果目标节点就是当前节点，分为以下三种情况：
  其无左子：其右子顶替其位置，删除了该节点；
  其无右子：其左子顶替其位置，删除了该节点；
  其左右子节点都有：其左子树转移到其右子树的最左节点的左子树上，然后右子树顶替其位置，由此删除了该节点。
*/