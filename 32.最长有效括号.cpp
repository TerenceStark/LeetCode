/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stack;
        stack.push(-1);
        int maxans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stack.push(i);
            }
            else
            {
                stack.pop();
                if (stack.empty())
                {
                    stack.push(i);
                }
                else
                {
                    maxans = max(maxans, i - stack.top());
                }
            }
        }
        return maxans;
    }
};
// @lc code=end
