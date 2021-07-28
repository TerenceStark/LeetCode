/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> stack;
        int size = pushed.size();
        int j = 0;

        for (int i = 0; i < size; i++)
        {
            stack.push(pushed[i]);
            while (!stack.empty() && stack.top() == popped[j])
            {
                stack.pop();
                j++;
            }
        }
        return stack.empty();
    }
};
// @lc code=end
