/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> stack;
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < nums.size() * 2 - 1; i++)
        {
            while (!stack.empty() && nums[stack.top()] < nums[i % n])
            {
                ans[stack.top()] = nums[i % n];
                stack.pop();
            }
            stack.push(i % n);
        }
        return ans;
    }
};
// @lc code=end
