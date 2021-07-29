/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        string ans = "";

        if (num == 0)
        {
            return "0";
        }

        if (num < 0)
        {
            return "-" + convert(-num, ans);
        }
        return convert(num, ans);
    }

    string convert(int num, string ans)
    {
        while (num > 0)
        {
            int reminder = num % 7;
            ans += reminder + '0';
            num /= 7;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
