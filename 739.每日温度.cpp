/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        stack<int> stack;
        int index = 0;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i])
            {
                index =stack.top();
                ans[index] = i - index;
                stack.pop();
            }
            stack.push(i);
        }
        return ans;
    }
};
// @lc code=end
