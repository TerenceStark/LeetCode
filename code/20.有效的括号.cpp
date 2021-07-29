/*
 * @lc app=leetcode.cn id=20 lang=cpp  

 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 == 1)
        {
            return false;
        }

        unordered_map<char, int> brackets{{'(', 1}, {'[', 2}, {'{', 3}, {')', 4}, {']', 5}, {'}', 6}};
        stack<char> st;

        for (char c : s)
        {
            int flag = brackets[c];
            if (flag >= 1 && flag <= 3)
            {
                st.push(c);
            }
            else if (!st.empty() && brackets[st.top()] == flag - 3)
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }
};
// @lc code=end
