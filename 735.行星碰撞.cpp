/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        ans.push_back(asteroids[0]);

        for (int i = 1; i < asteroids.size(); ++i)
        {
            bool flag = true;
            while (!ans.empty() && flag && ans.back() > 0 && asteroids[i] < 0)
            {
                if (-asteroids[i] < ans.back())
                {
                    flag = false;
                }
                else if (-asteroids[i] > ans.back())
                {
                    ans.pop_back();
                }
                else if (-asteroids[i] == ans.back())
                {
                    ans.pop_back(); 
                    flag = false;
                }
            }
            if (flag)
                ans.emplace_back(asteroids[i]);
        }
        return ans;
    }
};
// @lc code=end
