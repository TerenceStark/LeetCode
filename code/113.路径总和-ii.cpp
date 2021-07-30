/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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

//BFS Time:O(n^2) Space:O(n)
class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> tree;
    vector<vector<int>> ans;

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return ans;
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
                    getPath(cur);
                }
                continue;
            }

            if (cur->left)
            {
                tree[cur->left] = cur;
                nodeQueue.push(cur->left);
                valQueue.push(cur->left->val + temp);
            }

            if (cur->right)
            {
                tree[cur->right] = cur;
                nodeQueue.push(cur->right);
                valQueue.push(cur->right->val + temp);
            }
        }
        return ans;
    }

    void getPath(TreeNode *node)
    {
        vector<int> temp;
        while (node)
        {
            temp.push_back(node->val);
            node = tree[node];
        }
        reverse(temp.begin(), temp.end());
        ans.push_back(temp);
    }
};

/* 
backtracking
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;  
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};
 */

/* DFS Time:O(n^2) Space:O(n)
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum);
        return ans;
    }

    void dfs(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return;
        }

        path.push_back(root->val);
        targetSum -= root->val;
        if (!root->left && !root->right && targetSum == 0)
        {
            ans.push_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }
}; */
// @lc code=end
